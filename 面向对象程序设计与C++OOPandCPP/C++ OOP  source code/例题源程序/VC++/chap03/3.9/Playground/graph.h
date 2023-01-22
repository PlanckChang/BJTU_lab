#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<iostream>
#include<math.h>

using namespace std;

#define PI 3.14159

/*class CGraph
{
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;
};
*/
class CPlaygraph //: public CGraph
{
public:
	CPlaygraph(const double len, const double w);
	double full_area(const double ext = 0) const;	//计算图形向外扩展ext后的面积
	double inner_area() const; //计算中间矩形的面积
private:
	double m_length;
	double m_width;
}; 
/*
class CCircle : public CGraph
{
public:
	CCircle(double r);
	CCircle(const CCircle & c);
	double area();
	double perimeter();
private:
	double radius;
};

class CTriangle : public CGraph
{
public:
	CTriangle(double a, double b, double c);
	CTriangle(const CTriangle & t);
	double area();
	double perimeter();
private:
	 double s1, s2, s3;
};
*/
#endif
