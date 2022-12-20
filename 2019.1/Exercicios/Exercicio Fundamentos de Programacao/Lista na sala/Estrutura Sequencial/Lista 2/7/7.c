/*Um viajante de carro fará o trajeto entre duas cidades e ao término deseja saber:
    - Quantas vezes foi necessário abastecer;
    - Quantos litros foram consumidos para percorrer a distância indicada;
    - Quantos litros restaram no tanque após a chegada ao destino.
    Faca um programa em C que leia a distância entre as duas cidades, a capacidade do
tanque e o consumo médio do veiculo, calcule e mostre as informações solicitadas.*/

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
