#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768
#define OK 1
#define ERROR 0


typedef int Status;

typedef struct {
    int *elem;
    int count;
} HashTable;

int m = 0;

Status InitHashTable(HashTable *H) {
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    for (i=0; i<m; i++) {
        H->elem[i] = NULLKEY;
    }
    return OK;
}

int Hash(int key) {
    return key % m;
}

void InsertHash(HashTable *H, int key) {
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY) {
        addr = (addr + 1) % m;
    }
    H->elem[addr] = key;
}

Status SearchHash(HashTable H, int key, int *addr) {
    *addr = Hash(key);
    while (H.elem[*addr] != key) {
        *addr = (*addr + 1) % m;
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) {
            return UNSUCCESS;
        }
    }
    return SUCCESS;
}
