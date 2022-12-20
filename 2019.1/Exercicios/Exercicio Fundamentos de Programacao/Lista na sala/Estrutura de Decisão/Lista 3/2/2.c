/*Ler dois n�meros inteiros e informar:
a) Se ambos s�o divis�veis por 5.
b) Se pelo menos um deles � divis�vel por 5.
c) Se ambos s�o pares.
d) Se pelo menos um deles � �mpar.
Esses quatro itens podem ser realizados utilizando uma �nica estrutura if else if
encadeada? Por qu�?*/

# include <stdio.h>

int main(void)

{
    int num1, num2;

    printf("Informe um numero: ");
    scanf("%d",&num1);
    printf("Informe outro numero: ");
    scanf("%d",&num2);

    if (num1%5==0 && num2%5==0)
    {
        printf("\nOs dois sao divisiveis por 5\n");
    }
    else if (num1%5==0 && num2%5!=0 || num1%5!=0 && num2%5==0)
    {
        printf("\nPelo menos um deles e divisivel por 5\n");
    }
    else if (num1%2==0 && num2%2==0)
    {
        printf("\nOs dois sao pares\n");
    }
    else if (num1%2!=0 && num2%2==0 || num1%2==0 && num2%2!=0)
    {
        printf("\nPelo menos um dos dois e impar\n");
    }
    else
    {
        printf("\nOs numeros nao sao pares e nem divisiveis por 5");
    }
}
