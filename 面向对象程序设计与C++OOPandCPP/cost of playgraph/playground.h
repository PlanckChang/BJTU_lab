//
// Created by Planck Chang on 2021/10/21.
//

#ifndef COST_OF_PLAYGRAPH_PLAYGROUND_H
#define COST_OF_PLAYGRAPH_PLAYGROUND_H
#include "graph.h"
class CPlayground{
public:
    CPlayground(CPlaygraph &g, double lane,
                double cost1 =100.0, double cost2 =80.0);

    double compute_cost() const;

private:
    CPlaygraph g;
    const double LANE;
    const double COST1;
    const double COST2;
};

#endif //COST_OF_PLAYGRAPH_PLAYGROUND_H
