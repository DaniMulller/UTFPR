/*Fazer um algoritmo para ler o salário de uma pessoa, o percentual de aumento e o
percentual de descontos. Os descontos incidem sobre o salário com aumento. Calcular o
novo salário e mostrá-lo na forma: Salário de 1234 reais e 65 centavos.

    a) Orientar o usuário na forma como deve ser informado o percentual (por exemplo,10 para 10% ou 0.1 para 10%), ou seja, como o programa espera que
     o valor sejainformado. Isso é importante para definir a fórmula.

    b) Cálculos de percentual podem ser realizados por meio de regras de três.*/

# include <stdio.h>

int main(void)

{
    float salario, aumento, descontos;
    float novo_salario;
    int reais, centavos;

    printf("Informe o salario: ");
    scanf("%f",&salario);
    printf("Informe o percentual de aumento(Ex. 5 para 5%%): ");
    scanf("%f",&aumento);
    printf("Informe o percentual de desconto(Ex. 10 para 10%%): ");
    scanf("%f",&descontos);

    novo_salario = salario + (salario*(aumento/100));
    novo_salario = novo_salario - (novo_salario*(descontos/100));
    reais = (int)novo_salario;
    centavos = (novo_salario - (int)novo_salario) * 100;

    printf("\nO novo salario sera de %d reais e %d centavos\n",reais, centavos);
}
