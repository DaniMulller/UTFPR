/* Mostrar os valores ímpares e não divisíveis por 5 entre 200 e 0. Apresentar os valores
em ordem decrescente. Fazer a média dos valores desse intervalo que são divisíveis por 3
e por 5.*/

# include <stdio.h>

int main(void)

{
    int i,soma=0,qtd=0;
    float media;

    printf("Numeros impares e nao divisiveis por 5: ");
    for (i=0;i<=200;i++)
    {
        if (i%2!=0 && i%5!=0)
        {
            printf("%d\t",i);
        }
    qtd++;
    soma = soma + i;
    }
    media = soma/(float)qtd;

    printf("\n\nMedia dos numeros: %.2f\n",media);
}
