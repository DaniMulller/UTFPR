/*Fazer um algoritmo que leia um valor float que representa o sal�rio de uma pessoa.
Apresente separadamente os reais (parte inteira) e os centavos (parte decimal).
Observa��o: apresentar os centavos como inteiro de dois d�gitos (98 em vez de 0.98)
Exemplo:
Sal�rio informado: 1345.98
Reais: 1345
Centavos: 98*/

# include <stdio.h>

int main(void)

{
    int salario_int, centavos;
    float salario_float;

    printf("Informe o salario: ");
    scanf("%f",&salario_float);

    printf("\nSalario Informado: %.2f R$\n",salario_float);
    printf("\nReais: %d\n",(int)salario_float);

    salario_int = salario_float;
    centavos = (salario_float - salario_int)*100;
    printf("\nCentavos: %d\n",centavos);
}

