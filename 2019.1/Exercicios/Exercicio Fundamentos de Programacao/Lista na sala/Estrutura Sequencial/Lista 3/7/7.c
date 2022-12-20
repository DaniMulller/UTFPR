/*Ler um número inteiro longo (long int) que representa segundos e convertê-lo para horas,
minutos e segundos. Mostrar a quantidade de horas, minutos e segundos obtidos, no
seguinte formato: xhoras:yminutos:zsegundos.
Exemplo:
informado o valor 3725
apresentar
1hora:2minutos:5segundos
Observação:
//declarar uma variável inteiro longo
long int Num;
//ler uma variável inteiro longo
scanf(“%li”,&Num);
//mostrar o conteúdo de uma variável inteiro longo
printf(“valor %li”,Num);*/

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


