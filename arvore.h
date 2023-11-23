// binary_search_tree.h

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct TreeNode {
    int chave;                // Valor do nó
    struct TreeNode* left;  // Ponteiro para o filho esquerdo
    struct TreeNode* right; // Ponteiro para o filho direito
};

struct TreeNode* insert(struct TreeNode* root, int chave);
struct TreeNode* removeNode(struct TreeNode* root, int chave);
int search(struct TreeNode* root, int chave);
void inorderTraversal(struct TreeNode* root);
void preorderTraversal(struct TreeNode* root);
void postorderTraversal(struct TreeNode* root);
int findMin(struct TreeNode* root);
int findMax(struct TreeNode* root);
void freeTree(struct TreeNode* root);

#endif // BINARY_SEARCH_TREE_H
