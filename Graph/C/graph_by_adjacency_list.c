#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
#define OK 1
#define ERROR 0

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode {
    int adjvex;
    EdgeType weight;
    struct EdgeNode * next;
}EdgeNode;

typedef struct VertexNode {
    VertexType data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;


void CreateALGraph(GraphAdjList *G) {
    int i, j, k;
    EdgeNode *e;
    printf("Enter the number of vertices and sides:\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);
    for (i = 0; i < G->numVertexes; i++) {
        scanf(&G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }
    for (k = 0;k < G->numEdges; k++) {
        printf("输入边(vi, vj)上的顶点序号：\n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *) malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        e = (EdgeNode *) malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}

void DFS(GraphAdjList G, int i) {
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ", G.adjList[i].data);
    p = G.adjList[i].firstedge;
    while(p) {
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex);
        }
        p = p->next;
    }
}

void DFSTraverse(GraphAdjList G) {
    int i;
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }
    for (i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

void BFSTraverse(GraphAdjList G) {
    int i;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }
    initQueue(&Q);
    for (i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", G.adjList[i].data);
            EnQueue(&Q, i);
            while (!QueueEmpty(Q)) {
                if (!visited[p->adjvex]) {
                    visited[p->adjvex] = TRUE;
                    printf("%c ", G.adjList[p->adjvex].data);
                    EnQueue(&Q, p->adjvex);
                }
                p = p->next;
            }
        }
    }
}