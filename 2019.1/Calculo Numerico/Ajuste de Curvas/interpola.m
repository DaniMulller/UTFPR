clear
clc

x(1)=-1;
x(2)=0;
x(3)=1;
x(4)=2;
y(1)=1;
y(2)=3;
y(3)=-1;
y(4)=-5;
n=3;
pn=0;

t=[-1:0.01:5];

for i=1:n+1
  L(i,:) =0*t+1;
endfor

for i=1:n+1
  for j=1:n+1
    if(j!=i)
      L(i,:) .*= (t-x(j))/(x(i)-x(j));
    endif
  endfor
endfor

for k=1:n+1
  pn += y(k)*L(k,:);
endfor
pn;

plot(x,y,'*',t,pn)
