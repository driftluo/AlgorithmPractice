#include <iostream>
#include "stack_by_linked_list.h"

Stack::Stack():length(-1), top(nullptr) {}

Stack::~Stack() {
    clear();
}

void Stack::push(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
    length++;
}

int Stack::pop() {
    if (length == -1) {
        abort();
    }
    Node *temp = top;
    top = top->next;
    int data;
    data = temp->data;
    delete(temp);
    length--;
    return data;
}

void Stack::clear() {
    if (length >= 0) {
        Node *temp = top;
        top = top->next;
        delete(temp);
        length--;
    }
}

bool Stack::isEmpty() {
    return length == -1;
}

int Stack::len() const {
    return length;
}

std::ostream &operator<<(std::ostream &os, const Stack & l) {
    auto *temp = l.top;
    for (int i = 0; i < l.len() + 1; i++){
        os << i << ":\t" << temp->data << std::endl;
        temp = temp->next;
    }
    return os;
}
