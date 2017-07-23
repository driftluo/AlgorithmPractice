//
// Created by luoch on 2017/7/14 0014.
//

#include <iostream>
#include "single_linked_list0.h"

class IndexError{};

List::List() {
    head = new Node(0);
    length = 0;
}

List::List(const List & l) {
    Node *temp = l.head;

    for (int i = 0; i < length; i++) {
        this->erase(i);
    }
    length = l.length;
    for (int i = 0; i < length; i++) {
        temp = temp->next;
        this->insert(temp->data);
    }
}

List& List::operator=(const List &l) {
    if (this == &l) {
        return *this;
    }
    Node *temp = l.head;

    for (int i = 0; i < length; i++) {
        this->erase(i);
    }
    length = l.length;
    for (int i = 0; i < length; i++) {
        temp = temp->next;
        this->insert(temp->data);
    }
    return *this;
}

List::~List() {
    Node *temp;
    for (int i = 0; i<length; i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void List::insert(const int &d) {
    Node *temp = new Node(d);
    temp->next = head->next;
    head->next = temp;
    length++;
}

void List::insert(const int &d, const int &pos) {
    if (pos < 0 || pos > length) {
        std::cout << "dl must be greater than zero" << std::endl;
        return;
    }
    if (pos == 0) {
        List::insert(d);
    }

    if (pos <= length) {
        int i;
        Node *node = new Node(d);
        Node *temp = head;
        for (i = 0; i < pos; i++) {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
        length++;
    }
}

void List::erase(const int &pos) {
    if (pos > length-1 || pos < 0) return;
    Node * temp = head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    Node * p = temp->next;
    temp->next = p->next;
    delete p;
    length--;
}

const int& List::operator[](const int &i) {
    if (i<0 || i>length-1) throw IndexError();
    Node * temp = head;
    for (int j = 0; j < i; j++) {
        temp = temp->next;
    }
    temp = temp->next;
    return temp->data;
}

std::ostream& operator<<(std::ostream &os, const List &l) {
    List::Node *temp = l.head;
    for (int i = 0; i < l.lengh(); i++){
        temp = temp->next;
        os << i << ":\t" << temp->data << std::endl;
    }
    return os;
}
