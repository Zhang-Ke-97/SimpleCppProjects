
/**
 * This header file contains declarations of classes
 * Point_2D, Point_3D, Circle, Cylinder and Sphere
 */
#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include <string>
using std::string;

// normal function to control application
void go_on();

typedef class Point_2D{
private:
    string name;
protected:
    void sayNo();
    double x, y;
public:
    double const PI;

    Point_2D();
    Point_2D(double X, double Y);
    double get_x();
    void set_x(double X);
    double get_y();
    void set_y(double Y);
    void printInfo();
    void sayhello();

    Point_2D operator +(Point_2D &v);
    double operator *(Point_2D &v);

    virtual double cal_distance();
    virtual void show_info();
    virtual ~Point_2D();
} Vector_2D;

class Point_3D: public Point_2D{
private:
protected:
    double z;
public:
    Point_3D();
    Point_3D(double X, double Y, double Z);
    Point_3D(Point_2D p, double Z);
    Point_3D(Point_2D* p, double Z);
    double get_z();
    void set_z(double Z);
    void printInfo();

    Point_3D operator +(Point_3D &v);
    double operator *(Point_3D &v);

    virtual double cal_distance();
    virtual void show_info();
    virtual ~Point_3D();
};

class Circle: public Point_2D{
private:
protected:
    double r;
public:
    Circle();
    Circle(double X, double Y, double R);
    Circle(Point_2D, double );
    Circle(Circle &);
    double get_r();
    void set_r(double R);
    double cal_area();
    void printInfo();

    virtual void show_info();
    virtual ~Circle();
};

class Cylinder: public  Circle{
private:

protected:
    double h;
public:
    Cylinder();
    Cylinder(double X, double Y, double R, double H);
    Cylinder(Circle c, double H);
    Cylinder(Point_2D p, double R, double H);
    double get_h();
    double cal_volume();
    void set_h(double H);

    virtual void show_info();
    virtual ~Cylinder();

};
class Sphere: public Point_3D{
private:

protected:
    double r;
public:
    Sphere();
    Sphere(double X, double Y, double Z, double R);
    Sphere(Point_3D p, double R);
    double cal_volume();

    virtual void show_info();
    virtual ~Sphere();
};

#endif
