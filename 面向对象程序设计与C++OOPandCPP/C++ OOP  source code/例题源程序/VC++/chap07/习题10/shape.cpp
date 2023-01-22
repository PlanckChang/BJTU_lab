#include "shape.h"

CRectangle::CRectangle(const char * p, double h, double w) : CShape(p), height(h), width(w)
{
}

CRectangle::CRectangle(const CRectangle & r) : CShape(r), height(r.height), width(r.width)
{
}

double CRectangle::area()
{
	return height * width;
}

CCircle::CCircle(const char * p, double r) : CShape(p), radius(r)
{
}

CCircle::CCircle(const CCircle & c) : CShape(c), radius(c.radius)
{
}

double CCircle::area()
{
	return PI * radius * radius;
}

CTriangle::CTriangle(const char * p, double a, double b, double c) : CShape(p), s1(a), s2(b), s3(c)
{
}

CTriangle::CTriangle(const CTriangle & t) : CShape(t), s1(t.s1), s2(t.s2), s3(t.s3)
{
}

double CTriangle::area()
{
	double p = (s1 + s2 + s3) / 2;
	return pow(p * (p - s1) * (p - s2) * (p - s3), 0.5);
}
