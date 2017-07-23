#include <iostream>
#include "template_class_single_linked_list.h"


int main() {
    List<int> zx;
    zx.add(5);
    zx.add(4);
    zx.inserthead(1);
    zx.insert(2, 1);
    std::cout << zx;
}
