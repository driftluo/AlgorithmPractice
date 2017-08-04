#ifndef BINARY_H
#define BINARY_H

#include <iostream>

// 二叉树的删除：
// 1.该节点无孩子；
// 2.该节点只有左或者右孩子；
// 3.该节点存在双孩子；
// 思路：
// 1.直接删除，双亲的孩子指针为空；
// 2.该节点的双亲指向该节点的孩子(左配左，右配右)；
// 3.找到该节点的前驱或者后继，将前驱或者后继的值赋给该节点，同时将前驱的双亲指向前驱左孩子或者后继的双亲指向后继的右孩子，
//   然后删除其前驱或者后继；

template <typename T>
class BinaryTree {
private:
    struct BinaryNode {
        T element;
        BinaryNode * left;
        BinaryNode * right;
        BinaryNode * parent;
        BinaryNode(const T & t, BinaryNode * lt, BinaryNode * rt, BinaryNode * pt)
                : element(t), left(lt), right(rt), parent(pt) {}
    };
    BinaryNode *root;
    void destroy(BinaryNode * t);
    void preOrder(BinaryNode *t) const;
    void inOrder(BinaryNode *t) const;
    void postOrder(BinaryNode *t) const;
    BinaryNode * remove(BinaryNode *tree, BinaryNode *z);
    BinaryNode * predecessor(BinaryNode * x);
    BinaryNode * successor(BinaryNode * x);

public:
    BinaryTree(): root(nullptr) {};
    ~BinaryTree();

    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    BinaryNode * findMin() const;
    BinaryNode * findMax() const;
    bool contains(const T & x) const;
    void insert(const T & x);
    void remove(const T & x);
    BinaryNode * search(T key);
    const BinaryTree &operator=(const BinaryTree & rhs);
};


template <typename T>
BinaryTree<T>::~BinaryTree() {
    destroy(root);
}

template <typename T>
void BinaryTree<T>::preOrder(BinaryNode *t) const {
    if (t != nullptr) {
        std::cout << t->element << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}
template <typename T>
void BinaryTree<T>::preOrder() const {
    preOrder(root);
}

template <typename T>
void BinaryTree<T>::inOrder(BinaryNode *t) const {
    if (t != nullptr) {
        inOrder(t->left);
        std::cout << t->element << " ";
        inOrder(t->right);
    }
}

template <typename T>
void BinaryTree<T>::inOrder() const {
    inOrder(root);
}

template <typename T>
void BinaryTree<T>::postOrder(BinaryNode *t) const {
    if (t != nullptr) {
        postOrder(t->left);
        postOrder(t->right);
        std::cout << t->element << " ";
    }
}

template <typename T>
void BinaryTree<T>::postOrder() const {
    postOrder(root);
}

template <typename T>
bool BinaryTree<T>::contains(const T &x) const {
    auto temp = root;
    while (temp != nullptr) {
        if (x < temp->element) {
            temp = temp->left;
        } else if (x > temp->element) {
            temp = temp->right;
        } else {
            return true;
        }
    }
    return false;
}

template <typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::search(T key) {
    auto temp = root;
    while (temp != nullptr && temp->element != key) {
        if (key < temp->element) {
            temp = temp->left;
        } else if (key > temp->element) {
            temp = temp->right;
        }
    }
    return temp;
}

template <typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::findMin() const {
    auto temp = root;
    if (temp != nullptr) {
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }
}

template <typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::findMax() const {
    auto temp = root;
    if (temp != nullptr) {
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;
    }
}

template <typename T>
void BinaryTree<T>::insert(const T &x) {
    auto temp = root;
    BinaryNode * p = nullptr;
    if (temp == nullptr) {
        root = new BinaryNode(x, nullptr, nullptr, nullptr);
        return;
    }
    while (temp != nullptr) {
        p = temp;
        if (x < temp->element) {
            temp = temp->left;
        } else if (x > temp->element) {
            temp = temp->right;
        }
    }
    if (x < p->element) {
        p->left = new BinaryNode(x, nullptr, nullptr, p);
    } else {
        p->right = new BinaryNode(x, nullptr, nullptr, p);
    }
}

template <typename T>
void BinaryTree<T>::destroy(BinaryNode *t) {
    if (t == nullptr) return;
    if (t->left != nullptr) {
        return destroy(t->left);
    }
    if (t->right != nullptr) {
        return destroy(t->right);
    }
    delete t;
}

template <typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::predecessor(BinaryNode *x) {
    if (x->left != nullptr) {
        auto temp = x->left;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;
    }

    auto y = x->parent;
    while ((y != nullptr) && (x == y->left)) {
        x = y;
        y = y->parent;
    }
    return y;
}

template <typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::successor(BinaryNode *x) {
    if (x->right != nullptr) {
        auto temp = x->right;
        if (temp != nullptr) {
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            return temp;
        }
    }

    auto y = x->parent;
    while ((y != nullptr) && (x == y->right)) {
        x = y;
        y = y->parent;
    }
    return y;
}

template <typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::remove(BinaryNode *tree, BinaryNode *z) {
    BinaryNode *x = nullptr;
    BinaryNode *y = nullptr;

    if ((z->left == nullptr) || (z->right == nullptr)) {
        y = z;
    } else {
        y = successor(z);
    }

    if (y->left != nullptr) {
        x = y->left;
    } else {
        x = y->right;
    }
    if (x == nullptr) {
        x->parent = y->parent;
    }
    if (y->parent == nullptr) {
        tree = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    if (y != z) {
        z->element = y->element;
    }

    return y;

}

template <typename T>
void BinaryTree<T>::remove(const T &x) {
    BinaryNode *z, *node;

    if ((z = search(x)) != nullptr) {
        if ((node = remove(root, z)) != nullptr) {
            delete node;
        }
    }
}

#endif // BINARY_H
