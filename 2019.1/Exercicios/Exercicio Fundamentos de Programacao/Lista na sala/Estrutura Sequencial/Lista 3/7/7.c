/*Ler um n�mero inteiro longo (long int) que representa segundos e convert�-lo para horas,
minutos e segundos. Mostrar a quantidade de horas, minutos e segundos obtidos, no
seguinte formato: xhoras:yminutos:zsegundos.
Exemplo:
informado o valor 3725
apresentar
1hora:2minutos:5segundos
Observa��o:
//declarar uma vari�vel inteiro longo
long int Num;
//ler uma vari�vel inteiro longo
scanf(�%li�,&Num);
//mostrar o conte�do de uma vari�vel inteiro longo
printf(�valor %li�,Num);*/

# include <stdio.h>

int main(void)

{
    long int num;
    int horas, minutos, segundos;

    printf("Informe um numero: ");
    scanf("%li",&num);

    horas = num/3600;
    minutos =  num%3600 / 60;
    segundos =  num%3600%60;

    printf("\nValor: %d horas, %d minutos, %d segundos \n",horas,minutos,segundos);



}


