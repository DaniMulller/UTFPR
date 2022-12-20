/* Elaborar um algoritmo para ler um número que representa uma senha, verificar se a
senha está correta ou não, comparando-a com 12345 e informar "Acesso autorizado" ou
"Acesso negado", conforme o caso. */

# include <stdio.h>

int main(void)

{
    int senha;

    printf("Informe a senha numerica de 5 digitos: ");
    scanf("%d",&senha);

    if (senha != 12345)
    {
        printf("\nAcesso negado!\n");
    }
    else
    {
        printf("\nAcesso autorizado!\n");
    }
}

