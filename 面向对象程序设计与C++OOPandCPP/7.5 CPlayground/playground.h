//
// Created by Planck Chang on 2021/11/29.
//

#ifndef INC_7_5_CPLAYGROUND_PLAYGROUND_H
#define INC_7_5_CPLAYGROUND_PLAYGROUND_H

#include "graph.h"
using namespace std;
class CPlayground
{
public:
    CPlayground(double lane_width = 3, double cost1 = 100.0, double cost2 = 80):
        g(NULL), lane(lane_width), COST1(cost1), COST2(cost2){}
    virtual ~CPlayground();
    CPlaygraph * attach_graph(const CPlaygraph *p);
    double compute_cost() const;

private:
    CPlayground(const CPlayground & pool);
    CPlayground & operator = (const CPlayground & pool);

    CPlaygraph *g;
    double lane;
    const double COST1;
    const double COST2;
};
#endif //INC_7_5_CPLAYGROUND_PLAYGROUND_H
