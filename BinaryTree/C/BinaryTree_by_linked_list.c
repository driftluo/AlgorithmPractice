#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_SIZE 100
#define OK 1
#define ERROR 0

typedef int Elemtype;

typedef struct BiTNode {
    Elemtype data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


// Preorder traversal algorithm
void PreOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

// Sequential traversal algorithm
void InOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

// Posterior traversal algorithm
void PostOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    PostOrderTraverse(T->lchild); // Traverse the left subtree
    PostOrderTraverse(T->rchild); // Traverse the right subtree
    printf("%c", T->data);
}
