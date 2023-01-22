#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<iostream>
#include<math.h>

using namespace std;

#define PI 3.14159

class CPlaygraph
{
public:
	virtual double full_area(const double ext = 0) const = 0;	//计算图形向外扩展ext后的面积
	virtual double inner_area() const = 0; //计算中间矩形的面积
};

class CRectgraph : public CPlaygraph
{
public:
	CRectgraph(const double len, const double w);
	double full_area(const double ext) const;	//计算图形向外扩展ext后的面积
	double inner_area() const; //计算中间矩形的面积
private:
	double length;
	double width;
}; 

class CCirclegraph : public CPlaygraph
{
public:
	CCirclegraph(double r);
	double full_area(const double ext) const;	//计算图形向外扩展ext后的面积
	double inner_area() const; //计算中间矩形的面积
private:
	double radius;
};

#endif
