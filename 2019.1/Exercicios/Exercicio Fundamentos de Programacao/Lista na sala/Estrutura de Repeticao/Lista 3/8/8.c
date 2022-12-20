/*Apresentar os números entre 100 e 200. Contar quantos são ímpares e não divisíveis
por 3 nesse intervalo. Fazer a média dos valores pares e divisíveis por 5 do intervalo.*/

# include <stdio.h>

int main(void)

{
    int i,qtd_impar_3=0,qtd_pares_5=0,soma_pares;
    float media;

    printf("Numeros entre 100 e 200: ");

    for (i=100;i<=200;i++)
    {
        printf("%d\t",i);
        if (i%2!=0 && i%3!=0)
        {
            qtd_impar_3 = qtd_impar_3 + i;
        }

        if (i%2==0 && i%5==0)
        {
            qtd_pares_5++;
            soma_pares = soma_pares + i;
        }
    }
    media = soma_pares/qtd_pares_5;
    printf("\n\nNumeros impares e divisiveis por 3: ",qtd_impar_3);
    printf("\n\nMedia dos numeros pares e divisiveis por 5: \n",media);
}
