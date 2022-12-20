#include <stdio.h>
#include <stdlib.h>
#include "funcoes5.h"

typedef struct fracao Fracao;

struct fracao{
    int numerador;
    int denominador;
};

Fracao * criaFracao(int x,int y){
    Fracao *p = malloc(sizeof(Fracao));
    p->numerador = x;
    p->denominador = y;
    return p;
}

void liberaFracao(Fracao *p){
    free(p);
}

Fracao * somaFracao(Fracao *p,Fracao *q){
    Fracao *s = malloc(sizeof(Fracao));
    s->numerador = ((p->numerador*q->denominador)+(q->numerador*p->denominador));
    s->denominador = (p->denominador*q->denominador);

    return s;
}

Fracao * diminuirFracao(Fracao *p,Fracao *q){
    Fracao *s = malloc(sizeof(Fracao));
    s->numerador = ((p->numerador*q->denominador)-(q->numerador*p->denominador));
    s->denominador = (p->denominador*q->denominador);

    return s;
}

Fracao * multiplicarFracao(Fracao *p,Fracao *q){
    Fracao *s = malloc(sizeof(Fracao));
    s->numerador = (p->numerador*q->numerador);
    s->denominador = (p->denominador*q->denominador);

    return s;
}

Fracao * dividirFracao(Fracao *p,Fracao *q){
    Fracao *s = malloc(sizeof(Fracao));
    s->numerador = (p->numerador*q->denominador);
    s->denominador = (p->denominador*q->numerador);

    return s;
}

void imprimeFracao(Fracao *p){
    printf("%d/%d\n",p->numerador,p->denominador);
}
