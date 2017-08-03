#include <iostream>
#include "binarytree_by_template.h"


int main() {
    BinaryTree<int> tree;
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
    auto a = tree.findMin();
    std::cout << a->element <<std::endl;
    auto b = tree.findMax();
    std::cout << b->element <<std::endl;
    tree.remove(1);
    tree.preOrder();
    std::cout << std::endl;
}
