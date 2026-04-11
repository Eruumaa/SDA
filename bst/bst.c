#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int MakeIntBST(IntBSTree * pBST) {
    pBST->root = NULL;
    pBST->size = 0;
    return EXIT_SUCCESS;
}

int InsertBST(IntBSTree * pBST, int data) {
    IntBSTNodePtr current, previous, newNode;
    previous = NULL;
    current = pBST->root;

    while(current != NULL) {
        previous = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return EXIT_SUCCESS; // Abaikan duplikat
    }

    newNode = (IntBSTNodePtr) malloc(sizeof(IntBSTNode));
    if (newNode == NULL) return EXIT_FAILURE;

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    (pBST->size)++;
    if (previous == NULL) pBST->root = newNode;
    else if (data < previous->data) previous->left = newNode;
    else previous->right = newNode;

    return EXIT_SUCCESS;
}

// Rekursif Delete Helper
static IntBSTNodePtr deleteNode(IntBSTNodePtr root, int data, int *isDeleted) {
    if (root == NULL) return NULL;

    if (data < root->data) {
        root->left = deleteNode(root->left, data, isDeleted);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data, isDeleted);
    } else {
        *isDeleted = 1;
        if (root->left == NULL) {
            IntBSTNodePtr temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            IntBSTNodePtr temp = root->left;
            free(root);
            return temp;
        }
        IntBSTNodePtr temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, isDeleted);
    }
    return root;
}

void deleteBST(IntBSTree * pBST, int data) {
    int isDeleted = 0;
    pBST->root = deleteNode(pBST->root, data, &isDeleted);
    if (isDeleted) (pBST->size)--;
}

// Iterative In-Order
void inOrder(IntBSTree * pBST) {
    if (pBST->root == NULL) return;
    IntBSTNodePtr stack[100];
    int top = -1;
    IntBSTNodePtr curr = pBST->root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

// Iterative Pre-Order
void preOrder(IntBSTree * pBST) {
    if (pBST->root == NULL) return;
    IntBSTNodePtr stack[100];
    int top = -1;
    stack[++top] = pBST->root;

    while (top != -1) {
        IntBSTNodePtr node = stack[top--];
        printf("%d ", node->data);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
    printf("\n");
}

// Iterative Post-Order
void postOrder(IntBSTree * pBST) {
    if (pBST->root == NULL) return;
    IntBSTNodePtr stack[100];
    int top = -1;
    IntBSTNodePtr curr = pBST->root;
    IntBSTNodePtr lastVisited = NULL;

    while (curr != NULL || top != -1) {
        if (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        } else {
            IntBSTNodePtr peek = stack[top];
            if (peek->right != NULL && lastVisited != peek->right) {
                curr = peek->right;
            } else {
                printf("%d ", peek->data);
                lastVisited = stack[top--];
            }
        }
    }
    printf("\n");
}

static void freeNode(IntBSTNodePtr node) {
    if (node != NULL) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

void freeBST(IntBSTree * pBST) {
    freeNode(pBST->root);
    pBST->root = NULL;
    pBST->size = 0;
}