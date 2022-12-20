/*Faça um programa que calcule a quantidade necessária de latas de tinta e o custo para
pintar um tanque cilíndrico. Apresentar o custo com duas casas decimais. Se para a
quantidade de latas de tinta for obtido um resultado fracionário arredondar o número para o
próximo inteiro. Por exemplo: 5.2 apresentar 6 latas de tinta. Uma lata de tinta
contém 3,6 litros e que cada litro de tinta é suficiente para pintar três metros quadrados.
Observação: a função
int ceil (float num)
 faz arredondamento do número para cima, ou
seja, para o próximo inteiro.  É necessário incluir essa biblioteca com # include <math.h>
Exemplo de uso:
Valor = ceil(Variável);*/

# include <stdio.h>
# include <math.h>

int main(void)

{
    float altura, raio, custo, area_tanque;
    int latas;

    printf("Informe a altura do tanque em metros: ");
    scanf("%f",&altura);
    printf("Informe o raio do tanque em metros: ");
    scanf("%f",&raio);
    printf("Informe o custo da lata de tinta: ");
    scanf("%f",&custo);

    area_tanque = altura*(2*3.14*raio) + 2*(3.14*raio*raio);
    latas = ceil(area_tanque/3);

    printf("\nSerao utilizadas %d latas de tinta e serao gastos %.2f R$\n",latas,custo*latas);

}
