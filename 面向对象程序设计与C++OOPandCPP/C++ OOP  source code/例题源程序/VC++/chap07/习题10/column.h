#pragma once
#include "shape.h"

class CColumn
{
public:
	// ���β�pָ��Ŀռ䣨�����ڶ��з��䣩����CColumn�������ʱ�����gָ��ָ�������ڴ�
	CColumn(CShape * p, double h) : g(p), height(h) { }

	virtual ~CColumn() { if (g != NULL) delete g; }
	double volume() { return g->area() * height; }
	CShape * attach(CShape * p) { CShape * tmp = g; g = p; return tmp; }

	//�����ļ���д�������޷�Ԥ����ͼ���ൽ����ʲô������ֻ��ͨ�����ö�Ӧ���麯����ɶ�д
	//����ָʾ����ͼ�����͵ı�ǣ�Ӧ��������ⲿȷ��
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
	CColumn(const CColumn & );	           //����Ϊ˽�к�������ֹ������øú���
	CColumn & operator=(const CColumn & ); //����Ϊ˽�к�������ֹ������øú���

	CShape * g;
	double height;
};


