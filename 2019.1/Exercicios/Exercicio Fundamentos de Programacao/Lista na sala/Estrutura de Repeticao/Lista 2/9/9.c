/* Ler números inteiros informados pelo usuário até ser informado um valor negativo. Dentre
os números informados, exceto o valor negativo que é a condição de saída:
a) contar a quantidade de números menores que 10 e os maiores que 100;
b) contar a quantidade de números ímpares;
c) contar a quantidade de números entre 10 e 100;
d) contar quantas vezes é informado um número diferente de 10, de 20 e de 30*/

# include <stdio.h>

int main(void)

{
    int i,num=1;

    for (i=0;num > 0;i++)
    {
        printf("Informe um numero: ");
        scanf("%d",&num);

        if (i<10 && i>100)
        {
            printf("\nNumeros menores que 10 e maiores que 100: ",i);
        }
        else if (i%2!=0)
        {
            printf("\nNumeros impares: ",i);
        }
        else if (i>10 && i<100)
        {
            printf("\nNumeros entre 10 e 100: ",i);
        }
        else if (i!=10 && i!=20 && i!=30)
        {
            printf("\nNumero diferente de 10, de 20 e de 30: ",i);
        }
    }
}
