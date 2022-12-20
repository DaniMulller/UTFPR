% metodo da bisseccao
clear
i=0;
a=1;
b=2;
tol=0.0005;
f=@(x) x^2 - 2;

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
  