#ifndef AVLTree_H
#define AVLTree_H

#include <iostream>

template <typename T>
class AVLTree {
private:
    struct AVLTreeNode {
        T key;
        int height;
        AVLTreeNode * left;
        AVLTreeNode * right;
        AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r)
                : key(value), height(0), left(l), right(r) {}
    };
    AVLTreeNode * root;

    int height(AVLTreeNode * tree);

    void preOrder(AVLTreeNode * tree) const;
    void inOrder(AVLTreeNode * tree) const;
    void postOrder(AVLTreeNode * tree) const;

    AVLTreeNode * search(AVLTreeNode * x, T key) const;
    AVLTreeNode * notIterativeSearch(AVLTreeNode * x, T key) const;

    AVLTreeNode * mininum(AVLTreeNode * tree);
    AVLTreeNode * maxnum(AVLTreeNode * tree);

    AVLTreeNode * leftLeftRotation(AVLTreeNode * k);
    AVLTreeNode * rightRightRotation(AVLTreeNode * k);
    AVLTreeNode * leftRightRotation(AVLTreeNode * k);
    AVLTreeNode * rightLeftRotation(AVLTreeNode * k);

    AVLTreeNode * insert(AVLTreeNode * &tree, T key);

    AVLTreeNode * remove(AVLTreeNode * &tree, AVLTreeNode * z);

    void destroy(AVLTreeNode * &tree);



public:
    AVLTree():root(nullptr) {};
    ~AVLTree() { destroy(root); }

    int height();
    int max(int a, int b);

    void preOrder();
    void inOrder();
    void postOrder();

    AVLTreeNode * search(T key);
    AVLTreeNode * notIterativeSearch(T key);

    T mininum();
    T maxinum();

    void insert(T key);

    void remove(T key);
    void destroy();
};

template <typename T>
int AVLTree<T>::height(AVLTreeNode *tree) {
    if (tree != nullptr) {
        return tree->height;
    }
    return 0;
}

template <typename T>
int AVLTree<T>::height() {
    return height(root);
}

template <typename T>
int AVLTree<T>::max(int a, int b) {
    return a>b ? a : b;
}

