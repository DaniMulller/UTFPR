/*Implemente um cronômetro, apresentando dados de horas, minutos e segundos da
seguinte forma: 00:00:00. O cronômetro inicia com 00:00:00 e quando chegar a
23:59:59, deverá ir para 00:00:00.*/

# include <stdio.h>
# include <windows.h>
# include <stdlib.h>

int main(void)

{
    int i,j,k;

    printf("\n");
    for (i=0;i<=24;i++)
    {
        system("cls");
        for (j=0;j<=59;j++)
        {
            system("cls");
            for (k=0;k<=59;k++)
            {
                system("cls");
                printf("%d : %d : %d\n",i,j,k);
                Sleep(1000);
            }
        }
    }
    if (i==24)
    {
        i=0;
    }
}
