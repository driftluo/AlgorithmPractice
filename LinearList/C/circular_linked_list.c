#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0

// A circular linked list

typedef int Status;

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i, ElemType *e);
void CreateListHead(LinkList *L, int n);
void CreateListTail(LinkList *L, int n);
Status ClearList(LinkList *L);
void ListShow(LinkList *L);

int main() {
    LinkList x;
    LinkList y;
    ElemType e;
    ElemType f;
    CreateListHead(&x, 10);
    CreateListTail(&y, 10);
    GetElem(x, 2, &e);
    printf("%d\n", e);
    GetElem(y, 2, &f);
    printf("%d\n", f);
    ListShow(&x);
    ListShow(&y);
    ClearList(&x);
    ClearList(&y);
    return 0;
}

Status GetElem(LinkList L, int i, ElemType *e) {
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while (p->next!=L && j<i) {
        p = p->next;
        j++;
    }
    if (j> i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e) {
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p->next!=*L && j< i) {
        p = p->next;
        j++;
    }
    if (j > i) {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e) {
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next!=*L && j<i) {
        p = p->next;
        j++;
    }
    if (!(p->next) || j>i) {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

// Head inserted
void CreateListHead(LinkList *L, int n) {
    LinkList p;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = *L;
    for (i=0; i<n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

// Tail insert
void CreateListTail(LinkList *L, int n) {
    LinkList p, r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;
    for (i=0; i<n; i++) {
        p = (Node *)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;      // r point to the end
    }
    r->next = *L;
}

Status ClearList(LinkList *L) {
    LinkList p, q;
    p = (*L)->next;
    while (p!=*L) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = *L;
    return OK;
}

void ListShow(LinkList *L) {
    LinkList p;
    int i=0;
    printf("The list:\n");
    p = *L;
    p = p->next;
    while (p->next!=*L) {
        printf("%d:\t%d\n", i, p->data);
        p = p->next;
        i++;
    }
}
