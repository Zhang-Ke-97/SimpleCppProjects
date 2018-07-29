#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include "geometry.h"

void go_on(){
    while(1){
        cout << "Enter 'c' to continue: "<< endl << ">> ";
        if (cin.get() == 'c'){
            while(cin.get()!='\n');
            cout << "_____________________________________________" << endl;
            break;
        }else{
            while(cin.get()!='\n');
        }
    };
}

void Point_2D::sayhello() {
    std::cout << "hello" << '\n';
}

Point_2D::Point_2D():x(0),y(0),PI(3.14159){
    cout << "creating Point_2D by default constructor..." << '\n';
}

Point_2D::Point_2D(double X, double Y):PI(3.14159){
    cout << "creating Point_2D..." << '\n';
    this->x = X;
    this->y = Y;
}

double Point_2D::get_x(){
    return x;
}

void Point_2D::set_x(double X){
    this->x = X;
}

double Point_2D::get_y(){
    return y;
}

void Point_2D::sayNo() {
    std::cout << "no" << '\n';
}
void Point_2D::set_y(double Y){
    this->y = Y;
}

void Point_2D::printInfo(){
    cout << "point 2D "<<"created at ("
         << x <<',' << y <<')' <<'\n';
}

double Point_2D::cal_distance(){
    return sqrt(x*x + y*y);
}

Point_2D Point_2D::operator+(Point_2D &v){
    double xx = this ->x + v.x;
    double yy = this ->y + v.y;
    return Point_2D(xx,yy);
}

double Point_2D::operator *(Point_2D &v) {
    return (this->x * v.x + this->y * v.y);
}


void Point_2D::show_info(){
    cout << "2D point" << endl;
}
Point_2D::~Point_2D(){
    cout << "Point_2D destroyed" << '\n';
}

Point_3D::Point_3D():z(0){
    cout << "creating Point_3D from default constructor..."<< endl;
}

Point_3D::Point_3D(double X, double Y, double Z): Point_2D(X, Y){
    cout << "creating Point_3D from parameter list..." << '\n';
    this->z = Z;
}

Point_3D::Point_3D(Point_2D p, double Z): Point_2D(p.get_x(), p.get_y()){
    cout << "creating Point_3D from a Point_2D..." << '\n';
    this->z = Z;
}

void Point_3D::printInfo() {
    cout << "3D point" << endl;
}
// FIX BUG p.x protected member of Point_2D
Point_3D::Point_3D(Point_2D* p, double Z): Point_2D(p->get_x(), p->get_y()){
    cout << "creating Point_3D from a pointer to Point_2D..." << '\n';
    this->z = Z;
}

double Point_3D::get_z(){
    return z;
}
void Point_3D::set_z(double Z){
    this->z = Z;
}

Point_3D Point_3D::operator +(Point_3D &v){
    return Point_3D(x+v.x, y+v.y, z+v.z);
}

double Point_3D::operator *(Point_3D &v){
    return (x*v.x + y*v.y + z*v.z);
}

double Point_3D::cal_distance(){
    return sqrt(x*x + y*y + z*z);
}

void Point_3D::show_info(){
    cout << "3D point created at ("
         << x << ", " << y << ", "<< z <<')'
         << endl;
}
Point_3D::~Point_3D(){
    cout << "Point_3D destroyed" << '\n';
}

Circle::Circle():Point_2D(),r(0){
    cout<<"creating circle by default constructor..."<<endl;
}

Circle::Circle(double X, double Y, double R):Point_2D(X, Y),r(R){
    cout<<"creating circle..."<<endl;
}

Circle::Circle(Point_2D p, double R):Point_2D(p.get_x(), p.get_y() ), r(R){
    cout<<"creating circle from Point_2D..."<<endl;
}

Circle::Circle(Circle &C):Point_2D(C.get_x(), C.get_y()), r(C.get_r()){
    cout<<"creating circle by copying..."<<endl;
}

double Circle::get_r(){
    return r;
}

void Circle::set_r(double R){
    r = R;
}

double Circle::cal_area(){
    if (r < 0) {
        cerr<<"Radius cannot be negative!"<<endl;
        exit(1);
    }
    return  M_PI*r*r;
}

void Circle::show_info(){
    cout << "Circle created at (" << x << ", " << y << ')'
         << ", with radius r = " << r << endl;

}

void Circle::printInfo(){
    cout << "Circle created at (" << x << ", " << y << ')'
         << ", with radius r = " << r << endl;
}

Circle::~Circle(){
    cout<<"circle distroyed"<<endl;
}

Cylinder::Cylinder(){
    cout << "creating Cylinder by using default constructor..." << endl;
}

Cylinder::Cylinder(double X, double Y, double R, double H):Circle(X,Y,R),h(H){
    cout << "creating Cylinder from parameter list" << endl;
}

Cylinder::Cylinder(Circle c, double H): Circle(c), h(H){
    cout << "creating Cylinder from a cirlcle" << endl;
}

Cylinder::Cylinder(Point_2D p, double R, double H): Circle(p, R), h(H){
    cout << "creating Cylinder from a 2D Point" << endl;
}

double Cylinder::get_h(){
    return h;
}

void Cylinder::set_h(double H){
    h = H;
}

double Cylinder::cal_volume(){
    double Cyl_A = this->Circle::cal_area();
    return Cyl_A*h;
}

void Cylinder::show_info(){
    cout << "Cylinder created at (" << x << ", " << y << ')'
         << ", with radius r = " << r
         << ", and height h = " << h << endl;
}

Cylinder:: ~Cylinder(){
    cout << "Cylinder destroyed" << endl;
}

Sphere::Sphere(Point_3D p, double R): Point_3D(p), r(R){
    cout << "creating sphere from a 3D point" << endl;
}

Sphere::Sphere():Point_3D(),r(0) {
    cout << "creating sphere from default consturctor..." << endl;
}

Sphere::Sphere(double X, double Y, double Z, double R):Point_3D(X,Y,Z), r(R) {
    cout << "creating sphere..." << endl;
}

double Sphere::cal_volume(){
    if (r < 0) {
        cerr<<"Radiu cannot be negative!"<<endl;
        exit(1);
    }
    return  4.0/3.0 * M_PI*pow(r,3.0);
}

void Sphere::show_info(){
    cout << "Sphere created at (" <<
         x << ", " << y << ", " << z << ')'
         << ", with radius r = " << r << endl;
}

Sphere::~Sphere(){
    cout << "Spere destroyed" << endl;
}
