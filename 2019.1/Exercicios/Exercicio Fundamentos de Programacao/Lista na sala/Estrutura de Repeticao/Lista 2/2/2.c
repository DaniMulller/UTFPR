/*Calcular e mostrar o fatorial de um n�mero informado pelo usu�rio*/

# include <stdio.h>

int main(void)

{
    int num,fat=1,i;

    printf("Informe um numero: ");
    scanf("%d",&num);

    for (i=num ; i>1 ; i--)
    {
        fat = fat*i;
    }
    printf("\nFatorial do numero informado e %d\n",fat);
}
