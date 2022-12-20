/*Ler um n�mero e utilizando uma estrutura if else if  else if... (obrigatoriamente
encadeada) informar se ele �:

a) divis�vel somente por 5, por 3 ou por 2;
Exemplo: 25 divis�vel somente por 5

b) n�o � divis�vel por nenhum destes;
Exemplo: 7 n�o � divis�vel por 5, 3 ou 2;

c) se � divis�vel por todos eles;
Exemplo: 30 � divis�vel por 2, 3 e 5.

d) se ele � divis�vel somente por 5 e por 3; por 5 e por 2; ou por 3 e por 2

Exemplo: 15 � divis�vel somente por 3 e por 5.
Exemplo: 10 � divis�vel somente por 5 e por 2.
Exemplo: 6 � divis�vel somente por 3 e por 2*/

# include <stdio.h>

int main(void)

{
    int num;

    printf("Informe um numero: ");
    scanf("%d",&num);

    if (num>0)
    {
        if (num%5==0 || num%3==0 || num%2==0)
        {
            if (num%5==0 && num%3!=0 && num%2!=0)
            {
                 printf("\nO numero e divisivel somente por 5\n");
            }
            else if (num%5!=0 && num%3==0 && num%2!=0)
            {
                 printf("\nO numero e divisivel somente por 3\n");
            }
            else if (num%5!=0 && num%3!=0 && num%2==0)
            {
                 printf("\nO numero e divisivel somente por 2\n");
            }
            else if (num%5==0 && num%3==0 && num%2==0)
            {
                printf("\nO numero e divisivel por 5, 3 e 2\n");
            }
            else if (num%5==0 && num%3==0)
            {
                printf("\nO numero e divisivel por 5 e 3\n");
            }
            else if (num%5==0 && num%2==0)
            {
                printf("\nO numero e divisivel por 5 e 2\n");
            }
            else if (num%3==0 && num%2==0)
            {
                printf("\nO numero e divisivel por 3 e 2\n");
            }
        }
        else
        {
            printf("\nO numero nao e divisivel por 5 ou por 3 ou por 2\n");
        }
    }
    else
    {
        printf("\nInforme um numero valido!\n");
    }


}
