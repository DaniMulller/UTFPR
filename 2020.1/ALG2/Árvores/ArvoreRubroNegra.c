#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
  int key;
  int color;
  Node *father;
  Node *left;
  Node *right;
};

Node* create(int key){
  Node *tree = (Node*)malloc(sizeof(Node));
  tree->key = key;
  tree->father = NULL;
  tree->left = NULL;
  tree->right = NULL;
  tree->color = 0; //red
  return tree;
}

int release(Node *tree){
  if(tree!=NULL){
    free(tree);
    return 1;
  }
  return 0;
}

Node* search(Node *tree, int key){
  if(tree!=NULL){
    if(key==tree->key){
      return tree;
    }
    else if(key<tree->key){
      return search(tree->left,key);
    }
    else{
      return search(tree->right,key);
    }
  }
  return NULL;
}

void inorder(Node *tree){
  if (tree != NULL){
    inorder(tree->left);
    printf("%d %d\t", tree->key,tree->color);
    inorder(tree->right);
  }
}


Node* get_grandpa(Node *tree){
  Node *grandpa = NULL;
  if(tree!=NULL && tree->father!=NULL){
    grandpa = tree->father->father;
  }
  return grandpa;
}

Node* get_uncle(Node *tree){
  Node *uncle = NULL;
  if(tree!=NULL && tree->father!=NULL){
    if(tree->father->father->left == tree->father){
      uncle = tree->father->father->right;
    }
    else{
      uncle = tree->father->father->left;
    }
  }
  return uncle;
}

Node* right_rotation(Node *tree){
  Node *pai = tree->father; //pai de tree
  Node *avo = pai->father; //avo de tree

  avo->left = pai->right;
  pai->right = avo;

  if(avo->father != NULL){
    if(avo->father->left==avo){
        avo->father->left = pai;
    }
    else{
      avo->father->right = pai;
    }
  }
  pai->father = avo->father;
  avo->father = pai;

  return pai;
}

Node* left_rotation(Node *tree){
  Node *pai = tree->father; //pai de tree
  Node *avo = pai->father; //avo de tree

  avo->right = pai->left;
  pai->left = avo;

  if(avo->father != NULL){
    if(avo->father->right==avo){
        avo->father->right = pai;
    }
    else{
      avo->father->left = pai;
    }
  }
  pai->father = avo->father;
  avo->father = pai;

  return pai;
}

Node* right_left_rotation(Node *tree){
  Node *pai = tree->father; //pai de tree
  Node *avo = pai->father; //avo de tree

 pai->left = tree->right;
 tree->right = pai;
 if (avo->left == pai){
   avo->left = tree;
 }
 else{
   avo->right = tree;
 }
 tree->father = pai->father;
 pai->father = tree;

  //left rotation
  return left_rotation(pai);
}

Node* left_right_rotation(Node *tree){
  Node *pai = tree->father; //pai de tree
  Node *avo = pai->father; //avo de tree

  pai->right = tree->left;
  tree->left = pai;
  if(avo->left == pai){
    avo->left = tree;
  }
  else{
    avo->right = tree;
  }
  tree->father = pai->father;
  pai->father = tree;

  //right rotation
  return right_rotation(pai);
}

Node* balance(Node *tree){
  Node *pai,*tio;

  if(tree->father==NULL){ //caso 1, é raiz
    tree->color = 1; //recolorir de preto
  }
  else{
    pai = tree->father;
    if(pai->color==0){
      tio = get_uncle(tree);

      if(tio!=NULL && tio->color==0){ //caso 2, pai e tio são vermelhos
        pai->color = tio->color = 1;
        tree = get_grandpa(tree);

        if(tree->father != NULL){
          tree->color = 0;
        }
      }
      else{ //caso 3
        if(pai->left == tree){
          if(pai->father->right == pai){
            tree = right_left_rotation(tree); //caso 3c
          }
          else{
            tree = right_rotation(tree); //caso 3a
          }
        }
        else{ //caso 3
          if(pai->father->left == pai){
            tree = left_right_rotation(tree); //caso 3d
          }
          else{
            tree = left_rotation(tree); //caso 3b
          }
        }
      tree->color = 1;
      if(tree->left != NULL){
        tree->left->color = 0;
      }
      if(tree->right != NULL){
        tree->right->color = 0;
      }
     }
    }
  }
  return tree;
}

Node* insert(Node *tree,int key){
  Node *auxP,*auxF;

  if(tree==NULL){
    tree = create(key);
    tree->color = 1;
  }
  else{
    auxP = auxF = tree;

    while(auxF!=NULL){
      auxP = auxF;
      if(key<auxF->key){
        auxF = auxF->left;
      }
      else{
        auxF = auxF->right;
      }
    }

    auxF = create(key);
    auxF->color = 0;
    auxF->key = key;
    auxF->father = auxP;

    if(auxF->key < auxP->key){
      auxP->left = auxF;
    }
    else{
      auxP->right = auxF;
    }

    while((auxF->father!=NULL) && (auxF->color==0) && (auxF->father->color==0)){
      auxF = balance(auxF);
    }

    while(auxF->father != NULL){
      auxF = auxF->father;
    }

    return auxF;
  }

  return tree;
}

int height(Node* tree){
  int aux=0;
  while(tree!=NULL){
    if(tree->color == 1){ //se for preto +1
      aux=aux+1;
    }
    tree = tree->left;
  }
  return aux;
}

int main(void){
  Node *tree = NULL;
  int nos,i,key;

  scanf(" %d",&nos);

  for(i=0;i<nos;i++){
    scanf(" %d",&key);
    tree = insert(tree,key);
  }

  printf("%d\n",height(tree));

  return 0;
}
