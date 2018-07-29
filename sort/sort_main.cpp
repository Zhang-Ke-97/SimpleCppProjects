#include <iostream>
#include "sort.h"
#include "arrays.h"
/*
 * This is main file to test functions in arrays.h and sort.h
 * compile it with commandline :
 * g++ -o sort arrays.cpp sort.cpp sort_main.cpp -std=c++14 -Wall
 */
int main(int argc, char const *argv[]) {
    int a[] = {34, 1, 5, 10, 59, 40, 0, 12};
    std::cout << "Before reverse:" << '\n';
    showArray(a, LENGTH(a));

    reverseArray(a, LENGTH(a));
    std::cout << "After reverse:" << '\n';
    showArray(a, LENGTH(a));

    std::cout << "Before sort:" << '\n';
    showArray(a, LENGTH(a));

    std::cout << "sorting data" << '\n';
    quickSort(a, 0,LENGTH(a)-1);
    std::cout << "After sort:" << '\n';
    showArray(a, LENGTH(a));
    return 0;
}
