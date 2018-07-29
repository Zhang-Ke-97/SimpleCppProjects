#include <iostream>
#include "yanghui.h"
using namespace std;
#define SIZE 10
/* This programm use static long array to generate Yang Hui triangle
 * Compare with yanghui_main.cpp, which allocats all memory in heap,
 * this Programm allotes no heap memory for int*
 */
int main(int argc, char const *argv[]) {
    unsigned long* triangle [SIZE] = {NULL};

    show(triangle, SIZE);

    return 0;
}
