/*Considerando que para um consórcio sabe-se o número total de prestações, a quantidade
de prestações pagas e o valor de cada prestação (que é fixo). Escreva um algoritmo que
determine o valor total já pago pelo consorciado e o saldo devedor.*/

# include <stdio.h>

int main(void)


{
    int prestacoes_npagas, prestacoes_pagas;
    float valor, valor_pago, saldo_devedor;

    printf("Informe o valor das prestacoes: ");
    scanf("%f",&valor);
    printf("Informe a quantidade de prestacoes pagas: ");
    scanf("%d",&prestacoes_pagas);
    printf("Informe a quantidade de prestacoes ainda nao pagas: ");
    scanf("%d",&prestacoes_npagas);

    valor_pago = valor*prestacoes_pagas;
    saldo_devedor = valor*prestacoes_npagas;

    printf("\nForam pagos %.2f R$ e ainda devem ser pagos %.2f R$\n",valor_pago,saldo_devedor);

}
