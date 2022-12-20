/*Ler dois valores A e B e efetue a troca do conteúdo das duas variáveis lidas, de forma
que a variável A passe a ter o valor de B e a variável B o valor de A. Mostre o conteúdo
das variáveis antes e depois da troca. */

# include <stdio.h>

int main(void)

{
    int A, B, aux; //aux fará o papel de copo vazio

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
