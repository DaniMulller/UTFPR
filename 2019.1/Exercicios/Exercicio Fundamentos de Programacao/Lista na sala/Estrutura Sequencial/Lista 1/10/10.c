/*Um eletricista precisa comprar fio que irá passar pela diagonal de uma casa de
formato retangular. Como ele não tem condições de medir a diagonal com precisão, uma
solução alternativa é medir os lados da casa. A diagonal pode ser calculada a partir dos
lados   pelo   Teorema   de   Pitágoras. Faça   um   algoritmo   que   calcule   a
quantidade mínima necessária de fio a ser comprada. Apresente também a quantidade
mínima em metros  inteiros. Por exemplo: resultado do cálculo 18.35, apresentar  19
metros.*/

# include <stdio.h> //funções como printf() e scanf()
# include <math.h> //funções matemáticas

int main(void)

{
    float ladoA, ladoB, hipo;
    int metros;

    printf("Informe o valor do lado A: ");
    scanf("%f",&ladoA);
    printf("Informe o valor do lado B: ");
    scanf("%f",&ladoB);

    hipo = sqrt((ladoA*ladoA) + (ladoB*ladoB)); //sqrt calcula a raíz quadrada e devolve a raíz calculada
    metros = hipo + 0.999999;
    //metros = ceil(hipo); arredonda para o proximo inteiro

    printf("\nSerao necessarios %d metros de fio\n",metros);
}
