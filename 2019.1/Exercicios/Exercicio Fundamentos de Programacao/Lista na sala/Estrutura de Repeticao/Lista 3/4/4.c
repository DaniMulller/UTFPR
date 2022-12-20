/* Leia dos valores que representam os limites de um intervalo. O usu�rio pode informar
os valores em ordem crescente ou decrescente. Mostrar os divis�veis por x e n�o
divis�veis por y nesse intervalo. X e y s�o vari�veis informadas pelo usu�rio.
Exemplo:
Informados: 5 e 15 como limites e 2 para x e 3 para y.
Mostrar os divis�veis por 2 e n�o divis�veis por 3 entre 5 e 15:
2 4 6 8 10 14*/

# include <stdio.h>

int main(void)

{
    int num1,num2,i;

    printf("Informe um limite: ");
    scanf("%d",&num1);
    printf("Informe outro limite: ");
    scanf("%d",&num2);

    if (num1>num2)
    {
        printf("\nDivisiveis por 2 e nao por 3: ");
        for (i=num2;i<=num1;i++)
        {
            if (i%2==0 && i%3!=0)
            {
                printf("\n");
                printf("%d\t",i);
            }
        }
    }
    else
    {
        printf("\nDivisiveis por 2 e nao por 3: ");
        for (i=num1;i<=num2;i++)
        {
            if (i%2==0 && i%3!=0)
            {
                printf("\n");
                printf("%d\t",i);
            }
        }
    }
}
