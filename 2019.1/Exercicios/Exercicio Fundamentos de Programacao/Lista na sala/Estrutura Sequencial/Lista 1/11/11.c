/*
Resolva as seguintes expressões matemáticas. X e Y são valores fornecidos pelo
usuário. Calcule e mostre o resultado de cada expressão. Atenção para os resultados que podem ser valores float e para a prioridade dos
operadores.Primeiro linearizar as expressões depois implementar o algoritmo para calcular o
resultado. */

# include <stdio.h>
# include <math.h>

int main(void)

{
    float valorX;
    float valorY;
    float numero1, numero2, numero3, numero4, numero5, numero5B;

    printf("Informe o valor de X: ");
    scanf("%f",&valorX);
    printf("Informe o valor de Y: ");
    scanf("%f",&valorY);

    numero1 = (valorX + valorY)/2 * (valorX*valorX);
    printf("\nO valor da questao A e de: %.2f ",numero1);
    numero2 = (valorX+valorY)/(valorX-valorY);
    printf("\nO valor da questao B e de: %.2f ",numero2);
    numero3 = ((valorX*valorX) + (valorY*valorY*valorY))/2;
    printf("\nO valor da questao C e de: %.2f ",numero3);
    numero4 = (valorX*valorX*valorX)/(valorX*valorX);
    printf("\nO valor da questao D e de: %.2f ",numero4);
    numero5 = ((int)valorX/(int)valorY);
    printf("\nO valor da questao E e de: %.0f ",numero5);
    numero5B = ((int)valorX/3);
    printf("\nO valor da questao E.2 e de: %.0f\n ",numero5B);
}
