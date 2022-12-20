/*Leia um valor float que representa o troco a ser fornecido por um caixa. Separe a parte
inteira (reais) da parte decimal (centavos) e apresente na forma: 123 reais e 18 centavos.*/

# include <stdio.h>

int main(void)

{
    float troco, valor, recebido;
    int troco_reais, troco_int, troco_centavos;

    printf("Informe o valor a ser pago: ");
    scanf("%f",&valor);
    printf("Informe o valor recebido: ");
    scanf("%f",&recebido);

    troco = recebido - valor;
    troco_reais = troco;
    troco_int = troco ;
    troco_centavos = (int)((troco - troco_int)*100);

    printf("\nO troco deve ser de: %d reais e %d centavos\n",troco_reais,troco_centavos);
}
