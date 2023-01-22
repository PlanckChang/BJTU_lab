//
// Created by Planck Chang on 2021/11/29.
//

#ifndef INC_7_5_CPLAYGROUND_GRAPH_H
#define INC_7_5_CPLAYGROUND_GRAPH_H

#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14159

class CPlaygraph
{
public:
    virtual ~CPlaygraph(){};

    virtual double full_area(const double ext = 0 ) const = 0;
    virtual double inner_area() const = 0;
};

class CRectgraph: public CPlaygraph
{
public:
    CRectgraph(const double len, const double w);
    double full_area(const double ext) const;
    double inner_area() const;
private:
    double length;
    double width;
};

class CCirclegraph: public CPlaygraph
{
public:
    CCirclegraph(double r);
    ~CCirclegraph(){};
    double full_area(const double ext) const;
    double inner_area() const;

private:
    double radius;
};
#endif //INC_7_5_CPLAYGROUND_GRAPH_H
