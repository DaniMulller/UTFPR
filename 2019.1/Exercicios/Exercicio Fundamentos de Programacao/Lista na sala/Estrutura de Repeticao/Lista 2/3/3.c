/*Apresentar o quadrado dos n�meros divis�veis por 3 e a raiz quadrada dos n�meros
positivos e divis�veis por 5 ou por 7 entre 0 a 100. Apresentar em listagens separadas: uma
para os quadrados e outra para as ra�zes quadradas. Colocar um cabe�alho antes de cada
listagem de maneira a identificar o conte�do da mesma. Em cada listagem separar os n�meros
por uma tabula��o. A raiz quadrada pode ser obtida pela fun��o sqrt () que est� na biblioteca
<math.h>*/

# include <stdio.h>
# include <math.h>

int main(void)

{
    int i,divisiveis_3=1,divisiveis_5_7;

    printf("\nQuadrado dos divisiveis por 3\n");
    printf("\n");
    for(i=0;i<=100;i++)
    {
        if (i%3==0)
        {
            divisiveis_3 = i*i;
            printf("%d\t",divisiveis_3);
        }
    }
    printf("\n---------------------------------------------------------------------------------------------------------------------\n");

    printf("\nRaiz dos divisiveis por 5 ou 7\n");
    printf("\n");
    for(i=0;i<=100;i++)
    {
        if (i%5==0 || i%7==0)
        {
            divisiveis_5_7 = sqrt(i);
            printf("%d\t",divisiveis_5_7);
        }
    }
    printf("\n");
}
