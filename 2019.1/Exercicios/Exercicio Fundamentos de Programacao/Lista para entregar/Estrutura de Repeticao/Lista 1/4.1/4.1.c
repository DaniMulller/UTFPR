/*Elaborar um programa para calcular a quantidade de l�mpadas para uma resid�ncia,
independentemente da quantidade e do tipo de c�modos. A casa pode ter v�rios quartos, salas
e etc.
Ler a classe do c�modo e as suas duas dimens�es. Calcular a quantidade de l�mpadas
necess�rias de acordo com a tabela anterior. Suponha quer ser�o utilizadas somente l�mpadas
de 60 wats. Ao final informar a quantidade total de l�mpadas necess�rias.
Estabele�a uma condi��o para finalizar a leitura dos dados de entrada. Exemplo:
a) uma classe inv�lida. Nesse caso, quando informada uma classe inv�lida, n�o devem ser
lidas as dimens�es do c�modo.
b) ler, inicialmente, a quantidade de c�modos.
Observa��o: Aten��o o n�mero total de l�mpadas informado dever� ser inteiro. E lembre-se
que cada c�modo utilizar� um n�mero inteiro de l�mpadas.*/

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
