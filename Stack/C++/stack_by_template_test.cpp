#include <iostream>
#include "stack_by_template.h"


int main() {
    Stack<int> zx;
    zx.push(5);
    zx.push(4);
    std::cout << zx;
    zx.pop();
    std::cout << zx;
}
