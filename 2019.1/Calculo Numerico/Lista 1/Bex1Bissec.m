% metodo da bisseccao
clear
i=0;
a=0;
b=pi/2;
tol=0.00005;
f=@(x) x - cos(x);

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