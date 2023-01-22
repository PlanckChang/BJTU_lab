#include "column.h"

int main()
{
	CShape * pShape = new CRectangle;
	cout << pShape->area() << endl;
	delete pShape;	//��ʾ�ȵ�������������������ٵ��û������������

	CCircle * p_c = new CCircle("circle", 3);
	CRectangle * p_r = new CRectangle("rect", 4, 7.5);
	CTriangle * p_t = new CTriangle("triangle", 3, 4, 5);
	
	CColumn column(p_c, 10);
	cout << "����ǣ�" << column.volume() << endl;

	CShape * p = column.attach(p_r);
	cout << "����ǣ�" << column.volume() << endl;
	delete p;

	p = column.attach(p_t);
	cout << "����ǣ�" << column.volume() << endl;
	delete p;

	//��������ϰ���������������д�뵽�ļ���Ȼ����ļ��ָ���Щ����Ĺ���

	return 0;
}


