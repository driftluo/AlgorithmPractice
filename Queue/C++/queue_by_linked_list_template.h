#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Queue<T> & x);

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node * next;
        Node(T x):data(x),next(nullptr) {}
    };
    Node * head;
    Node * rear;

public:
    Queue();
    ~Queue();
    void enqueue(T x);
    T dequeue();
    void clear();
    bool isEmpty() const;
    int len() const;
    friend std::ostream &operator<<<>(std::ostream &os, const Queue<T> & x);
};

template <typename T>
Queue<T>::Queue():head(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    Node * temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::enqueue(T x) {
    if (head == nullptr) {
        head = rear = new Node(x);
    } else {
        rear = rear->next = new Node(x);
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue empty" << std::endl;
        exit(EXIT_FAILURE);
    }
    T temp;
    auto p = head;
    temp = head->data;
    head = head->next;
    delete p;
    return temp;
}

template <typename T>
void Queue<T>::clear() {
    Node * temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
int Queue<T>::len() const {
    auto p = head;
    int count = 0;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Queue<T> & l) {
    if (l.isEmpty()) {
        os <<  "Queue empty" << std::endl;
    } else {
        auto temp = l.head;
        for (int i = 0; i<l.len(); i++) {
            os << i << ":\t" << temp->data << std::endl;
            temp = temp->next;
        }
    }

    return os;
}

#endif // QUEUE_H
