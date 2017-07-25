#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0

// A circular queue by array

typedef int Status;

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int front;
    int rear;
} Queue;

Status EnQueue(Queue *Q, ElemType e);
Status DeQueue(Queue *Q, ElemType *e);
Status InitQueue(Queue *Q);
int QueueLength(Queue Q);
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
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}

Status DeQueue(Queue *Q, ElemType *e) {
    if (Q->front == Q->rear) {
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}

Status InitQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

int QueueLength(Queue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

void ShowQueue(Queue *Q) {
    int i = Q->front;
    if (Q->rear == Q->front) printf("empty Queue");
    if (Q->rear > Q->front) {
        for (int j = i; j<Q->rear; j++) {
            printf("%d:\t%d\n", j, Q->data[j]);
        }
    } else {
        for (int j = i; j<MAXSIZE; j++) {
            printf("%d:\t%d\n", j, Q->data[j]);
        }
        for (int x = 0; x<Q->rear; x++) {
            printf("%d:\t%d\n", x, Q->data[x]);
        }
    }
}
