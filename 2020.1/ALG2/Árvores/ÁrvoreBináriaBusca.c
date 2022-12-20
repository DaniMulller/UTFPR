#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
  int item;
  Node *left;
  Node *right;
};

Node* create(int value){
  Node *tree = (Node*)malloc(sizeof(Node));
  tree->left = NULL;
  tree->right = NULL;
  tree->item = value;
  return tree;
}

int release(Node* tree){
  if(tree!=NULL){
    free(tree);
    return 1;
  }
  return 0;
}

Node* search(Node* tree,int value){
  if(tree!=NULL){
    if(tree->item == value){
      return tree;
    }
    else if(tree->item < value){
      return search(tree->left,value);
    }
    else{
      return search(tree->right,value);
    }
  }
  else{
    return NULL;
  }
}

Node* insert(Node* tree,int value){
  if(tree==NULL){
    tree = create(value);
  }
  else if(value < tree->item){
    tree->left = insert(tree->left,value);
  }
  else{
    tree->right = insert(tree->right,value);
  }
  return tree;
}

int delete(Node* tree,int value){
  Node *aux,*auxP,*auxF;

  if(tree!=NULL){
    if(value < tree->item){
      delete(tree->left,value);
    }
    else if(value > tree->item){
      delete(tree->right,value);
    }
    else{
      aux=tree;
      if(aux->left == NULL){
        tree = tree->right;
      }
      else if(aux->right == NULL){
        tree = tree->left;
      }
      else{
        auxP = aux->right;
        auxF = auxP;
        while(auxF->left!=NULL){
          auxP = auxF;
          auxF = auxF->left;
        }
        auxP->left = auxF->right;
        auxF->left = aux->left;
        auxF->right = aux->right;
        tree = auxF;
      }
      free(aux);
      return 1;
    }
  }
  return 0;
}

void leaves(Node* tree){
  if(tree!=NULL && tree->left==NULL && tree->right==NULL){
    printf(" %d",tree->item);
  }
  else if(tree!=NULL){
    leaves(tree->left);
    leaves(tree->right);
  }
}

int maior(int a,int b){
  if(a>b){
    return a;
  }
  return b;
}

int height(Node* tree){
  if(tree==NULL){
    return 0;
  }
  return 1+maior(height(tree->left),height(tree->right));
}

//se a diferença de altura for <-1(direita maior que esquerda)
//ou >+1(esquerda maior que direita), está desbalanceada
int balanceada(Node* tree){
  if(tree==NULL){
    return 1; //balanceada
  }
  else if((height(tree->left)-height(tree->right))>1||(height(tree->left)-height(tree->right))<-1){
      return 0; //desbalanceada
  }
  else{
    return 1;
  }
}

int main(void){
  int n,i,value=0;
  Node *tree = NULL;
  scanf(" %d",&n);
  for(i=0;i<n;i++){
    scanf(" %d",&value);
    tree = insert(tree,value);
  }
  return 0;
}
