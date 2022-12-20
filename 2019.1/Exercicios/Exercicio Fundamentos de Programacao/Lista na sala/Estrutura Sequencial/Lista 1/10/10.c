/*Um eletricista precisa comprar fio que ir� passar pela diagonal de uma casa de
formato retangular. Como ele n�o tem condi��es de medir a diagonal com precis�o, uma
solu��o alternativa � medir os lados da casa. A diagonal pode ser calculada a partir dos
lados   pelo   Teorema   de   Pit�goras. Fa�a   um   algoritmo   que   calcule   a
quantidade m�nima necess�ria de fio a ser comprada. Apresente tamb�m a quantidade
m�nima em metros  inteiros. Por exemplo: resultado do c�lculo 18.35, apresentar  19
metros.*/

# include <stdio.h> //fun��es como printf() e scanf()
# include <math.h> //fun��es matem�ticas

int main(void)

{
    float ladoA, ladoB, hipo;
    int metros;

    printf("Informe o valor do lado A: ");
    scanf("%f",&ladoA);
    printf("Informe o valor do lado B: ");
    scanf("%f",&ladoB);

    hipo = sqrt((ladoA*ladoA) + (ladoB*ladoB)); //sqrt calcula a ra�z quadrada e devolve a ra�z calculada
    metros = hipo + 0.999999;
    //metros = ceil(hipo); arredonda para o proximo inteiro

    printf("\nSerao necessarios %d metros de fio\n",metros);
}
