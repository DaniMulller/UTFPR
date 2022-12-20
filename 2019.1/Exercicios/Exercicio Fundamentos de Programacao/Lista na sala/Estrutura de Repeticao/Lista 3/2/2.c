/* Faça um programa que apresente uma tabela de lucro esperado, em decorrência do
número de pessoas e valor do ingresso. O valor do ingresso vai de R$ 15 até 20,
aumentando de 0,50 centavos. É informada a quantidade de pessoas. */

# include <stdio.h>

int main(void)

{
    int pessoas;
    float i,valor;

    printf("Informe o numero de pessoas: ");
    scanf("%d",&pessoas);

    for (i=15;i<=20;i=i+0.5)
    {
        valor =  pessoas*i;
        printf("\n%.2fR$ , Valor recebido: %.2fR$\n",i,valor);
    }
}
