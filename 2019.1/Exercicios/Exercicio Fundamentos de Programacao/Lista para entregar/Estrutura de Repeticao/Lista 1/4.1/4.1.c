/*Elaborar um programa para calcular a quantidade de lâmpadas para uma residência,
independentemente da quantidade e do tipo de cômodos. A casa pode ter vários quartos, salas
e etc.
Ler a classe do cômodo e as suas duas dimensões. Calcular a quantidade de lâmpadas
necessárias de acordo com a tabela anterior. Suponha quer serão utilizadas somente lâmpadas
de 60 wats. Ao final informar a quantidade total de lâmpadas necessárias.
Estabeleça uma condição para finalizar a leitura dos dados de entrada. Exemplo:
a) uma classe inválida. Nesse caso, quando informada uma classe inválida, não devem ser
lidas as dimensões do cômodo.
b) ler, inicialmente, a quantidade de cômodos.
Observação: Atenção o número total de lâmpadas informado deverá ser inteiro. E lembre-se
que cada cômodo utilizará um número inteiro de lâmpadas.*/

#include <stdio.h>
#include <math.h>

int main(void)

{
    int dimensao,lampadas=0,comodos,i;
    char classe;

    printf("Informe o numero de comodos: ");
    scanf("%d",&comodos);

    for (i=1;i<=comodos;i++)
    {
        printf("\nInforme as dimensoes do comodo em metros quadrados: ");
        fflush(stdin);
        scanf("%d",&dimensao);

        printf("Informe a categoria do comodo(A,B,C): ");
        fflush(stdin);
        scanf("%c",&classe);

          if (classe == 'A' || classe == 'a')
        {
            lampadas = lampadas + (ceil)(dimensao/15));
        }
        else if (classe == 'B' || classe == 'b')
        {
            lampadas = lampadas + ceil(dimensao/18));
        }
        else if (classe == 'C' || classe  == 'c')
        {
            lampadas = lampadas + ceil(dimensao/20));
        }
        else
        {
            printf("\nInforme uma categoria valida!\n");
        }

        printf("\nSerao necessarias %d lampadas\n",lampadas);
    }
}
