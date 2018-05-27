#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void newtree(node **T) {
    *T = NULL;
}

node* rotacao_Direita(node *T) {
    node *q;
    q = T->left;
    T->left = q->right;
    q->right = T;

    return q;
}

node* rotacao_Esquerda(node *T) {
    node *q;
    q = T->right;
    T->right = q->left;
    q->left = T;

    return q;
}

node* newNode(int x) {
    node *T = malloc(sizeof(node));
    T->info = x;
    T->left = NULL;
    T->right = NULL;

    return T;
}

node* insert(node *T, int x) {
    if(T == NULL)
        return newNode(x);

    if(x < T->info)
        T->left = insert(T->left,x);
    else
        T->right = insert(T->right,x);

   return balance(T);
}

node* balance(node *T) {

	int fatbal = fb(T);

    if(fatbal == 2) {
        if(fb(T->right) < 0)
            T->right = rotacao_Direita(T->right);

        return rotacao_Esquerda(T);
    }
    if(fatbal == -2) {
        if(fb(T->left) > 0)
            T->left = rotacao_Esquerda(T->left);

        return rotacao_Direita(T);
    }
    return T;
}

int fb(node *T) {
    return (height(T->right) - height(T->left));
}

int height(node *T) {    
   if (T == NULL) 
      return -1;

	int he = height(T->left);
	int hd = height(T->right);

	return he < hd? hd+1 : he+1;
}

void emOrdem(node *T) {
    if(T != NULL) {
        emOrdem(T->left);
        printf("\n %d\n",T->info);
        emOrdem(T->right);
    }
}

void preOrdem(node *T) {
    if(T != NULL) {
	    printf("\n%d\n",T->info);
	    preOrdem(T->left);
	    preOrdem(T->right);
	}
}

void posOrdem(node *T) {
    if(T != NULL) {
	    posOrdem(T->left);
	    posOrdem(T->right);
	    printf("\n%d\n",T->info);
	}
}

int remove_node(node **T, int x) {
    node *p;
    int aux;
    if(*T == NULL)
        return 0;

    if(x < (*T)->info) {
        aux = remove_node(&((*T)->left),x);
        if ( aux != 1 ) 
            return 0;
        *T = balance((*T));
    }
    else {
        if(x > (*T)->info) {
            aux = remove_node(&((*T)->right),x);
            if ( aux != 1 ) 
                return 0;
            *T = balance(*T);
        }
        else {
            if (((*T)->left== NULL) && ((*T)->right == NULL)){
                p = (*T);
                free(p);
                (*T) = NULL;
                return (1);
            }
            else {
                if ((*T)->left == NULL) {
                    p = (*T);
                    (*T) = (*T)->right;
                    free(p);
                    return (1);
                }
                else {
                    if ((*T)->right == NULL) {
                        p = (*T);
                        (*T) = (*T)->left;
                        free((p));
                        return (1);
                    }
                    else {
                        p = pesq_Menor(&(*T)->left);
                        (*T)->info = p->info;
                        remove_node(&((*T)->left),p->info);
                    }
                }
            }
        }
    }
}

node *pesq_Menor(node **T) {
    if((*T)->left == NULL)
        return *T;

    pesq_Menor(&((*T)->left));
}