#include <iostream>
#include "arrays.h"


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void showArray(int* array, int length) {
    for (int i = 0; i < length; i++)
        std::cout << *(array+i) << ' ';
    std::cout << '\n';
}

void swapItems(int* array, int i, int j) {
    int temp = *(array+i);
    *(array+i) = *(array+j);
    *(array+j) = temp;
}

void reverseArray(int* array, int length){
    for (int i = 0; i < length/2; i++)
        swap(array[i], array[length-i-1]);
}
