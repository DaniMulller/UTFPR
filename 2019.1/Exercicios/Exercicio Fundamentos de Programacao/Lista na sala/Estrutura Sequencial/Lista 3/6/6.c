/*Fa�a um programa que calcule a quantidade necess�ria de latas de tinta e o custo para
pintar um tanque cil�ndrico. Apresentar o custo com duas casas decimais. Se para a
quantidade de latas de tinta for obtido um resultado fracion�rio arredondar o n�mero para o
pr�ximo inteiro. Por exemplo: 5.2 apresentar 6 latas de tinta. Uma lata de tinta
cont�m 3,6 litros e que cada litro de tinta � suficiente para pintar tr�s metros quadrados.
Observa��o: a fun��o
int ceil (float num)
 faz arredondamento do n�mero para cima, ou
seja, para o pr�ximo inteiro.  � necess�rio incluir essa biblioteca com # include <math.h>
Exemplo de uso:
Valor = ceil(Vari�vel);*/

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
