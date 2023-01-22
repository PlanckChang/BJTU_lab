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
	//CSwimPool(const CSwimPool & pool);	           //声明为私有函数，防止对象调用该函数
	//CSwimPool & operator=(const CSwimPool & pool); //声明为私有函数，防止对象调用该函数
	/*CGraph*/CPlaygraph g;
	const double LANE;
	const double COST1;		//足球场的建造单价
	const double COST2;		//其他部分的建造单价
};

#endif