#include "Playground.h"

CPlayground::CPlayground(CPlaygraph & g, double lane, double cost1, double cost2)
	: g(g), LANE(lane), COST1(cost1), COST2(cost2)
{
}

double CPlayground::compute_cost() const
{
	double cost = 0.0;
	cost += g.inner_area() * COST1;
	cost += (g.full_area(LANE) - g.inner_area()) * COST2;
	return cost;
}

//CPlayground::~CPlayground()
//{
//}