template <typename T>
void AVLTree<T>::preOrder(AVLTreeNode *tree) const {
    if (tree != nullptr) {
        std::cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <typename T>
void AVLTree<T>::preOrder() {
    preOrder(root);
}

template <typename T>
void AVLTree<T>::inOrder(AVLTreeNode *tree) const {
    if (tree != nullptr) {
        inOrder(tree->left);
        std::cout << tree->key << " ";
        inOrder(tree->right);
    }
}

template <typename T>
void AVLTree<T>::inOrder() {
    inOrder(root);
}

template <typename T>
void AVLTree<T>::postOrder(AVLTreeNode *tree) const {
    if (tree != nullptr) {
        postOrder(tree->left);
        postOrder(tree->right);
        std::cout << tree->key << " ";
    }
}

template <typename T>
void AVLTree<T>::postOrder() {
    postOrder(root);
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::search(AVLTreeNode *x, T key) const {
    if (x == nullptr || x->key == key) {
        return x;
    }
    if (key < x->key) {
        return search(x->left, key);
    } else {
        return search(x->right, key);
    }
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::search(T key) {
    return search(root, key);
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::notIterativeSearch(AVLTreeNode *x, T key) const {
    while ((x != nullptr) && (x->key != key)) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::notIterativeSearch(T key) {
    return notIterativeSearch(root, key);
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::leftLeftRotation(AVLTreeNode *k) {
    AVLTreeNode * r;

    r = k->left;
    k->left = r->right;
    r->right = k;

    k->height = max(height(k->left), height(k->right)) + 1;
    r->height = max(height(r->left), k->height) + 1;
    return r;
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::rightRightRotation(AVLTreeNode *k) {
    AVLTreeNode * r;

    r = k->right;
    k->right = r->left;
    r->left = k;

    k->height = max(height(k->left), height(k->right)) + 1;
    r->height = max(height(r->right), k->height) + 1;
    return r;
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::leftRightRotation(AVLTreeNode *k) {
    k->left = rightRightRotation(k->left);
    return leftLeftRotation(k);
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::rightLeftRotation(AVLTreeNode *k) {
    k->right = leftLeftRotation(k->right);
    return rightRightRotation(k);
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::mininum(AVLTreeNode *tree) {
    if (tree == nullptr) {
        return nullptr;
    }
    while (tree->left != nullptr) {
        tree = tree->left;
    }
    return tree;
}

template <typename T>
T AVLTree<T>::mininum() {
    auto p = mininum(root);
    if (p != nullptr) {
        return p->key;
    }
    return (T) NULL;
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::maxnum(AVLTreeNode *tree) {
    if (tree == nullptr) {
        return nullptr;
    }
    while (tree->right != nullptr) {
        tree = tree->right;
    }
    return tree;
}

template <typename T>
T AVLTree<T>::maxinum() {
    auto p = maxnum(root);
    if (p != nullptr) {
        return p->key;
    }
    return (T) NULL;
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::insert(AVLTreeNode *&tree, T key) {
    if (tree == nullptr) {
        tree = new AVLTreeNode(key, nullptr, nullptr);
    } else if (key < tree->key) {
        tree->left = insert(tree->left, key);
        if (height(tree->left) - height(tree->right) == 2) {
            if (key < tree->left->key) {
                tree = leftLeftRotation(tree);
            } else {
                tree = leftRightRotation(tree);
            }
        }
    } else if (key > tree->key) {
        tree->right = insert(tree->right, key);
        if (height(tree->right) - height(tree->left) == 2) {
            if (key > tree->right->key) {
                tree = rightRightRotation(tree);
            } else {
                tree = rightLeftRotation(tree);
            }
        }
    } else // key == tree->key
    {
        std::cout << "fail: " << key << " is already exists" << std::endl;
    }

    tree->height = max(height(tree->left), height(tree->right)) + 1;
    return tree;
}

template <typename T>
void AVLTree<T>::insert(T key) {
    insert(root, key);
}

template <typename T>
void AVLTree<T>::destroy(AVLTreeNode *&tree) {
    if (tree == nullptr) {
        return;
    }
    if (tree->left != nullptr) {
        destroy(tree->left);
    }
    if (tree->right != nullptr) {
        destroy(tree->right);
    }
    delete tree;
}

template <typename T>
void AVLTree<T>::destroy() {
    destroy(root);
}

template <typename T>
typename AVLTree<T>::AVLTreeNode * AVLTree<T>::remove(AVLTreeNode *&tree, AVLTreeNode *z) {
    if (tree == nullptr || z == nullptr) {
        return nullptr;
    }
    if (z->key < tree->key) {
        tree->left = remove(tree->left, z);
        if (height(tree->right) - height(tree->left) == 2) {
            auto r = tree->right;
            if (height(r->left) > height(r->right)) {
                tree = rightLeftRotation(tree);
            } else {
                tree = rightRightRotation(tree);
            }
        }
    } else if (z->key > tree->key) {
        tree->right = remove(tree->right, z);
        if (height(tree->left) - height(tree->right) == 2) {
            auto l = tree->left;
            if (height(l->right) > height(l->left)) {
                tree = leftRightRotation(tree);
            } else {
                tree = leftLeftRotation(tree);
            }
        }
    } else {
        if ((tree->left != nullptr) && (tree->right != nullptr)) {
            if (height(tree->left) > height(tree->right)) {
                // 如果tree的左子树比右子树高；
                // 则(01)找出tree的左子树中的最大节点
                //   (02)将该最大节点的值赋值给tree。
                //   (03)删除该最大节点。
                // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的
                auto max = maxnum(tree->left);
                tree->key = max->key;
                tree->left = remove(tree->left, max);
            } else {
                auto min = mininum(tree->right);
                tree->key = min->key;
                tree->right = remove(tree->right, min);
            }
        } else {
            auto tmp = tree;
            tree = (tree->left != nullptr) ? tree->left : tree->right;
            delete tmp;
        }
    }
    return tree;
}

template <typename T>
void AVLTree<T>::remove(T key) {
    AVLTreeNode * temp;
    if ((temp = search(key)) != nullptr) {
        root = remove(root, temp);
    }
}

#endif // AVLTree_H
