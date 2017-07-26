#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

const int MAX_SIZE = 100;

template <typename T>
class Queue;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Queue<T> & x);

template <typename T>
class Queue {
private:
    T data[MAX_SIZE];
    int head;
    int rear;

public:
    Queue();
    ~Queue() {};
    void enqueue(T x);
    T dequeue();
    void clear();
    bool isEmpty() const;
    bool isfull() const;
    int len() const;
    friend std::ostream &operator<<<>(std::ostream &os, const Queue<T> & x);
};

template <typename T>
Queue<T>::Queue():head(-1), rear(-1) {}

template <typename T>
void Queue<T>::enqueue(T x) {
    if (!isfull()) {
        if (rear == MAX_SIZE -1) {
            data[0] = x;
            rear = 0;
        } else {
            data[++rear] = x;
        }
        if (head == -1) {
            head = 0;
        }
    } else {
        std::cout << "Queue full" << std::endl;
        exit(EXIT_FAILURE);
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue empty" << std::endl;
        exit(EXIT_FAILURE);
    }
    T temp;
    temp = data[head];
    if (head == rear) {
        head = rear = -1;
    } else if (head == MAX_SIZE -1) {
        head = 0;
    } else {
        head++;
    }
    return temp;
}

template <typename T>
void Queue<T>::clear() {
    head = rear = -1;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return head == -1;
}

template <typename T>
bool Queue<T>::isfull() const {
    return head == 0 && rear == MAX_SIZE - 1 || rear == head - 1;
}

template <typename T>
int Queue<T>::len() const {
    return (rear - head + MAX_SIZE) % MAX_SIZE + 1;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Queue<T> & l) {
    if (l.isEmpty()) {
        os <<  "Queue empty" << std::endl;
    } else {
        if (l.rear < l.head) {
            for (auto i = l.head; i <= MAX_SIZE; i++) {
                os << i << ":\t" << l.data[i] << std::endl;
            }

            for (auto i = 0; i <= l.rear; i++) {
                os << i << ":\t" << l.data[i] << std::endl;
            }
        } else {
            for (auto i = l.head; i <= l.rear; i++) {
                os << i << ":\t" << l.data[i] << std::endl;
            }
        }
    }

    return os;
}

#endif // QUEUE_H
