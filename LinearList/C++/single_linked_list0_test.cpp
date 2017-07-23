#include <iostream>
#include "single_linked_list0.h"


int main() {
    List a;
    List b;
    a.insert(2);
    a.insert(5);
    a.insert(3);
    a.insert(1, 4);
    b.insert(3);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a.lengh();
}
