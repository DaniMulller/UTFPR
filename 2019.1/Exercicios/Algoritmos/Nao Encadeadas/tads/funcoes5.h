typedef struct fracao Fracao;

Fracao * criaFracao(int x,int y);
void liberaFracao(Fracao *p);
Fracao * somaFracao(Fracao *p,Fracao *q);
Fracao * diminuirFracao(Fracao *p,Fracao *q);
Fracao * multiplicarFracao(Fracao *p,Fracao *q);
Fracao * dividirFracao(Fracao *p,Fracao *q);
void imprimeFracao(Fracao *p);
