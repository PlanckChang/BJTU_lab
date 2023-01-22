#include "Playground.h"

//CPlayground::CPlayground(CPlaygraph * p, double lane_width, double cost1, double cost2)
//	: g(p), lane(lane_width), COST1(cost1), COST2(cost2)
//{
//}

CPlayground::~CPlayground()
{
	delete g;
}

CPlaygraph * CPlayground::attach_graph(const CPlaygraph * p)
{
	CPlaygraph * old = g;
	g = (CPlaygraph*)p;
	return old;
}

double CPlayground::compute_cost() const
{	
	if (NULL != g)
	{
		double cost = 0.0;
		cost += g->inner_area() * COST1;
		cost += (g->full_area(lane) - g->inner_area()) * COST2;
		return cost;
	}
	else
		return -1;
}

