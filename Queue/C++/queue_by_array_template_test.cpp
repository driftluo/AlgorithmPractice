#include <iostream>
#include "queue_by_array_template.h"


int main() {
    Queue<int> zx;
    zx.enqueue(5);
    zx.enqueue(4);
    std::cout << zx;
    std::cout << zx.len() << std::endl;
    auto i = zx.dequeue();
    std::cout << zx;
    std::cout << i << std::endl;
    std::cout << zx.len();
}
