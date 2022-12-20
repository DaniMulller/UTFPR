/* A figura a seguir representa uma �rvore de decis�o para identificar se um paciente est�
saud�vel ou doente. Elabore um algoritmo que implementa essa �rvore de decis�o.*/

# include <stdio.h>

int main(void)

{
    char sentindo,dor;
    int temp;

    printf("Informe se esta se sentindo bem(s/n): ");
    scanf("%c",&sentindo);

    if (sentindo == 's')
    {
        printf("\nPaciente Saudavel!\n");
    }
    else if (sentindo == 'n')
    {
        printf("\nTem dores de cabeca?(s/n): ");
        fflush(stdin);
        scanf("%c",&dor);

        if (dor == 's')
        {
            printf("\nPaciente Doente!\n");
        }
        else if (dor == 'n')
        {
            printf("\nInforme a temperatura da febre: ");
            scanf("%d",&temp);

            if (temp > 37)
            {
                printf("\nPaciente Doente!\n");
            }
            else
            {
                printf("\nPaciente Saudavel!\n");
            }
        }
    }
    else
    {
        printf("\nInforme um caracter valido!\n");
    }
}
