/* Ler um número e imprimir todos os pares entre 2 e o número lido. Imprimir a soma
dos pares, o produto dos ímpares e divisíveis por 9 e a média de todos os números do
intervalo. Validar para que não seja realizada divisão por zero.*/

# include <stdio.h>

int main(void)

{
    int i;
    int num;
    int soma_pares=0; //inicializar a variavel com 0
    int produto_impares=1; //inicializar a variavel com 1
    int soma_todos=0;
    int qtde=0;
    float media;

    printf("Informe o valor extremo: ");
    scanf("%d",&num);

    for (i=2; i<=num ; i++ )
    {
        if ( i%2 == 0)
        {
            printf("%d\t",i);
            soma_pares = soma_pares + i;
        }
        else if ( i%9 == 0)
        {
            produto_impares = produto_impares * i;
        }
        soma_todos = soma_todos + i;
        qtde++; // qtde = qtde + 1
    }//fim for
    if (qtde > 0)
    {
        media = (float)soma_todos/qtde;
        printf("\n\nMedia da soma: %.2f\n",media);
    }
    printf("\nSoma dos pares: %d\n",soma_pares);
    if (produto_impares > 1)
    {
        printf("\nProduto dos impares e divisivel por 9: %d\n",produto_impares);
    }
}
