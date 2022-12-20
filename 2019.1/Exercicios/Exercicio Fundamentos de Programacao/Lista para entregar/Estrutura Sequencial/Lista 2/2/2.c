/*Faca um programa para calcular a quantidade de caixas de ladrilhos (cer�mica,
porcelanato...) necess�rios para revestir um determinado c�modo de uma resid�ncia. S�o
informados a altura e a largura total das paredes. Tamb�m � informada a altura e largura
da porta e das janelas e a quantidade de janelas. As janelas possuem o mesmo tamanho. O
usu�rio informa o tamanho de um ladrilho e a quantidade de ladrilhos por caixa. Indicar a
quantidade inteira para o n�mero de caixas necess�rios (arredondar o valor para o
pr�ximo inteiro).*/

# include <stdio.h>

int main(void)

{
    float altura, largura, altura_porta, largura_porta, altura_janela, largura_janela, ladrilho;
    int caixas;
    int janela, ladrilho_caixa;

    printf("Informe a altura da parede: ");
    scanf("%f",&altura);
    printf("Informe a largura da parede: ");
    scanf("%f",&largura);
    printf("Informe a altura da porta: ");
    scanf("%f",&altura_porta);
    printf("Informe a largura da porta: ");
    scanf("%f",&largura_porta);
    printf("Informe a altura da janela em metros: ");
    scanf("%f",&altura_janela);
    printf("Informe a largura da janela em metros: ");
    scanf("%f",&largura_janela);
    printf("Informe a quantidade de janelas: ");
    scanf("%d",&janela);
    printf("Informe o tamanho do ladrilho em metros quadrados: ");
    scanf("%f",&ladrilho);
    printf("Informe a quantidade de ladrilhos por caixa: ");
    scanf("%d",&ladrilho_caixa);

    caixas = ceil((((4*(altura*largura)) - ((janela*(altura_janela*largura_janela)) + (altura_porta*largura_porta)))/ladrilho)/ladrilho_caixa));

    printf("\nO numero de caixas devera ser de: %d\n",caixas);
}
