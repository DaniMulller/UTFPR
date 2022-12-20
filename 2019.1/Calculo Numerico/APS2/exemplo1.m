clear
clc
% ESCALONAMENTO

n=5;

% MATRIZ A
for i=1:n
  for j=1:n
    A(i,j) = 1/(i+j-1);
  endfor
endfor

% MATRIZ B
for i=1:n
   B(i,1)=1/i;
endfor

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







