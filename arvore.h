// arvore.h

#ifndef ARVORE_H
#define ARVORE_H

struct NoArvore {
    int chave;                 // Valor do nó
    struct NoArvore* esquerda;  // Ponteiro para o filho esquerdo
    struct NoArvore* direita;   // Ponteiro para o filho direito
};

struct NoArvore* adicionar(struct NoArvore* raiz, int chave);
struct NoArvore* remover(struct NoArvore* raiz, int chave);
int buscar(struct NoArvore* raiz, int chave);
void emOrdem(struct NoArvore* raiz);
void preOrdem(struct NoArvore* raiz);
void posOrdem(struct NoArvore* raiz);
int valorMin(struct NoArvore* raiz);
int valorMax(struct NoArvore* raiz);
void liberarArvore(struct NoArvore** raiz);

#endif // ARVORE_H
