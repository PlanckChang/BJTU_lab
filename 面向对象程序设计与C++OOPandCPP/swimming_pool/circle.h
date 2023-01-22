//
// Created by Planck Chang on 2021/10/28.
//

#ifndef SWIMMING_POOL_CIRCLE_H
#define SWIMMING_POOL_CIRCLE_H

#include <math.h>
using namespace std;

#define PI 3.14159

class CCircle
{
public:
    CCircle(double r):m_radius(r){};
    double full_area() const
    {
        return PI*(m_radius+3)*(m_radius);
    };
    double inner_area() const
    {
        return PI*m_radius*m_radius;
    };
    double full_circumference() const
    {
        return 2*PI*(m_radius+3);
    };
private:
    double m_radius;
};
#endif //SWIMMING_POOL_CIRCLE_H
