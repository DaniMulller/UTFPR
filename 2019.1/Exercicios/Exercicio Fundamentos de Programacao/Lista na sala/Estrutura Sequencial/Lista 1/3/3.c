# include <stdio.h>

int main(void)

{
    float valor_juros;
    float prestacao;
    float taxa;

    printf("Informe o valor da prestacao: ");
    scanf("%f",&prestacao);
    printf("Informe o valor da taxa: ");
    scanf("%f",&taxa);

    valor_juros = prestacao + (prestacao * taxa/100);

    printf("\nO valor a ser pago com juros e de %.2f R$\n"),valor_juros;

}
