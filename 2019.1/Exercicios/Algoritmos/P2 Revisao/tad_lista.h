typedef struct lista Lista;
typedef struct celula Celula;
typedef struct item Item;

Lista *cria_lista_vazia();
int verifica_lista_vazia(Lista *l);
void insere_inicio(Lista *l,int chave);
void insere_final(Lista *l,int chave);
void insere_meio(Lista *l,int chave_anterior,int chave);
void imprime(Lista *l);
Celula *busca_chave(Lista *l,int chave);
