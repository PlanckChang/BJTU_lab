#include "graph.h"

//CRectgraph类的实现-----------------------------
CRectgraph::CRectgraph(const double len, const double w) : length(len), width(w)
{
}

double CRectgraph::full_area(double ext) const
{
	return length * (width + 2 * ext) + PI * (width / 2 + ext) * (width / 2 + ext);
}

double CRectgraph::inner_area() const
{
	return length * width;
}

//CCirclegraph类的实现---------------------------
CCirclegraph::CCirclegraph(double r) : radius(r)
{
}

double CCirclegraph::full_area(double ext) const
{
	return PI * (radius + ext) * (radius + ext);
}

double CCirclegraph::inner_area() const
{
	return PI * radius * radius;
}
