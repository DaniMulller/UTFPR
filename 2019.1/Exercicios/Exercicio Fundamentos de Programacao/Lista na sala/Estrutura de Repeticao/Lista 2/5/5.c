/*O que faz o algoritmo a seguir?
declare valor, maior como inteiro
leia valor
maior ← valor
para j = 0 até j < 4 passo 1
leia valor
se valor > maior então
maior ← valor
fim-se
fim-para
escreva maior
Implemente esse algoritmo utilizando a linguagem C.
Desafio) Como alterar o algoritmo para não ser necessário fazer uma leitura do valor antes da
estrutura para … até?*/

# include <stdio.h>

int main(void)

{
    int num,j,maior;

    printf("Informe um numero: ");
    scanf("%d",&num);

    maior = num;

    for (j=0;j<4;j++)
    {
        printf("Informe um numero: ");
        scanf("%d",&num);

        if (num>maior)
        {
            maior = num;
        }
    }
    printf("\nMaior e igual a: %d\n",maior);
}
