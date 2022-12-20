# include <stdio.h>

int main(void)

{
    float volume;
    float altura;
    float comprimento;
    float largura;

    printf ("Informe a altura em metros: ");
    scanf ("%f",&altura);
    printf ("Informe o comprimento em metros: ");
    scanf ("%f",&comprimento);
    printf ("Informe a largura em metros: ");
    scanf ("%f",&largura);

    volume = altura * comprimento * largura;

    printf ("\nO volume dessa caixa e de %.2f metros cubicos\n"),volume;
}
