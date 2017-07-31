#include <stdio.h>


// Sequential Search
int Sequential_Search(int *a, int n, int key) {
    int i;
    for (i = 1; i <= n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return 0;
}

int Sequential_Search2(int *a, int n, int key) {
    int i;
    a[0] = key;
    i = n;
    while (a[i] != key) {
        i--;
    }
    return i;
}

int Binary_Search(int *a, int n, int key) {
    int low, high, mid;
    low = 1;
    high = n;
    while (low <= high) {
        mid = (low+high) / 2;
        if (key < a[mid]) {
            high = mid - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

int Interpolation_Search(int *a, int n, int key) {
    int low, high, mid;
    low = 1;
    high = n;
    while (low <= high) {
        mid = low + (low+high) * (key - a[low]) / (a[high] - a[low]);  // Interpolation 插值
        if (key < a[mid]) {
            high = mid - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

int Fibonacci_search(int *a, int n, int key) {
    int F[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int low, high, mid, i, k;
    low = 1;
    high = n;
    k = 0;
    while (n > F[k] - 1) {
        k++;
    }
    for (i = n; i < F[k]-1; i++) {
        a[i] = a[n];
    }

    while (low <= high) {
        mid = low + F[k-1] - 1;
        if (key < a[mid]) {
            high = mid - 1;
            k = k - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
            k = k - 2;
        } else {
            if (mid <= n) {
                return mid;
            } else {
                return n;
            }
        }
    }
    return 0;
}
