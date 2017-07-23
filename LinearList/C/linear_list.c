#include <stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0

// A linear list with an array

typedef int Status;

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
}SqList;

Status GetElem(SqList L, int i, ElemType *e);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
void ListShow(SqList *L);

int main() {
    SqList s;
    ElemType e;
    ElemType f;
    ListInsert(&s, 1, 10);
    ListInsert(&s, 2, 20);
    ListInsert(&s, 3, 30);
    ListShow(&s);
    ListDelete(&s, 2, &e);
    ListShow(&s);
    printf("%d\n", e);
    GetElem(s, 1, &f);
    printf("%d\n", f);
    ListShow(&s);
    return 0;
}

Status GetElem(SqList L, int i, ElemType *e) {
    if(L.length==0 || i<1 || i>L.length) {
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e) {
    int k;
    if (L->length == MAXSIZE){
        return ERROR;
    }
    if (i<1 || i>L->length+1) {
        return ERROR;
    }
    if (i<=L->length){
        for (k=L->length-1;k>=i-1;k--) {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    int k;
    if (L->length == 0) {
        return ERROR;
    }
    if (i<1 || i>L->length) {
        return ERROR;
    }
    *e = L->data[i-1];
    if (i<L->length) {
        for (k=i; k<L->length;k++) {
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}

void ListShow(SqList *L) {
    int k;
    if (L->length == 0) {
        printf("This is an empty table.");
    }
    printf("The table:\n");
    for (k=0; k<L->length; k++) {
        printf("%d: %d\n", k, L->data[k]);
    }
}
