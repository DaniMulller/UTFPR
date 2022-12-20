# include <stdio.h>

int main(void)

{
    float raio;
    float circunferencia;

    printf("Informe o raio em metros: ");
    scanf("%f",&raio);

    circunferencia = 2 * 3,14 * raio;

    printf("\nA circunferencia do circulo e de %.2f metros\n",circunferencia);
}
