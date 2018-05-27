#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void main() {
    node *T;
    newtree(&T);

    T = insert(T, 20);
    T = insert(T, 30);
    T = insert(T, 10);
    T = insert(T, 40);
    T = insert(T, 50);

    printf("Arvore AVL - preOrdem\n");
    preOrdem(T);

    printf("\n\nArvore AVL - preOrdem depois de remover 10\n");
    remove_node(&T, 10);
    preOrdem(T);
}