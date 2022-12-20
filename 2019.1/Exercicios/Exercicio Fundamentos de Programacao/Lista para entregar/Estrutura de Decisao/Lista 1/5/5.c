/* Elaborar um algoritmo para realizar o controle de pagamento de um
estacionamento
,
com base na tabela a seguir. O tempo é informado em minutos.
Tempo                  Valor

Até 15 minutos         Grátis
Até 60 minutos         R$ 10.40
Acima de 60 minutos    R$ 11.20 + R$ 1.20 por hora excedente. */

# include <stdio.h>

int main(void)

{
    int minutos;

    printf("Informe quantos minutos utilizou o estacionamento: ");
    scanf("%d",&minutos);

    if (minutos < 15)
    {
        printf("\nNao e preciso pagar o estacionamento!\n");
    }
    else if (minutos >= 15 && minutos < 60)
    {
        printf("\nO valor a ser pago e de: 10.40 R$!\n");
    }
    else
    {
        float valor;

        valor = (minutos-60)/60 * 1.2;

        printf("\nO valor a ser pago e de: 11.20 R$ + %.2f R$\n",valor);
    }
}
