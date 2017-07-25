#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0

// A queue by single linked list

typedef int Status;

typedef int ElemType;

typedef struct QNode {
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front,rear;
} Queue;

Status EnQueue(Queue *Q, ElemType e);
Status DeQueue(Queue *Q, ElemType *e);
Status InitQueue(Queue *Q);
int len(Queue *Q);
void ShowQueue(Queue *Q);

int main(){
    Queue q;
    int x;
    InitQueue(&q);
    EnQueue(&q, 1);
    EnQueue(&q, 2);
    EnQueue(&q, 3);
    ShowQueue(&q);
    DeQueue(&q, &x);
    ShowQueue(&q);
    printf("%d", x);
}

Status EnQueue(Queue *Q, ElemType e) {
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return OK;
}

Status DeQueue(Queue *Q, ElemType *e) {
    QueuePtr p;
    if (Q->front == Q->rear) {
        return ERROR;
    }
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

Status InitQueue(Queue *Q) {
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    s->next = NULL;
    Q->front = s;
    Q->rear = s;
    return OK;
}

int len(Queue *Q) {
    int i = 0;
    QueuePtr temp = Q->front->next;
    while (temp != Q->rear) {
        temp = temp->next;
        ++i;
    }
    return ++i;
}

void ShowQueue(Queue *Q) {
    QueuePtr temp;
    if (Q->front == Q->rear) {
        printf("The queue is empty");
    }
    temp = Q->front->next;
    for (int i = 0; i < len(Q); i++) {
        printf("%d:\t%d\n", i, temp->data);
        temp = temp->next;
    }
}
