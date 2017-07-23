//
// Created by luoch on 2017/7/14 0014.
//

#ifndef LIST0_H
#define LIST0_H

#include <iostream>


class List {
public:
    struct Node {
        int data;
        Node * next;
        explicit Node(const int & d): data(d), next(nullptr) {}
    };
    List();
    List(const List & l);
    List &operator=(const List & l);
    ~List();
    void insert(const int & d, const int & pos);
    void insert(const int & d);
    void erase(const int & pos);
    const int lengh() const { return length; }
    const int &operator[](const int & i);
    friend std::ostream & operator<<(std::ostream & os, const List & l);

private:
    Node * head;
    int length;
};

#endif //LIST0_H
