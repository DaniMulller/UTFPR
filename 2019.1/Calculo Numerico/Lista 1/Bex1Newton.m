% metodo de newton
clear
f=@(x) x - cos(x);
d=@(x) 1 + sin(x);
i=1;
x(i) = pi/2;
x(i+1) = x-f(x)/d(x);
tol=0.00005;

while abs(x(i+1)-x(i))>tol && abs(f(x(i)))>tol
  i++;
  x(i+1) = x(i)-f(x(i))/d(x(i));
endwhile
sol = x(i)