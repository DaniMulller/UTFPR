/* Fazer um programa que leia um n�mero de at� tr�s d�gitos (considere que ser� fornecido
um n�mero de at� 3 d�gitos), calcule e imprima a soma dos seus d�gitos. Exemplo: 123 = 1
+ 2 + 3 = 6.*/

# include <stdio.h>

int main(void)

{
    int num;

    printf("Informe um numero de ate 3 digitos: ");
    scanf("%d",&num);

    printf("\nA soma sera: %d + %d + %d = %d\n",(num/100),(num%100)/10,(num%10),(num/100)+(num%100)/10+(num%10));
}
