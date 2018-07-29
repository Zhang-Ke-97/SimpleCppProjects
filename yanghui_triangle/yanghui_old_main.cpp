#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

void show(int** triangle, int SIZE);
void build(int** &triangle, int SIZE);      // use reference to allocate memory
void build2(int*** triangle, int SIZE);     // use pointer to allocate memory
void destroy(int** &triangle, int SIZE);    // use reference to free memory
void destroy2(int*** triangle, int SIZE);   // use pointer to free memory

int main(int argc, char const *argv[]) {
    const int SIZE = (argc==2) ? atof(argv[1]):10;
    if (SIZE <=2) {
        cout << "SIZE is too small!" << endl;
        exit(1);
    }

    int** triangle = NULL;
    // build(triangle, SIZE);
    build2(&triangle, SIZE);
    show(triangle, SIZE);
    // destroy(triangle, SIZE);

    destroy2(&triangle, SIZE);
    return 0;
}

void show(int** triangle, int SIZE) {
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < i+1; j++) {
            cout << setw(6) << *(triangle[i]+j) << ' ';
        }
        cout << endl;
    }
}

void build(int** &triangle, int SIZE) {
    if (triangle!=NULL) delete triangle;
    triangle = new int*[SIZE];
    for (size_t i = 0; i < SIZE; i++) {
        triangle[i] = new int[i+1];
    }

    for (size_t i = 0; i < SIZE; i++) {
            *(triangle[i]) = 1;
            *(triangle[i] + i) = 1;
    }

    for (size_t i = 2; i < SIZE; i++) {
        for (size_t j = 1; j < i; j++) {
            *(triangle[i]+j ) = *(triangle[i-1]+j-1) + *(triangle[i-1]+j);
        }
    }
}

void build2(int*** triangle, int SIZE) {
    if (*triangle!=NULL) delete *triangle;
    *triangle = new int*[SIZE];
    for (size_t i = 0; i < SIZE; i++) {
        (*triangle)[i] = new int[i+1];
    }

    for (size_t i = 0; i < SIZE; i++) {
            (*triangle)[i][0] = 1;
            (*triangle)[i][i] = 1;
    }

    for (size_t i = 2; i < SIZE; i++) {
        for (size_t j = 1; j < i; j++) {
            (*triangle)[i][j] = (*triangle)[i-1][j-1] + (*triangle)[i-1][j];
        }
    }
}

void destroy(int** &triangle, int SIZE) {
    cout << "freeing all memory in heap..." << endl;
    for (size_t i = 0; i < SIZE; i++) {
        delete triangle[i];
    }
    delete triangle;
}

void destroy2(int*** triangle, int SIZE) {
    cout << "freeing all memory in heap..." << endl;
    for (size_t i = 0; i < SIZE; i++) {
        delete (*triangle)[i];
    }
    delete *triangle;
}
