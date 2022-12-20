/* Apresentar os múltiplos de 5, entre 5 e 50*/

# include <stdio.h>

int main(void)

{
    int i;

    printf("Sem uso do if\n");
    for(i=5; i<=50 ; i=i+5) //i+=5
    {
        printf("%d\t",i);
    }

    printf("\n\nCom uso do if\n");
    for (i=5 ; i<=50 ; i++)
    {
        if (i%5 == 0)
        {
            printf("%d\t",i);
        }
    }
}
