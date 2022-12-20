/*Ler dois números inteiros (armazená-los em variáveis do tipo int). Dividir o primeiro
desses números pelo segundo, obter e mostrar separadamente (Não utilizar funções
matemáticas prontas):
a) a parte inteira do número resultante.
b) a parte decimal desse número resultante com três casas decimais.
c) a parte decimal como um número inteiro de três dígitos.
Por exemplo:
Lidos: 20 e 3
Parte inteira: 6
Parte decimal: 0.666 ou 0.667 (se mostrado com arredondamento estatístico)
Parte decimal como um inteiro de dois dígitos: 666*/

# include <stdio.h>

int main(void)

{
    int num1, num2, divisao;
    float decimal, divisao_float;

    printf("Informe um numero: ");
    scanf("%d",&num1);
    printf("Informe outro numero: ");
    scanf("%d",&num2);

    divisao = num1/num2;
    divisao_float = (float)(num1/num2);
    decimal = divisao_float - divisao;

    printf("\nLidos %d e %d\n",num1,num2);
    printf("\nParte inteira: %d\n",divisao);
    printf("\nParte decimal: %.3f\n",decimal);
    printf("\nParte decimal como um numero inteiro de tres digitos: %d\n",decimal*100);
}
