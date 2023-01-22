#ifndef __PLAYGROUND_H__
#define __PLAYGROUND_H__
#include "graph.h"

class CPlayground
{
public:
	CPlayground(CPlaygraph & g, double lane, double cost1 = 100.0, double cost2 = 80.0);
	/*virtual*/ //~CPlayground();
	//double area() const;
	//double perimeter() const;
	double compute_cost() const;
private:
	//CSwimPool(const CSwimPool & pool);	           //����Ϊ˽�к�������ֹ������øú���
	//CSwimPool & operator=(const CSwimPool & pool); //����Ϊ˽�к�������ֹ������øú���
	/*CGraph*/CPlaygraph g;
	const double LANE;
	const double COST1;		//���򳡵Ľ��쵥��
	const double COST2;		//�������ֵĽ��쵥��
};

#endif