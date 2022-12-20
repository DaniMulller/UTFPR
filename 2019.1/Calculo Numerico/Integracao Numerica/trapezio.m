clc
clear

%REGRA DOS TRAPEZIOS%
f=@(x) e^x;
n=4;
xi=1;
xf=2;
h=(xf-xi)/n
soma=0;

for i=1:n+1
  x(i) = xi+(i-1)*h;
endfor

for i=1:n
  soma += (f(x(i))+f(x(i+1)));
endfor

INTEGRAL = h/2*(soma)