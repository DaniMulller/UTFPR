# include <stdio.h>

int main(void)

{
    float raio;
    float altura;
    float volume;

    printf("Informe a medida do raio em metros: ");
    scanf("%f",&raio);
    printf("Informe a medida da altura em metros: ");
    scanf("%f",&altura);

    volume = 2 * 3.14 * raio * altura;

    printf("\nO volume desse cilindro e de %.2f metros cubicos\n",volume);
}
