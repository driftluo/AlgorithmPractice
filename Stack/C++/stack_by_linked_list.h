#ifndef STOCK_H
#define STOCK_H

#include <iostream>

class Stack {
private:
    struct Node {
        int data;
        Node * next;
    };
    Node * top;
    int length;

public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    void clear();
    bool isEmpty();
    int len() const;
    friend std::ostream &operator<<(std::ostream &os, const Stack & x);
};

#endif //STOCK_H
