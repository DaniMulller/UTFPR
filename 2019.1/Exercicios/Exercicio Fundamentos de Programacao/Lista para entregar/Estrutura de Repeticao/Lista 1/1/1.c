/*Elaborar um programa para mostrar os números pares entre 10 e 100. Fazer a média dos
valores desse intervalo que são divisíveis por 5.*/

# include <stdio.h>

int main(void)

{
    int i,qtd_todos=0,soma_todos=0;
    float media;

    for (i=10;i<=100;i=i+2)
    {
        printf("%d\t",i);

        if (i%5==0)
        {
            soma_todos = soma_todos + i;
            qtd_todos++;
        }
    }

    if (qtd_todos!=0)
    {
        media = (float)soma_todos/qtd_todos;
        printf("\nMedia dos divisiveis por 5: %.2f",media);
    }

}
