#ifndef STOCK_H
#define STOCK_H

#include <iostream>

template <typename T>
class Stack;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Stack<T> & x);

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node * next;
    };
    Node * top;
    int length;

public:
    Stack();
    ~Stack();
    void push(T x);
    T pop();
    void clear();
    bool isEmpty();
    int len() const;
    friend std::ostream &operator<<<>(std::ostream &os, const Stack<T> & x);
};

template <typename T>
Stack<T>::Stack():length(-1), top(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
void Stack<T>::push(T x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
    length++;
}

template <typename T>
T Stack<T>::pop() {
    if (length == -1) {
        abort();
    }
    Node *temp = top;
    top = top->next;
    T data;
    data = temp->data;
    delete(temp);
    length--;
    return data;
}

template <typename T>
void Stack<T>::clear() {
    if (length >= 0) {
        Node *temp = top;
        top = top->next;
        delete(temp);
        length--;
    }
}

template <typename T>
bool Stack<T>::isEmpty() {
    return length == -1;
}

template <typename T>
int Stack<T>::len() const {
    return length;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Stack<T> & l) {
    auto *temp = l.top;
    for (int i = 0; i < l.len() + 1; i++){
        os << i << ":\t" << temp->data << std::endl;
        temp = temp->next;
    }
    return os;
}

#endif //STOCK_H
