#include <iostream>
#include "avltree_search.h"


int main() {
    AVLTree<int> tree;
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);
    tree.insert(2);
    tree.preOrder();
    std::cout << std::endl;
    tree.inOrder();
    std::cout << std::endl;
    tree.postOrder();
    std::cout << std::endl;
    auto a = tree.mininum();
    std::cout << a <<std::endl;
    auto b = tree.maxinum();
    std::cout << b <<std::endl;
    tree.remove(1);
    tree.preOrder();
    std::cout << std::endl;
}
