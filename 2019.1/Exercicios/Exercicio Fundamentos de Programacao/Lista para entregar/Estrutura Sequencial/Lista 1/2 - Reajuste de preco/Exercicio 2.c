# include <stdio.h>

int main(void)

{
    float produto;
    float porcentagem;
    float reajuste;
    float valor_reajustado;

    printf("Informe o valor do produto: ");
    scanf("%f",&produto);
    printf("Informe o percentual do reajuste(5 para 5%%): ");
    scanf("%f",&porcentagem);

    reajuste = produto * (porcentagem/100);
    valor_reajustado = produto + reajuste;

    printf("\nValor reajustado: %.2f R$\n",valor_reajustado);
}
