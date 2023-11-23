// binary_search_tree.c

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

struct TreeNode* removeNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = removeNode(root->left, key);
    } else if (key > root->key) {
        root->right = removeNode(root->right, key);
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

        root->key = temp->key;
        root->right = removeNode(root->right, temp->key);
    }

    return root;
}

int search(struct TreeNode* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (key == root->key) {
        return 1;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
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

    return root->key;
}

int findMax(struct TreeNode* root) {
    if (root == NULL) {
        fprintf(stderr, "Empty tree\n");
        exit(EXIT_FAILURE);
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->key;
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
