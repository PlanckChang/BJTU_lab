#pragma once
#include "shape.h"

class CColumn
{
public:
	// 将形参p指向的空间（必须在堆中分配）交给CColumn类管理，此时该类的g指针指向上述内存
	CColumn(CShape * p, double h) : g(p), height(h) { }

	virtual ~CColumn() { if (g != NULL) delete g; }
	double volume() { return g->area() * height; }
	CShape * attach(CShape * p) { CShape * tmp = g; g = p; return tmp; }

	//对于文件读写，由于无法预测其图形类到底是什么，所以只能通过调用对应的虚函数完成读写
	//对于指示具体图形类型的标记，应该在类的外部确定
	ostream & write_text(ostream & o)
	{
		g->write_text(o);
		o << height << " ";
		return o;
	}

	ifstream & read_text(ifstream & in)
	{
		g->read_text(in);
		in >> height;
		in.get();
		return in;
	}
private:
	CColumn(const CColumn & );	           //声明为私有函数，防止对象调用该函数
	CColumn & operator=(const CColumn & ); //声明为私有函数，防止对象调用该函数

	CShape * g;
	double height;
};


