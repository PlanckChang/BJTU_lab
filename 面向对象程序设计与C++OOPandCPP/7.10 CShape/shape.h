//
// Created by Planck Chang on 2021/11/29.
//

#ifndef INC_7_10_CSHAPE_SHAPE_H
#define INC_7_10_CSHAPE_SHAPE_H

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
#define PI 3.14159

class CShape
{
public:
    CShape(){};
    virtual double area() =0;

};

class CRectangle: public CShape
{
public:
    CRectangle(double len, double w):length(len), width(w){};
    double area(){
        return length * width;
    };
private:
    double length;
    double width;
};

class CCircle: public CShape
{
private:
    double radius;
public:
    CCircle(double r): radius(r){};
    double area(){
        return PI * radius * radius;
    };
};

class CTriangle: public CShape
{
private:
    double s1, s2, s3;
public:
    CTriangle(double a, double b, double c): s1(a), s2(b), s3(c){};
    double area(){
        double p = 0.5 * (s1 + s2 + s3);
        return pow(p* (p-s1) * (p-s2) * (p-s3), 0.5);
    }
};
#endif //INC_7_10_CSHAPE_SHAPE_H
