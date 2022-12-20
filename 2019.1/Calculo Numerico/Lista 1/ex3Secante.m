% metodo de newton
clear
f=@(x) 1/x;
i=0;
x(1) = 1;
x(2) = 2;
tol=0.0001;

while abs(x(i+2)-x(i+1))>tol && abs(f(x(i+2)))>tol
  i++;
  x(i+2) = (x(i)*f(x(i+1))-x(i+1)*f(x(i)))/(f(x(i+1))-f(x(i)));
endwhile
sol = x(i)