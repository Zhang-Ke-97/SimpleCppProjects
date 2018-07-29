#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "geometry.h"
#define SIZE 10
#define LENGTH(a) (int)(sizeof(a)/sizeof(a[0]))

struct Usr_input {
    double x;
    double y;
    double z;
    double r;
    double h;
};

int main(int argc, char const *argv[]) {
    cout << "Five classes have been defined:" << endl;
    cout << "size of Point_2D = " << sizeof(Point_2D) << endl;
    cout << "size of Point_3D = " << sizeof(Point_3D) << endl;
    cout << "size of Circle = " << sizeof(Circle) << endl;
    cout << "size of Cylinder = " << sizeof(Cylinder) << endl;
    cout << "size of Sphere = " << sizeof(Sphere) << endl;

    go_on();
    cout << "allocate memory for other[ ] and shapes[ ]:" << endl;
    int shape_count = 0;
    Point_2D* shapes[SIZE] = {NULL};
    shapes[shape_count] = new Point_3D(12,3,6);
    shape_count++;
    shapes[shape_count] = new Cylinder(0,0,2,4);
    shape_count++;
    shapes[shape_count] = new Sphere(0,0,0,1);
    shape_count++;

    Point_2D* other[] = {
        new Point_2D(1,1),
        new Circle(2,2,6),
        new Cylinder(1,1,1,1),
    };
    cout <<endl
         << "memory details about shapes[ ]:" << endl;
    for(int i=0; i<LENGTH(shapes); i++){
        cout << "address: " << &shapes[i]/* <<' ' << shapes+i */
             << ", value: " << shapes[i]/* << ' ' << *(shapes+i) */
            //<< "size of shapes [" << i << "] = "
            // << (int)sizeof(shapes[i])
             << endl;
    }
    cout <<endl
         << "memory details about other[ ]:" << endl;
    for(int i=0; i<LENGTH(other); i++){
        cout << "address: " << &other[i]/* <<' ' << other+i */
             << ", value: " << other[i]/* << ' ' << *(other+i) */<< endl;
    }
    go_on();
    cout << "copying other[ ] to shapes[ ]:" << endl;
    memcpy(shapes+shape_count, other, sizeof(other));

    cout << "memory details about shape[10]:" << endl;
    for(int i=0; i<LENGTH(shapes); i++){
        cout << "address: " << &shapes[i]/* <<' ' << shapes+i */
             << ", value: " << shapes[i]/* << ' ' << *(shapes+i) */ << endl;
    }

    go_on();
    cout << "freeing memory..." << endl;

    for (int i = 0; i < SIZE; i++) {
        if (shapes+i != NULL) {
            delete *(shapes+i);
        }
    }

    return 0;
}
