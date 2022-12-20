/* O custo ao consumidor  de um carro novo é a soma do custo de fábrica com a
percentagem do distribuidor e a percentagem dos impostos (ambas aplicadas sobre o
custo de fábrica). Escrever um algoritmo para, a partir do custo de fábrica do carro,
calcular e mostrar o custo ao consumidor.*/

# include <stdio.h>

int main(void)

{
    float consumidor, imposto, distribuidor, fabrica;

    printf("Informe o valor do custo de fabrica do carro: ");
    scanf("%f",&fabrica);
    printf("Informe o imposto sobre o carro(2 para 2%%): ");
    scanf("%f",&imposto);
    printf("Informe a porcentagem do distribuidor(5 para 5%%): ");
    scanf("%f",&distribuidor);

    consumidor = fabrica + ((fabrica*distribuidor)/100) + ((fabrica*imposto)/100);

    printf("\nO preco final para o consumidor e de: %.2f R$\n",consumidor);
}
