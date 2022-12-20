/*Um viajante de carro far� o trajeto entre duas cidades e ao t�rmino deseja saber:
    - Quantas vezes foi necess�rio abastecer;
    - Quantos litros foram consumidos para percorrer a dist�ncia indicada;
    - Quantos litros restaram no tanque ap�s a chegada ao destino.
    Faca um programa em C que leia a dist�ncia entre as duas cidades, a capacidade do
tanque e o consumo m�dio do veiculo, calcule e mostre as informa��es solicitadas.*/

# include <stdio.h>

int main(void)

{
    int distancia, abasteceu, consumido, resta, capacidade;
    float consumo_medio;

    printf("Informe a distancia entre as cidades em km: ");
    scanf("%d",&distancia);
    printf("Informe a capacidade do tanque: ");
    scanf("%d",&capacidade);

    abasteceu = distancia/capacidade;
    printf("\nFoi necessario abastecer: %d vezes na viagem\n",abasteceu);

    consumo_medio = (float)distancia/(float)consumido;
    printf("\nO consumo medio foi de: %.2f litros por km\n",consumo_medio);

    consumido = abasteceu*capacidade;
    printf("\nForam consumidos: %d litros na viagem\n",consumido);

    resta = consumido-capacidade;
    printf("\nRestaram %d litros\n",resta);
}
