// main.c

#include <stdio.h>
#include "arvore.h"

int main() {
    struct TreeNode* root = NULL;

    // Teste de inserção
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Teste de remoção
    printf("Inorder traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");

    root = removeNode(root, 20);

    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Teste de busca
    int keyToSearch = 40;
    if (search(root, keyToSearch)) {
        printf("%d found in the tree.\n", keyToSearch);
    } else {
        printf("%d not found in the tree.\n", keyToSearch);
    }

    // Teste de percursos
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Teste de mínimo e máximo
    printf("Minimum value in the tree: %d\n", findMin(root));
    printf("Maximum value in the tree: %d\n", findMax(root));

    // Liberação de memória
    freeTree(root);

    return 0;
}
