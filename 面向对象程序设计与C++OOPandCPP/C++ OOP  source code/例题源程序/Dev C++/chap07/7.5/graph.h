#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<iostream>
#include<math.h>

using namespace std;

#define PI 3.14159

class CPlaygraph
{
public:
	virtual double full_area(const double ext = 0) const = 0;	//����ͼ��������չext������
	virtual double inner_area() const = 0; //�����м���ε����
};

class CRectgraph : public CPlaygraph
{
public:
	CRectgraph(const double len, const double w);
	double full_area(const double ext) const;	//����ͼ��������չext������
	double inner_area() const; //�����м���ε����
private:
	double length;
	double width;
}; 

class CCirclegraph : public CPlaygraph
{
public:
	CCirclegraph(double r);
	double full_area(const double ext) const;	//����ͼ��������չext������
	double inner_area() const; //�����м���ε����
private:
	double radius;
};

#endif
