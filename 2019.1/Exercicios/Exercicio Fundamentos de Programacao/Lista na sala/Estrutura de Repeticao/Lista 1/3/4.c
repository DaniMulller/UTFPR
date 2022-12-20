/*Apresentar os números entre 10 e 0, ou seja, em ordem decrescente*/

# include <stdio.h>

int main(void)

{
    int i;

    for (i=10 ; i >=0 ; i=i-1 )
    {
        printf("%d\n",i);
    }
    printf("\nValor de i ao sair do for: %d\n",i);
}
