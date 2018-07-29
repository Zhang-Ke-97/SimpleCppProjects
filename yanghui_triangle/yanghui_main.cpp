#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "yanghui.h"
using namespace std;

void go_on();

int main(int argc, char const *argv[]) {
    const int SIZE = (argc==2) ? atof(argv[1]):10;
    if (SIZE <=2) {
        cout << "SIZE is too small! Programm terminated." << endl;
        exit(1);
    }
    unsigned long** triangle = NULL;
    allocate_mem(&triangle, SIZE);
    set_two_sides(triangle, SIZE);
    show(triangle, SIZE);

    go_on();
    cout << "building part of the triangle" << endl;
    cal_part(triangle, SIZE, SIZE-1, 1);
    if (SIZE-2 > 0 && SIZE-4 > 0) {
        cal_part(triangle, SIZE, SIZE-1, SIZE-2);
        cal_part(triangle, SIZE, SIZE-1, SIZE-4);
    }
    show(triangle, SIZE);

    go_on();
    destroy(triangle, SIZE);    // destroy triangle before building a bigger one.
    cout << "building a bigger triangle..." << endl;
    // triangle = new unsigned long*;  // uncomment it and you'll see a WARNING while running
    build(&triangle, SIZE+5);
    show(triangle, SIZE+5);
    destroy(triangle, SIZE+5);

    return 0;
}

void go_on(){
    while(1){
        cout << "Enter 'c' to continue: "<< endl << ">> ";
        if (cin.get() == 'c'){
            while(cin.get()!='\n');
            break;
        }else{
            while(cin.get()!='\n');
        }
    }
}
