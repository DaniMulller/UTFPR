typedef struct matriz Matriz;
typedef struct celula Celula;
typedef struct item Item;
typedef struct hash Hash;
//#define TABLESIZE 50

Matriz * inicializa_matriz(int lin, int col);
void libera_matriz(Matriz *m);
void adiciona_celula(Matriz *m, int lin, int col, float valor);
void imprime_matriz(Matriz *m);
float busca_valor(Matriz *m, int lin, int col);
Hash * cria_tabela(int tam);
void libera_tabela(Hash *h,int tam);
Item * cadastra_item(int chave);
void imprime_item(Item *item);
int verifica_tabela_cheia(Hash *h);
int hashing_divisao(int chave,int tam);
void imprime_tabela(Hash *h,int tam);
void insere_tratamento_lista_encadeada(Hash *h, Item *item,int tam);
Item * busca_tratamento_lista_encadeada(Hash *h, int chave,int tam);
void remove_tratamento_lista_encadeada(Hash *h, int chave,int tam) ;
Item * cadastra_item(int chave);
void imprime_item(Item *item);
