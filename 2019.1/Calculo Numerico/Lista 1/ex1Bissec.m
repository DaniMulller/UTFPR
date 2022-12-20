% metodo da bisseccao
clear
i=0;
a=-2;
b=-4;
tol=0.00005;
f=@(x) x^3 + 3*x^2 - 1;

while abs(b-a)>tol
  i++;
  x(i)=(a+b)/2;
  if f(a)*f(x(i))<0
    b=x(i);
   else
    a=x(i);
  endif   
endwhile
sol = x(i)