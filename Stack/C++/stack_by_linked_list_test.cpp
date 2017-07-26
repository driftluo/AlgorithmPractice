#include <iostream>
#include "stack_by_linked_list.h"


int main() {
    Stack zx;
    int x;
    zx.push(5);
    zx.push(4);
    std::cout << zx;
    zx.pop();
    std::cout << zx;
}
