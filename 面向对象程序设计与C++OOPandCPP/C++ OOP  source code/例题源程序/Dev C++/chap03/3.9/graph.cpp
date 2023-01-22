#include "graph.h"

CPlaygraph::CPlaygraph(const double len, const double w) : m_length(len), m_width(w)
{
}

double CPlaygraph::full_area(double ext) const
{
	return m_length * (m_width + 2 * ext) + PI * (m_width / 2 + ext) * (m_width / 2 + ext);
}

double CPlaygraph::inner_area() const
{
	return m_length * m_width;
}

/*
CCircle::CCircle(double r) : radius(r)
{
}

CCircle::CCircle(const CCircle & c) : radius(c.radius)
{
}

double CCircle::area()
{
	return PI * radius * radius;
}

double CCircle::perimeter()
{
	return 2 * PI * radius;
}

CTriangle::CTriangle(double a, double b, double c) : s1(a), s2(b), s3(c)
{
}

CTriangle::CTriangle(const CTriangle & t) : s1(t.s1), s2(t.s2), s3(t.s3)
{
}

double CTriangle::area()
{
	double p = (s1 + s2 + s3) / 2;
	return pow(p * (p - s1) * (p - s2) * (p - s3), 0.5);
}

double CTriangle::perimeter()
{
	return s1 + s2 + s3;
}
*/