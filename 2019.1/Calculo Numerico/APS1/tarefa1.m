% metodo de newton
clear
f=@(x) x^4 - 3*x^3 + x - 2;
d=@(x) 4*x^3 - 9*x^2 + 1;
i=1;
x(i) = -1;
x(i+1) = x-f(x)/d(x);
tol=0.00005;

while abs(x(i+1)-x(i))>tol && abs(f(x(i)))>tol
  i++;
  x(i+1) = x(i)-f(x(i))/d(x(i));
endwhile
tentativas = i
primeiro_chute = x(1)
sol = x(i)

% A equacao aprenta 2 raízes reais

% A) Após ver o gráfico da equacao decidi o chute inicial como 3 pois esta perto de uma das raízes.
% Mas também utilizei -1 como chute inicial para detectar a outra raíz.

% B) x1 = 2.9630 e x2 = -0.90613

% C) O número varia conforme o primeiro chute, mas com o chute de 3, foram feitas 3 tentativas e com o
% chute de -1 foram 4 tentativas.