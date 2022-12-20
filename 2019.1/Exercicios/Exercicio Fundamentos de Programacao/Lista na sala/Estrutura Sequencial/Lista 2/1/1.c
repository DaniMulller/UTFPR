/*Ler dois números reais (ponto flutuante) e apresentar, sem utilizar funções
matemáticas prontas:
    a) A divisão do primeiro número pelo segundo, armazenando somente a parte
inteira do valor resultante da divisão.
    b) A soma dos dois números com o resultado arredondado para o próximo número
inteiro.
Fazer o mesmo exercício utilizando funções da biblioteca <math.h>.  É necessário
incluí-la com # include <math.h>
A função int ceil (float num) faz arredondamento do número para cima, ou seja,
para o próximo inteiro.
    A função int trunc (float num) apanha apenas a parte inteira do número, desconsiderando a sua parte decimal.*/

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
