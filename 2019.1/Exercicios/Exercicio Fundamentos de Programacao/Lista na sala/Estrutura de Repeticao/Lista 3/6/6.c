/*Apresente os pares entre entre 0 e 100, sem utilizar if dentro do for*/

# include <stdio.h>

int main(void)

{
    int i;

    for (i=0;i<=100;i=i+2)
    {
        printf("%d\t",i);
    }
}
