//
// Created by Planck Chang on 2021/11/29.
//

#include "playground.h"
CPlayground:: ~CPlayground(){
    delete g;
}

CPlaygraph * CPlayground::attach_graph(const CPlaygraph *p) {
    CPlaygraph * old = g;
    g = (CPlaygraph* ) p;
    return old;
}

double CPlayground::compute_cost() const {
    if( g != NULL)
    {
        double cost = 0.0;
        cost += g->inner_area() * COST1;
        cost += (g->full_area(lane)- g->inner_area())*COST2;
        return cost;
    }
    else
        return -1;
}
#include "playground.h"
