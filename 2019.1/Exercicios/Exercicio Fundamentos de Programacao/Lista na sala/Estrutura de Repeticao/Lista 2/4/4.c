/* Apresentar os n�meros divis�veis por 4 ou m�ltiplos de 10 entre 500 e 0 e a m�dia desses
m�ltiplos.*/

# include <stdio.h>

int main(void)

{
    int i,media,qtd=0,soma;

    for (i=0;i<=500;i++)
    {
        if (i%4==0 || i%10==0)
        {
            printf("%d\t",i);
            soma = soma + i;
            qtd = qtd + 1;
        }
    }
    media = soma/qtd;

    printf("\n\nMedia dos numeros: %d\n",media);
}
