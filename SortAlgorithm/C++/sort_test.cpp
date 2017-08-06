#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "sort.h"


using namespace std;

template <typename T>
void printVector(const vector<T> &a) {
    auto itr = a.begin();
    while (itr != a.end()) {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;
}

int main() {
    vector<int> a(10);
    vector<int> b(10);
    srand(time(0));
    for (int i = 0; i< a.size(); i++) {
        a[i] = rand() %100;
    }
    printVector(a);
    quickSort(a, 0, a.size());
    printVector(a);
}
