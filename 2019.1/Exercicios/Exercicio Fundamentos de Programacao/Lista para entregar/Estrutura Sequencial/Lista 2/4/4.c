/*Ler um n�mero com at� 4 d�gitos. Separar os d�gitos desse n�mero e mostr�-los em
linhas distintas.
Por exemplo:
Lido o n�mero: 1234
Mostrar da seguinte forma:
1 � o primeiro d�gito.
2 � o segundo d�gito.
3 � o terceiro d�gito.
4 � o quarto d�gito.*/

# include <stdio.h>

int main(void)

{
    int numero, num1, num2, num3, num4;

    printf("Informe um numero de ate 4 digitos: ");
    scanf("%d",&numero);

    printf("\nLido o numero: %d\n",numero);

    num1 = (numero/1000);
    printf("\n%d e o primeiro nunmero\n",num1);

    num2 = (numero/100);
    printf("\n%d e o segundo numero\n",num2-(num1*10));

    num3 = (numero/10);
    printf("\n%d e o terceiro numero\n",num3 - (num2*10));

    num4 = (numero/1);
    printf("\n%d e o quarto numero\n",num4 - (num3*10));
}
