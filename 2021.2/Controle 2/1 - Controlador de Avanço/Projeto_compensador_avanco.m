close all;
clear all;
clc;

%Planta
num=16;
den=[1 4 0];
G=tf(num,den)
%Planta sem compensação em malha fechada
Gmf=feedback(G,1)
%Polos de MF sem compensação
polos_Gmf = pole(Gmf)

%Lugar das raízes de G(s)
%rlocus(G)

%Verificação da condição de ângulo
s=-8+j*8.392;
angulo_lugar_raizes_negativo = angle(4/(s*(s+4)))*180/pi-360 %O resultado é em rad que é convertido para graus.
angulo_lugar_raizes_positivo = angle(4/(s*(s+4)))*180/pi %O resultado é em rad que é convertido para graus.
teta = 180 - angle(4/(s*(s+4)))*180/pi %O resultado é em rad que é convertido para graus.

%Cálculo de Kc
Kc=1/abs(4/(s*(s+4)))

%Compensador
numc=4*[1 2];
denc=[1 4];
Gc=tf(numc,denc)

%Planta com compensação em malha fechada
Gmfc=feedback(Gc*G,1);
Gmfc=minreal(Gmfc)
%Polos de MF com compensação
polos_Gmfc = pole(Gmfc)

%Resposta ao degrau
figure;
step(Gmf);
hold;
step(Gmfc);
legend('Sem compensação', 'Com compensação');

%Lugar das raízes da planta compensada
figure;
rlocus(Gc*G);