/*Ler dois n�meros reais (ponto flutuante) e apresentar, sem utilizar fun��es
matem�ticas prontas:
    a) A divis�o do primeiro n�mero pelo segundo, armazenando somente a parte
inteira do valor resultante da divis�o.
    b) A soma dos dois n�meros com o resultado arredondado para o pr�ximo n�mero
inteiro.
Fazer o mesmo exerc�cio utilizando fun��es da biblioteca <math.h>.  � necess�rio
inclu�-la com # include <math.h>
A fun��o int ceil (float num) faz arredondamento do n�mero para cima, ou seja,
para o pr�ximo inteiro.
    A fun��o int trunc (float num) apanha apenas a parte inteira do n�mero, desconsiderando a sua parte decimal.*/

# include <stdio.h>

int main(void)

{
    float num1, num2;
    int soma, divisao;

    printf("Informe o primeiro valor: ");
    scanf("%f",&num1);
    printf("Informe o segundo valor: ");
    scanf("%f",&num2);

    soma = (num1+num2) + 0,999999;
    divisao = (int)num1/(int)num2;

    printf("Soma: %d e Divisao: %d",soma,divisao);

    printf("\nUtilizando funcoes matematicas\n");
    soma = ceil(num1+num2); //arredonda para o proximo inteiro
    divisao = trunc(num1+num2); //apanhar somente a parte inteira do numero
    printf("Soma: %d e Divisao: %d\n",soma,divisao);

    return(0);

}

    float num1, num2;
    int soma, divisao;

    printf("Informe o primeiro valor: ");
    scanf("%f",&num1);
    printf("Informe o segundo valor: ");
    scanf("%f",&num2);

    soma = (num1 + num2) + 0.999999;
    divisao = (int)num1/(int)num2;

    printf("Soma: %d e Divisao: %d\n",soma,divisao;

    printf("\nUtilizando funcoes matematicas\n");
    soma = ceil(num1+num2); //arredonda para o proximo inteiro
    divisao = trunc(num1/num2); //apanhar somente a parte interia do numero
    printf("Soma: %d e Divisao: %d\n",soma,divisao);




}
