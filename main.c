#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void imprimirValores(struct NoArvore* raiz) {
    if (raiz != NULL) {
        imprimirValores(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirValores(raiz->direita);
    }
}

int main() {
    struct NoArvore* raiz = NULL;

    raiz = adicionar(raiz, 50);
    adicionar(raiz, 30);
    adicionar(raiz, 20);
    adicionar(raiz, 25);
    adicionar(raiz, 70);
    adicionar(raiz, 60);
    adicionar(raiz, 80);
    adicionar(raiz, 234);
    adicionar(raiz, 2321);

    printf("Valores depois da adicao: ");
    imprimirValores(raiz);
    printf("\n");

    printf("Valores em ordem: ");
    emOrdem(raiz);
    printf("\n");

    raiz = remover(raiz, 20);

    printf("Valores em ordem depois da remocao: ");
    emOrdem(raiz);
    printf("\n");

    int buscarNumero = 40;
    if (buscar(raiz, buscarNumero)) {
        printf("%d foi achado.\n", buscarNumero);
    } else {
        printf("%d nao foi achado.\n", buscarNumero);
    }

    printf("Inorder traversal: ");
    emOrdem(raiz);
    printf("\n");

    printf("Preorder traversal: ");
    preOrdem(raiz);
    printf("\n");

    printf("Postorder traversal: ");
    posOrdem(raiz);
    printf("\n");

    printf("Minimum value in the arvore: %d\n", valorMin(raiz));
    printf("Maximum value in the arvore: %d\n", valorMax(raiz));

    liberarArvore(&raiz);

    if (raiz == NULL) {
        printf("A árvore foi liberada com sucesso.\n");
    } else {
        printf("Erro ao liberar a árvore.\n");
    }

    return 0;
}
