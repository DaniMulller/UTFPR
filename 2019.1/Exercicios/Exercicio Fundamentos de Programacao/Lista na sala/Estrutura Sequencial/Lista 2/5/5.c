/*Escreva um algoritmo para ler o número de votos brancos, nulos (incluem eleitores
ausentes)   e   válidos   de   uma   eleição.   Calcular   e   mostrar   o   percentual   que   cada   um
(brancos, nulos e válidos) representa em relação ao total de eleitores. Lembrar que os
valores dos percentuais podem não ser inteiros.*/

# include <stdio.h>

int main(void)

{
    int brancos, nulos, validos;
    float p_brancos, p_nulos, p_validos;

    printf("Informe a qauntidade de votos brancos: ");
    scanf("%d",&brancos);
    printf("Informe a quantidade de votos nulos: ");
    scanf("%d",&nulos);
    printf("informe a quantidade de votos validos: ");
    scanf("%d",&validos);

    p_brancos= ((float)brancos/(float)(brancos+nulos+validos))*100;
    printf("\nO percentual de votos brancos e de: %.2f %%\n",p_brancos);

    p_nulos = ((float)nulos/(float)(brancos+nulos+validos))*100;
    printf("\nO percentual de votos nulos e de: %.2f %%\n",p_nulos);

    p_validos = ((float)validos/(float)(brancos+nulos+validos))*100;
    printf("\nO percentual de votos validos e de: %.2f %%\n",p_validos);

}
