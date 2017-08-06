#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void bubbleSort(vector<T> &a, int left, int right) {
    bool cond = true;
    for (int i = left; i < right && cond; i++) {
        cond = false;
        for (int j = right - 1; j > i; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                cond = true;
            }
        }
    }
}

template <typename T>
void selectSort(vector<T> &a, int left, int right) {
    for (int i = left; i < right; i++) {
        int min = i;
        for (int j = i + 1; j < right; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (i != min) {
            swap(a[i], a[min]);
        }
    }
}

template <typename T>
void insertSort(vector<T> &a, int left, int right) {
    for (int i = left + 1; i < right; i++) {
        T temp = a[i];
        int j;
        for (j = i; j > left && temp < a[j-1]; j--) {
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}

template <typename T>
void merg(vector<T> &a, int left, int m, int right, vector<T> temp) {
    int lb = left, rb = m, tb = left;
    while (lb != m && rb != right) {
        if (a[lb] < a[rb]) {
            temp[tb++] = a[lb++];
        } else {
            temp[tb++] = a[rb++];
        }
    }

    while (lb < m) {
        temp[tb++] = a[lb++];
    }
    while (rb < right) {
        temp[tb++] = a[rb++];
    }

    for (int i = left; i < right; i++) {
        a[i] = temp[i];
    }
}

template <typename T>
void mergSort(vector<T> &a, int left, int right, vector<T> &temp) {
    int m = (left + right) / 2;
    if (m != left) {
        mergSort(a, left, m, temp);
        mergSort(a, m, right, temp);
        merg(a, left, m, right, temp);
    }
}

template <typename T>
void quickSort(vector<T> &a, int left, int right) {
    if (left < right - 1) {
        int lb = left, rb = right - 1;
        while (lb < rb) {
            while (a[rb] >= a[left] && lb < rb) {
                rb--;
            }
            while (a[lb] <= a[left] && lb < rb) {
                lb++;
            }
            swap(a[lb], a[rb]);
        }
        swap(a[left], a[lb]);
        quickSort(a, left, lb);
        quickSort(a, lb+1, right);
    }
}

#endif // SORT_H
