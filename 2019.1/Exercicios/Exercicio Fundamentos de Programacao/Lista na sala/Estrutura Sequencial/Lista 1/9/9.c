/*Ler dois valores A e B e efetue a troca do conte�do das duas vari�veis lidas, de forma
que a vari�vel A passe a ter o valor de B e a vari�vel B o valor de A. Mostre o conte�do
das vari�veis antes e depois da troca. */

# include <stdio.h>

int main(void)

{
    int A, B, aux; //aux far� o papel de copo vazio

    printf("Informe um valor: ");
    scanf("%d",&A);
    printf("Informe outro valor: ");
    scanf("%d",&B);

    printf("\nAntes da troca \n");
    printf("A: %d e B: %d\n",A,B);

    aux = A;
    A = B;
    B = aux;

    printf("\nDepois da troca\n");
    printf("A: %d e B: %d\n",A,B);
}
