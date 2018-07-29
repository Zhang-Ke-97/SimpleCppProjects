#ifndef _ARRAYS_H_
#define _ARRAYS_H_ 1
#define LENGTH(array) (int)(sizeof(array)/sizeof(array[0]))

/*
 * following functions are not for sorting,
 * they will be called by other functions
 */
void swap(int* a, int* b);

void swap(int &a, int &b);

void showArray(int* array, int length);

void reverseArray(int* array, int length);

void swapItems(int* array, int i, int j);

#endif
