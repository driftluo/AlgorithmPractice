#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
    if (!T) {
        *p = f;
        return FALSE;
    } else if (key == T->data) {
        *p = T;
        return TRUE;
    } else if (key < T->data) {
        return SearchBST(T->lchild, key, f, p);
    } else {
        return SearchBST(T->rchild, key, f, p);
    }
}

int InsertBST(BiTree *T, int key) {
    BiTree p, s;
    if (!SearchBST(*T, key, NULL, &p)) {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p) {
            *T = s;
        } else if (key < p->data) {
            p->lchild = s;
        } else {
            p->rchild = s;
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

int DeleteBST(BiTree *T, int key) {
    if (!*T) {
        return FALSE;
    } else {
        if (key == (*T)->data) {
            return Delete(T);
        } else if (key < (*T)->data) {
            return DeleteBST(&(*T)->lchild, key);
        } else {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

int Delete(BiTree *p) {
    BiTree q, s;
    if ((*p)->rchild == NULL) {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    } else if ((*p)->lchild == NULL) {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    } else {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild) {
            q = s;
            s = s->rchild;
        }

        (*p)->data = s->data;

        if (q != *p) {
            q->rchild = s->lchild;
        } else {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return TRUE;
}
