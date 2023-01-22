#ifndef __PLAYGROUND_H__
#define __PLAYGROUND_H__
#include "graph.h"

class CPlayground
{
public:
	CPlayground(double lane_width = 3, double cost1 = 100.0, double cost2 = 80.0) 
		: g(NULL), lane(lane_width), COST1(cost1), COST2(cost2) { }
	////p所指向的是使用new构造的一个CPlaygraph类族的对象；CPlayground对象构造后，
	////p所指向的对象由上述CPlayground对象管理，即负责回收p所指向的内存
	//CPlayground(CPlaygraph * p, double lane, double cost1 = 100.0, double cost2 = 80.0);
	virtual ~CPlayground();
	//更改运动场的基本图形，返回之前的基本图形。p所指向的是使用new构造的一个
	//CPlaygraph类族的对象；函数调用后，p所指向的对象由CPlayground对象管理
	CPlaygraph * attach_graph(const CPlaygraph * p);
	//如果g是空指针则返回-1，否则返回造价
	double compute_cost() const;
private:
	CPlayground(const CPlayground & pool);	           //声明为私有函数，防止对象调用该函数
	CPlayground & operator=(const CPlayground & pool); //声明为私有函数，防止对象调用该函数

	CPlaygraph * g;
	double lane;
	const double COST1;		//运动场内部区域的建造单价
	const double COST2;		//运动场外部区域的建造单价
};

#endif