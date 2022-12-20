/*Um motorista de táxi deseja calcular o rendimento de seu carro na praça. Escreva um
programa para ler: a marcação do odômetro (Km) no início do dia, a marcação (Km) no
final do dia, o número de litros de combustível gasto, o valor do combustível por litro e o
valor total (R$) recebido dos passageiros. Calcular e escrever: a média do consumo em
Km/L e o lucro (líquido) do dia.*/

# include <stdio.h>

int main(void)

{
    float marcacao_inicio, marcacao_final, valor_litro, valor_recebido, media, lucro;
    int litros_gasto;

    printf("Informe o valor do litro de combustivel: ");
    scanf("%f",&valor_litro);
    printf("Informe o total de litros gasto: ");
    scanf("%d",&litros_gasto);
    printf("Informe a marcacao no inicio do dia em km: ");
    scanf("%f",&marcacao_inicio);
    printf("Informe a marcacao no final do dia em km: ");
    scanf("%f",&marcacao_final);
    printf("Informe o total recebido no dia: ");
    scanf("%f",&valor_recebido);

    media = (marcacao_final-marcacao_inicio)/litros_gasto;
    lucro = valor_recebido - (litros_gasto*valor_litro);

    printf("\nA media foi de %.2f litros/km e o Lucro total foi de %.2f R$\n",media,lucro);
}
