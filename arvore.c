// binary_buscar_arvore.c

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct NoArvore* adicionar(struct NoArvore* raiz, int chave) {
    if (raiz == NULL) {
        struct NoArvore* novoNo = (struct NoArvore*)malloc(sizeof(struct NoArvore));
        novoNo->chave = chave;
        novoNo->esquerda = novoNo->direita = NULL;
        return novoNo;
    }
    if (chave < raiz->chave) {
        raiz->esquerda = adicionar(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = adicionar(raiz->direita, chave);
    }

    return raiz;
}

struct NoArvore* remover(struct NoArvore* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }

    if (chave < raiz->chave) {
        raiz->esquerda = remover(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = remover(raiz->direita, chave);
    } else {
        if (raiz->esquerda == NULL) {
            struct NoArvore* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct NoArvore* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        struct NoArvore* temp = raiz->direita;
        while (temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        raiz->chave = temp->chave;
        raiz->direita = remover(raiz->direita, temp->chave);
    }

    return raiz;
}

int buscar(struct NoArvore* raiz, int chave) {
    if (raiz == NULL) {
        return 0;
    }

    if (chave == raiz->chave) {
        return 1;
    } else if (chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    } else {
        return buscar(raiz->direita, chave);
    }
}

void emOrdem(struct NoArvore* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        emOrdem(raiz->direita);
    }
}

void preOrdem(struct NoArvore* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(struct NoArvore* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

int valorMin(struct NoArvore* raiz) {
    if (raiz == NULL) {
        fprintf(stderr, "Empty arvore\n");
        exit(EXIT_FAILURE);
    }

    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }

    return raiz->chave;
}

int valorMax(struct NoArvore* raiz) {
    if (raiz == NULL) {
        fprintf(stderr, "Empty arvore\n");
        exit(EXIT_FAILURE);
    }

    while (raiz->direita != NULL) {
        raiz = raiz->direita;
    }

    return raiz->chave;
}

void liberarArvore(struct NoArvore** raiz) {
    if (*raiz != NULL) {
        liberarArvore(&((*raiz)->esquerda));
        liberarArvore(&((*raiz)->direita));
        free(*raiz);
        *raiz = NULL;  
    }
}

