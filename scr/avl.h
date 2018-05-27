#ifndef AVL_H
#define AVL_H

typedef struct Treeno {
	int info;
	struct Treeno *left;
	struct Treeno *right;
} node;

void newtree(node **T);
node* newNode(int x);
node* insert(node *T, int x);
int fb(node *T);
int height(node *T);
node* rotacao_Direita(node *T);
node* rotacao_Esquerda(node *T);
node* balance(node *T);
void emOrdem(node *T);
void preOrdem(node *T);
void posOrdem(node *T);
node *pesq_Menor(node **T);
int remove_node(node **T, int x);

#endif