#include <iostream>
#include "double_linked_list.h"


int main() {
    List zx;
    zx.add(5);
    zx.add(4);
    zx.insert(1, 1);
    zx.insert(2, 1);
    zx.remove(1);
    std::cout << zx;
}
