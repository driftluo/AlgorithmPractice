#ifndef LIST1_H
#define LIST1_H

#include <iostream>

template <typename T> class List;
template <typename T>
std::ostream &operator<<(std::ostream & os, const List<T> & l);

template <typename T>
class List {
public:
    class Node {
    public:
        T data;
        Node * next;
        Node() { next= nullptr; }
    };
    List();
    ~List();
    int listlength() const { return length; };
    void add(T x);
    void insert(T x, int pos);
    void inserthead(T x);
    friend std::ostream &operator<<<>(std::ostream & os, const List<T> & l);

private:
    int length;
    Node * head;
    Node * rear;
};

template <typename T>
List<T>::List() {
    head = nullptr;
    rear = nullptr;
    length = 0;
}

template <typename T>
List<T>::~List() {
    Node *temp;
    for (int i = 0; i < length; i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void List<T>::inserthead(T x) {
    auto node = new Node();
    node->data = x;
    node->next = head;
    head = node;
    if (rear == nullptr) {
        rear = node;
    }
    length++;
}

template <typename T>
void List<T>::insert(T x, int pos) {
    if (pos < 0 || pos > length) {
        std::cout << "dl must be greater than zero" << std::endl;
        return;
    }
    if (pos == 0) {
        List<T>::inserthead(x);
    }
    if (pos <= length) {
        auto node = new Node();
        node->data = x;
        Node *temp = head;
        for (int i = 0; i < pos-1; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
        length++;
        if (node->next == nullptr) {
            rear = node;
        }
    }
}

template <typename T>
void List<T>::add(T x) {
    auto node = new Node();
    node->data = x;
    if (rear == nullptr) {
        head = node;
        rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
    length++;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const List<T> &l) {
    auto *temp = l.head;
    for (int i = 0; i < l.listlength(); i++){
        os << i << ":\t" << temp->data << std::endl;
        temp = temp->next;
    }
    return os;
}

#endif //LIST1_H
