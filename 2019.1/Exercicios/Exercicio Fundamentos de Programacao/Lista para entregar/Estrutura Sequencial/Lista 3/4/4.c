/*Uma livraria fez uma promoção para pagamento à vista em que o comprador
pode escolher entre dois critérios de desconto:
1) 0,25 por livro + 7,50 fixo
2) 0,5 por livro + 2,5 fixo
Fazer um programa em que o usuário digita a quantidade de livros que deseja comprar e o
programa informa qual é a melhor opção de desconto.*/

# include <stdio.h>

int main(void)

{
    int livros;

    printf("Informe quantos livros deseja comprar: ");
    scanf("%d",&livros);

    if (livros < 20)
    {
        printf("\nA opcao 2 e a melhor escolha\n");
    }
    else if (livros > 20)
    {
        printf("\nA opcao 1 e a melhor escolha\n");
    }
    else
    {
        printf("\nCom 20 livros nao faz diferenca a escolha\n");
    }
}
