#define MAXTAM 10
typedef struct item Item;
typedef struct lista Lista;
void adicionar_item(Lista *l,int indice,int chave);
Lista *cria_lista_vazia();
void imprime_lista(Lista *l);
int verifica_lista_vazia(Lista *l);
int verifica_lista_cheia(Lista *l);
void adiciona_item_fim_lista(Lista *l, int chave);
