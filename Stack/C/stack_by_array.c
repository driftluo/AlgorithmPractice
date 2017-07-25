#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0

// A stack by array

typedef int Status;

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int top;
} Stack;

Status Push(Stack *S, ElemType e);
Status Pop(Stack *S, ElemType *e);
void InitStack(Stack *S);
void ShowStack(Stack *S);

int main(){
    Stack s;
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

Status Push(Stack *S, ElemType e) {
    if (S->top == MAXSIZE - 1) {
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status Pop(Stack *S, ElemType *e) {
    if (S->top == -1) {
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}

void InitStack(Stack *S) {
    S->top = -1;
}

void ShowStack(Stack *S) {
    for (int i = 0; i <= S->top; i++) {
        printf("%d:\t%d\n", i,S->data[i]);
    }
}
