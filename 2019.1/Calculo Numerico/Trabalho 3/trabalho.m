clc
clear all

f=@(x,y) x; #FUNCAO PARA APROXIMAR
L=pi;
n=4;   #NUMERO DE FUNCOES G(x)
m=100; #PARTES DA INTEGRAL

xi=-L;
xf=L;
h=(xf-xi)/m;

#DEFININDO OS X(i) 
X(1)=xi;
for i=1:m
  X(i+1)=X(1)+i*h;
endfor

#PARTE DO COSSENO
for i=1:n+1
  for j=1:m+1
   G(i,j)=cos(((i-1)*pi*X(j))/L);
  endfor
endfor

#PARTE DO SENO
for i=1:n
  for j=1:m+1
   #i+n+1 => metade pra frente 
   G(i+n+1,j)=sin((i*pi*X(j))/L);
  endfor
endfor

#INTEGRANDO A PRIMEIRA PARTE PELA REGRA DOS TRAPEZIOS (Matriz A)
for i=1:2*n+1
  for j=1:2*n+1
    A(i,j) = ((G(i,1)*G(j,1))+(G(i,m+1)*G(j,m+1)))/2;
    for k=2:m
      A(i,j) += G(i,k)*G(j,k);
    endfor
    A(i,j) *= h;
  endfor
endfor

#INTEGRANDO A SEGUNDA PARTE PELA REGRA DOS TRAPEZIOS (Vetor B)
for i=1:2*n+1
  B(i) = ((f(X(1))*G(i,1))+(f(X(m+1))*G(i,m+1)))/2;
  for j=2:m
    B(i) += G(i,j)*f(X(j));
  endfor
  B(i) *= h;
endfor

#MOSTRANDO AS MATRIZES A e B
A
B

#RESOLVENDO O SISTEMA LINEAR
C = A\B'
for i=1:m+1
  y(i)=0;
  for j=1:2*n+1
    y(i) += C(j)*G(j,i);
  endfor
endfor

#PLOTANDO O GRAFICO
plot(X,f(X),'b',X,y,'r');