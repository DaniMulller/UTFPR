/* Um ano � bissexto se for divis�vel por 4 e n�o for divis�vel por 100. Tamb�m s�o
bissextos os anos divis�veis por 400. Escreva um algoritmo que determina se um ano
informado pelo usu�rio � bissexto.
Observa��o: aten��o para a prioridade dos operadores (operador && tem prioridade mais
alta que o operador || ), utilizar par�nteses, se necess�rio, para alterar essa ordem de
prioridade.*/

# include <stdio.h>

int main(void)

{
    int ano;

    printf("Informe um ano: ");
    scanf("%d",&ano);

    if (((ano%4==0) && (ano%100!=0))|| (ano%400==0))
    {
        printf("\nE bissexto!\n");
    }
    else
    {
        printf("\nNao e ano bissexto!\n");
    }
}
