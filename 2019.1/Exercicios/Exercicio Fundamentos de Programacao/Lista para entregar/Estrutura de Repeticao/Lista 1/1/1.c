/*Elaborar um programa para mostrar os n�meros pares entre 10 e 100. Fazer a m�dia dos
valores desse intervalo que s�o divis�veis por 5.*/

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
