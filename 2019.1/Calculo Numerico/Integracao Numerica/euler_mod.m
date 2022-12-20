clc
clear

f=@(x,y) y;
x(1)=0;
y(1)=1;
w(1)=y(1);
h=0.1;
n=50;

for i=1:n
  x(i+1)=x(1)+i*h;
endfor

for i=1:n
  w(i+1)=w(i)+h*f(x(i),w(i)); %METODO DE EULER
endfor

for i=1:n
  z(i+1)=y(i)+h*f(x(i),y(i));
  y(i+1)=y(i)+h/2*(f(x(i),y(i))+f(x(i+1),z(i+1))); %METODO DE EULER MODIFICADO
endfor

sol_exata = e.^x;
plot(x,w,'b*',x,y,'o',x,sol_exata)
