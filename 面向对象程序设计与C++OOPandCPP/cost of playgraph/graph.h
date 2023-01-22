//
// Created by Planck Chang on 2021/10/21.
//

#ifndef COST_OF_PLAYGRAPH_GRAPH_H
#define COST_OF_PLAYGRAPH_GRAPH_H
#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14159

class CPlaygraph{
public:
    CPlaygraph(const double len, const double w);

    double full_area(const double ext = 0) const;
    double inner_area() const;

private:
    double m_length;
    double m_width;
};
#endif //COST_OF_PLAYGRAPH_GRAPH_H
