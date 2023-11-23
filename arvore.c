// binary_search_tree.c

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct TreeNode* insert(struct TreeNode* root, int chave) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->chave = chave;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (chave < root->chave) {
        root->left = insert(root->left, chave);
    } else if (chave > root->chave) {
        root->right = insert(root->right, chave);
    }

    return root;
}

struct TreeNode* removeNode(struct TreeNode* root, int chave) {
    if (root == NULL) {
        return root;
    }

    if (chave < root->chave) {
        root->left = removeNode(root->left, chave);
    } else if (chave > root->chave) {
        root->right = removeNode(root->right, chave);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->chave = temp->chave;
        root->right = removeNode(root->right, temp->chave);
    }

    return root;
}

int search(struct TreeNode* root, int chave) {
    if (root == NULL) {
        return 0;
    }

    if (chave == root->chave) {
        return 1;
    } else if (chave < root->chave) {
        return search(root->left, chave);
    } else {
        return search(root->right, chave);
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->chave);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->chave);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->chave);
    }
}

int findMin(struct TreeNode* root) {
    if (root == NULL) {
        fprintf(stderr, "Empty tree\n");
        exit(EXIT_FAILURE);
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->chave;
}

int findMax(struct TreeNode* root) {
    if (root == NULL) {
        fprintf(stderr, "Empty tree\n");
        exit(EXIT_FAILURE);
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->chave;
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
