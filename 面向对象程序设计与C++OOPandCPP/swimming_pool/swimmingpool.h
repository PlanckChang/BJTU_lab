//
// Created by Planck Chang on 2021/10/28.
//

#ifndef SWIMMING_POOL_SWIMMINGPOOL_H
#define SWIMMING_POOL_SWIMMINGPOOL_H

#include "circle.h"
class CSwimmingPool
{
public:
    CSwimmingPool(CCircle &circle, double cost1 = 20, double cost2 = 35):circle(circle), COST1(cost1),
    COST2(cost2){};

    double fence_cost() const
    {
        return COST2*circle.full_circumference();
    };

    double passageway_cost() const
    {
        return COST1*(circle.full_area()-circle.inner_area());
    };


private:
    CCircle circle;
    const double COST1;  //过道造价
    const double COST2;  //栅栏造价
};
#endif //SWIMMING_POOL_SWIMMINGPOOL_H
