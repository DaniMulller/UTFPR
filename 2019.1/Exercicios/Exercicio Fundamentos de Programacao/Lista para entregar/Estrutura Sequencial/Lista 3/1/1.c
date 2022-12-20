/* Ler um número inteiro que representa dias.
a) Obter e mostrar a quantidade de semanas que esse número possui.
b) Multiplicar os dias restantes, retiradas as semanas, por 24 e informar o número de
horas obtido.
c) Dividir esse número de horas por 8 e mostrar somente a parte inteira do resultado dessa
divisão.
d) Apanhar o resto dessa divisão por 8 e calcular e mostrar o percentual que essas horas
representam de uma semana.
e) Somar os dígitos do número lido e mostrar.
Por exemplo:
Informado: 125
Semanas: 17
Horas: 6 (o resto da divisão) multiplicado por 24 = 144
Parte inteira da divisão por 8: 18
144 horas representam 85% de uma semana
Soma dos dígitos do número lido: 8*/

# include <stdio.h>

int main(void)

{
    int num, semanas, soma, resto, horas, percentual, horas_8;

    printf("Informe um numero: ");
    scanf("%d",&num);

    semanas = num/7;
    horas = (num%7);
    resto = horas*24;
    horas_8 = resto/8;
    percentual = (resto*100)/168;
    soma = num%10 + num/10%10 + num/100%10;

    printf("\nInformado: %d\n",num);
    printf("\nSemanas: %d\n",semanas);
    printf("\nHoras: %d (o resto da divisao multiplicado por 24): %d\n",horas,resto);
    printf("\nParte inteira da divisao dividida por 8: %d\n",horas_8);
    printf("\n%d horas representam %d%% de uma semana\n",resto,percentual);
    printf("\nSoma dos digitos lidos: %d\n",soma);
}
