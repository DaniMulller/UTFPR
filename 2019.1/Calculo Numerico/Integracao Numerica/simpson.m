clc
clear

%REGRA DE SIMPSON%

f=@(x) e^x;
tol=0.00001;
n=100; %Numero e Divisoes do Intervalo
xi=1; %INTERVALO A 
xf=2; %INTERVALO B
h=(xf-xi)/n
soma=0;

%------------Definindo os X(i)-----------------
for i=1:n+1
   x(i)=xi+(i-1)*h; 
endfor

%---------------SEM TOLERANCIA----------------
for i=1:n/2
  soma += f(x(2*i-1))+4*f(x(2*i))+f(x(2*i+1));
endfor

%------------------ERRO-----------------------
y1=((xi+xf)/2)-((xf-xi)/(2*sqrt(3)));
y2=((xi+xf)/2)+((xf-xi)/(2*sqrt(3)));
erro = ((xf-xi)/2)*(f(y1)+f(y2))

%---------------COM TOLERANCIA----------------
#i=1;
#while abs(soma-erro)>tol
#  soma += f(x(2*i-1))+4*f(x(2*i))+f(x(2*i+1));
#  i++;
#endwhile
#numero_de_partes = i
 
INTEGRAL = (h/3)*soma
  

