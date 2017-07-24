#ifndef LIST2_H
#define LIST2_H

#include <iostream>

struct node {
    int data;
    node * pre;
    node * next;
};

class List {
private:
    int length;
    node * head;
    node * rear;

public:
    List();
    ~List();
    int len() const { return length; }
    void insert(int x, int pos);
    void add(int x);
    void remove(int pos);
    friend std::ostream &operator<<(std::ostream &os, const List & l);
};

#endif //LIST2_H
