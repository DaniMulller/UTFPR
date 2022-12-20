%Nome: Daniel Augusto Muller

%% Atividade 1 
clear all;
close all;
t=0:0.001:1;
x1=cos(pi*10*t);
figure
plot(t,x1);
ylim([-1.1 1.1]);
grid
title('cos(2*pi*10*t)')
xlabel('Tempo(s)')
ylabel('Amplitude')

sample=10; 
for k=1:1:(length(t)-1)/sample 
    n(1,k)=k;
    x2(1,k)=x1(k*sample); 
end
figure
stem(n,x2,'r') 
ylim([1.1 1.1])
grid
title('x[n] é x(t) amostrado')
xlabel('Tempo [n]')
ylabel('Amplitude')

n=0:1:10;
x3=cos(pi*n);
figure
stem(n,x3,'r')
ylim([-1.1 1.1])
grid
title('x[n] é um sinal de tempo discreto')
xlabel('Tempo [n]')
ylabel('Amplitude')

%% Atividade 2
clear all;
close all;
A=1; %amplitude 
phi=0; %fase do sinal 
w0=2*pi*5;% frequência angular 
t=0:0.001:1;%tempo contínuo 
sq=A*square(w0*t+phi);% procure a função square no help do matlab 
figure
plot(t,sq); 
ylim([-1.1 1.1]) 
title('utilizando a função "square" para gerar um sinal de tempo contínuo')
xlabel('Tempo (t)')
ylabel('Amplitude')

w0=10*pi; 
W=0.5; 
tri=A*sawtooth(2*w0*t,W); 
plot(t, tri); 
ylim([-1.1 1.1]) 
title('utilizando a função "sawtooth" para gerar um sinal de tempo contínuo')
xlabel('Tempo (t)')
ylabel('Amplitude')

close all % fecha todas as figuras anteriores 
clear all %deleta todas as variáveis da workspace 
A=1; 
w0=0.25*pi; 
n=-10:1:10; 
sqd=A*square(w0*n); % procure a função square no help do matlab 
stem(n,sqd); 
ylim([-1.1 1.1]) 
xlim([-10 10]) 
title('utilizando a função "square" para gerar um sinal de tempo discreto')
xlabel('Tempo [n]')
ylabel('Amplitude')

A=1; 
w0=0.25*pi; 
n=0:1:25; 
sqd=A*sawtooth(10*w0*n); % procure a função square no help do matlab 
stem(n,sqd); 
ylim([-1.1 1.1]) 
xlim([0 25]) 
title('utilizando a função "square" para gerar um sinal de tempo discreto')
xlabel('Tempo [n]')
ylabel('Amplitude')










