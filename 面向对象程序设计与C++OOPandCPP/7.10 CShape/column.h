//
// Created by Planck Chang on 2021/11/29.
//

#ifndef INC_7_10_CSHAPE_COLUMN_H
#define INC_7_10_CSHAPE_COLUMN_H

#include "shape.h"
using namespace std;

class CColumn
{
private:
    CShape *g;
    double height;
    CColumn(const CColumn & column);
    CColumn & operator = (const CColumn & column);

public:
   CColumn(CShape *shape, double h): g(shape), height(h){};
   double volume() {
       return g->area() * height;
   }
};

#endif //INC_7_10_CSHAPE_COLUMN_H
