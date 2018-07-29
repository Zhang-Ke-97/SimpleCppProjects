#include <iostream>
#include "sort.h"
#include "arrays.h"

void bubbleSort(int* array, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length-i; j++) {
            if (array[j]>array[j+1]) swap(array+j,array+j+1);
        }
    }
}

void quickSort(int* array, int low, int high) {
    if (low >= high) {
        return;
    }
    int lowOld = low ,highOld = high;
    int midValue = array[low];
    while (low < high) {
        while (low < high) { // run from right to left
            if (array[high] >= midValue) {
                high--;
            }else{
                array[low] = array[high];
                break;
            }
        }
        while (low < high) { // run from left to right
            if (array[low] <= midValue) {
                low++;
            }else{
                array[high] = array[low];
                break;
            }
        }
    }
    // here we have low == high,
    // if not, the following if statement will show us a BUG
    if (low == high){
        std::cout << "low == high == " << low << '\n';
    }else{
        std::cout << "FIX BUG:  low == " << low
                  << ", high == " << high << '\n';
    }
    array[low] = midValue;
    quickSort(array, lowOld, low-1);
    quickSort(array, high+1, highOld);
}
