% metodo de newton
clear
f=@(x) x^3 + 3*x^2 - 1;
d=@(x) 3*x^2 + 6*x;
i=1;
x(i) = 2;
x(i+1) = x-f(x)/d(x);
tol=0.00005;

while abs(x(i+1)-x(i))>tol && abs(f(x(i)))>tol
  i++;
  x(i+1) = x(i)-f(x(i))/d(x(i));
endwhile
sol = x(i)