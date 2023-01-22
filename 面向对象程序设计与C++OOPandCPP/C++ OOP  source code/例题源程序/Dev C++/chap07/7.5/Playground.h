#ifndef __PLAYGROUND_H__
#define __PLAYGROUND_H__
#include "graph.h"

class CPlayground
{
public:
	CPlayground(double lane_width = 3, double cost1 = 100.0, double cost2 = 80.0) 
		: g(NULL), lane(lane_width), COST1(cost1), COST2(cost2) { }
	////p��ָ�����ʹ��new�����һ��CPlaygraph����Ķ���CPlayground�������
	////p��ָ��Ķ���������CPlayground����������������p��ָ����ڴ�
	//CPlayground(CPlaygraph * p, double lane, double cost1 = 100.0, double cost2 = 80.0);
	virtual ~CPlayground();
	//�����˶����Ļ���ͼ�Σ�����֮ǰ�Ļ���ͼ�Ρ�p��ָ�����ʹ��new�����һ��
	//CPlaygraph����Ķ��󣻺������ú�p��ָ��Ķ�����CPlayground�������
	CPlaygraph * attach_graph(const CPlaygraph * p);
	//���g�ǿ�ָ���򷵻�-1�����򷵻����
	double compute_cost() const;
private:
	CPlayground(const CPlayground & pool);	           //����Ϊ˽�к�������ֹ������øú���
	CPlayground & operator=(const CPlayground & pool); //����Ϊ˽�к�������ֹ������øú���

	CPlaygraph * g;
	double lane;
	const double COST1;		//�˶����ڲ�����Ľ��쵥��
	const double COST2;		//�˶����ⲿ����Ľ��쵥��
};

#endif