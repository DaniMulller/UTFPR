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

int main(void)

{
    int dimensao,classe,lampadas;

    printf("Informe a categoria do comodo(A,B,C): ");
    scanf("%c",&classe);

    if (classe == 'A' || classe == 'a' || classe == 'B' || classe == 'b' || classe == 'C' || classe == 'c')
        {
            printf("Informe as dimensoes do comodo em metros quadrados: ");
            fflush(stdin);
            scanf("%d",&dimensao);

            if (classe == 'A' || classe == 'a')
                {
                    lampadas = (dimensao/15);
                    printf("\nSerao necessarias %d lampadas\n",lampadas);
                }
            else if (classe == 'B' || classe == 'b')
                {
                    lampadas = (dimensao/18);
                    printf("\nSerao necessarias %d lampadas\n",lampadas);
                }
            else if (classe == 'C' || classe  == 'c')
                {
                    lampadas = (dimensao/20);
                    printf("\nSerao necessarias %d lampadas\n",lampadas);
                }
        }
    else
    {
        printf("\nInforme uma categoria valida!\n");
    }
}
