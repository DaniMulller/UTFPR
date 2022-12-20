close all;
clear all;
clc;

%Planta
num=16;
den=[1 4 0];
G=tf(num,den)
%Planta sem compensa��o em malha fechada
Gmf=feedback(G,1)
%Polos de MF sem compensa��o
polos_Gmf = pole(Gmf)

%Lugar das ra�zes de G(s)
%rlocus(G)

%Verifica��o da condi��o de �ngulo
s=-8+j*8.392;
angulo_lugar_raizes_negativo = angle(4/(s*(s+4)))*180/pi-360 %O resultado � em rad que � convertido para graus.
angulo_lugar_raizes_positivo = angle(4/(s*(s+4)))*180/pi %O resultado � em rad que � convertido para graus.
teta = 180 - angle(4/(s*(s+4)))*180/pi %O resultado � em rad que � convertido para graus.

%C�lculo de Kc
Kc=1/abs(4/(s*(s+4)))

%Compensador
numc=4*[1 2];
denc=[1 4];
Gc=tf(numc,denc)

%Planta com compensa��o em malha fechada
Gmfc=feedback(Gc*G,1);
Gmfc=minreal(Gmfc)
%Polos de MF com compensa��o
polos_Gmfc = pole(Gmfc)

%Resposta ao degrau
figure;
step(Gmf);
hold;
step(Gmfc);
legend('Sem compensa��o', 'Com compensa��o');

%Lugar das ra�zes da planta compensada
figure;
rlocus(Gc*G);