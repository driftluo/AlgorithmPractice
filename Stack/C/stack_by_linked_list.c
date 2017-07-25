#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0

// A stack by linked list

typedef int Status;

typedef int ElemType;

typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *Node;

typedef struct LinkStack {
    Node top;
    int count;
}LinkStack;

Status Push(LinkStack *S, ElemType e);
Status Pop(LinkStack *S, ElemType *e);
void InitStack(LinkStack *S);
void ShowStack(LinkStack *S);

int main(){
    LinkStack s;
    int x;
    InitStack(&s);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    ShowStack(&s);
    Pop(&s, &x);
    ShowStack(&s);
    printf("%d", x);
}

Status Push(LinkStack *S, ElemType e) {
    Node s = (Node)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

Status Pop(LinkStack *S, ElemType *e) {
    Node p;
    if (S->count == 0) { return ERROR; }
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}

void InitStack(LinkStack *S) {
    S->top = NULL;
    S->count = 0;
}

void ShowStack(LinkStack *S) {
    Node temp = S->top;
    for (int i = 0; i < S->count; i++) {
        printf("%d:\t%d\n", i,temp->data);
        temp = temp->next;
    }
}
