#include <iostream>
#include "double_linked_list.h"

List::List() {
    head = nullptr;
    rear = nullptr;
    length = 0;
}

List::~List() {
    node *temp;
    for (int i = 0; i < length; i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void List::insert(int x, int pos) {
    if (pos < 0 || pos > length) {
        std::cout << "pos must be greater than zero" << std::endl;
        return;
    }
    if (pos == 0) {
        auto temp = new node();
        temp->data = x;
        temp->next = head;
        temp->pre = head->pre;
        head->pre = temp;
        head = temp;
        if (rear == nullptr) {
            rear = temp;
        }
        length++;
    }
    if (pos <= length) {
        auto temp = new node();
        temp->data = x;
        node * current = head;
        for (int i = 0; i < pos; i++) {
            current = head->next;
        }
        temp->next = current;
        temp->pre = current->pre;
        current->pre->next = temp;
        current->pre = temp;
        length++;
    }
}

void List::add(int x) {
    auto temp = new node();
    temp->data = x;
    if (rear == nullptr) {
        head = temp;
        rear = temp;
    } else {
        rear->next = temp;
        temp->pre = rear;
        rear = temp;
    }
    length++;
}

void List::remove(int pos) {
    if (pos > length) {
        std::cout << "pos must smaller than length" << std::endl;
        return;
    } else {
        node * current = head;
        for (int i = 0; i < pos; i++) {
            current = head->next;
        }
        current->pre->next = current->next;
        current->next->pre = current->pre;
        delete current;
        length--;
    }
}

std::ostream &operator<<(std::ostream &os, const List & l) {
    auto *temp = l.head;
    for (int i = 0; i < l.len(); i++){
        os << i << ":\t" << temp->data << std::endl;
        temp = temp->next;
    }
    return os;
}
