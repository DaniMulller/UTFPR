/*Apresentar o quadrado dos números divisíveis por 3 e a raiz quadrada dos números
positivos e divisíveis por 5 ou por 7 entre 0 a 100. Apresentar em listagens separadas: uma
para os quadrados e outra para as raízes quadradas. Colocar um cabeçalho antes de cada
listagem de maneira a identificar o conteúdo da mesma. Em cada listagem separar os números
por uma tabulação. A raiz quadrada pode ser obtida pela função sqrt () que está na biblioteca
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
