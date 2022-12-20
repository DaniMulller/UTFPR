/* Fazer um programa que leia um número de até três dígitos (considere que será fornecido
um número de até 3 dígitos), calcule e imprima a soma dos seus dígitos. Exemplo: 123 = 1
+ 2 + 3 = 6.*/

# include <stdio.h>

int main(void)

{
    int num;

    printf("Informe um numero de ate 3 digitos: ");
    scanf("%d",&num);

    printf("\nA soma sera: %d + %d + %d = %d\n",(num/100),(num%100)/10,(num%10),(num/100)+(num%100)/10+(num%10));
}
