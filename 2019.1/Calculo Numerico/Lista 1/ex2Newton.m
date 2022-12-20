% metodo de newton
clear
f=@(x) 3*x^2 - e^x;
d=@(x) 6*x - e^x;
i=1;
x(i) = 2;
x(i+1) = x-f(x)/d(x);
tol=0.00001;

while abs(x(i+1)-x(i))>tol && abs(f(x(i)))>tol
  i++;
  x(i+1) = x(i)-f(x(i))/d(x(i));
endwhile
sol = x(i)