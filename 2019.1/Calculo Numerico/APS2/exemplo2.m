clear
clc
% ESCALONAMENTO
n=5;

% MATRIZ A
A(1,1)=-2.02;
A(1,2)=1;
A(n,n)=-2.02;
A(n,n-1)=1;
for i=2:n-1;
  for j=i-1:i+1
    if(i==j)
      A(i,j)=-2.02;
    else
      A(i,j)=1;
    endif
   endfor
endfor

% MATRIZ B
B(1)=1;
for i=2;n-1
  B(i)=0;
endfor
B(n)=1;

A
B

% ESCALONAR MATRIZ
for k=1:n-1
  for i=k+1:n
    M(i,k)=A(i,k)/A(k,k);
    A(i,k)=0;
    for j=k+1:n
      A(i,j) = A(i,j) - M(i,k)*A(k,j);
    endfor
    B(i) = B(i) - M(i,k)*B(k);
  endfor
endfor

disp('MATRIZ ESCALONADA')
A
B

% MATRIZ X
for i=n:-1:1
  S = 0;
  for j=i+1:n
    S = S + A(i,j)*X(j);
  endfor
  X(i,1) = (B(i)-S)/A(i,i);
endfor

disp('MATRIZ SOLUCAO')
X