#include <iostream>
#include "stack_by_arry.h"

Stack::Stack():top(-1) {}

bool Stack::push(int x) {
    if (top == STOCK_SIZE -1) {
        return false;
    }
    top++;
    data[top] = x;    // data[++top] = x;
    return true;
}

bool Stack::pop(int &x) {
    if (top == -1) {
        return false;
    }
    x = data[top];
    top--;           // x = data[top--];
    return true;
}

void Stack::clear() {
    top = -1;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == STOCK_SIZE - 1;
}

int Stack::len() const {
    return top + 1;
}

std::ostream &operator<<(std::ostream &os, const Stack & l) {
    for (int i = 0; i < l.len(); i++){
        os << i << ":\t" << l.data[i] << std::endl;
    }
    return os;
}
