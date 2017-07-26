#ifndef STOCK_H
#define STOCK_H

#include <iostream>

const int STOCK_SIZE = 100;

class Stack {
private:
    int data[STOCK_SIZE];
    int top;

public:
    Stack();
    ~Stack() {};
    bool push(int x);
    bool pop(int &x);
    void clear();
    bool isEmpty();
    bool isFull();
    int len() const;
    friend std::ostream &operator<<(std::ostream &os, const Stack & x);
};

#endif //STOCK_H
