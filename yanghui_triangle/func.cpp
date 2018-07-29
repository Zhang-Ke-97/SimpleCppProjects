#include <iostream>
using namespace std;

void reverse(int*);
void swap(int&, int&);

int main(int argc, char const *argv[]) {
    int* a =  new int[10];
    for (size_t i = 0; i < 10; i++) {
        *(a+i) = i;
    }
    for (size_t i = 0; i < 10; i++) {
        cout << *(a+i) << ' ';
    }
    cout << endl;
    reverse(a);
    for (size_t i = 0; i < 10; i++) {
        cout << *(a+i) << ' ';
    }

    return 0;
}

void reverse(int* a) {
    for (size_t i = 0; i < 5; i++) {
        swap(a[i], a[9-i]);
    }
}

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}
