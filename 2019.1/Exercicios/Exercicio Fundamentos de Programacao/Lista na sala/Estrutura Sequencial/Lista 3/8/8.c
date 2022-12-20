/* Suponha que um caixa disponha apenas de cédulas de R$ 10, 5, 2 e 1. Escreva um
programa para ler o valor de uma conta e o valor fornecido pelo usuário para pagar essa
conta, e calcule e troco. Calcular e mostrar a quantidade de cada tipo de cédula que o caixa
deve fornecer como troco e os centavos que devem ser fornecidos. Mostrar, também o valor
da compra e do troco.*/


# include <stdio.h>

int main(void)

{
    float valor, fornecido, troco;
    int q10, q5, q2, q1;

    printf("Informe o valor do produto: ");
    scanf("%f",&valor);
    printf("Informe o valor fornecido pelo usuario: ");
    scanf("%f",&fornecido);

    troco = fornecido - valor;
    q10 = (int)troco/10;
    q5 = (int)troco%10/5;
    q2 = (int)troco%5/2;
    q1 = (int)troco%2/1;

    printf("\nDevera ser dado %d de 10R$, %d de 5R$, %d de 2R$, %d de 1R$\n",q10,q5,q2,q1);
    printf("\nValor da compra: %.2f R$, Valor do Troco: %.2f R$\n",valor,troco);
}
