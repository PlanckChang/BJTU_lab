#include "column.h"

int main()
{
	CShape * pShape = new CRectangle;
	cout << pShape->area() << endl;
	delete pShape;	//演示先调用派生类的析构函数再调用基类的析构函数

	CCircle * p_c = new CCircle("circle", 3);
	CRectangle * p_r = new CRectangle("rect", 4, 7.5);
	CTriangle * p_t = new CTriangle("triangle", 3, 4, 5);
	
	CColumn column(p_c, 10);
	cout << "体积是：" << column.volume() << endl;

	CShape * p = column.attach(p_r);
	cout << "体积是：" << column.volume() << endl;
	delete p;

	p = column.attach(p_t);
	cout << "体积是：" << column.volume() << endl;
	delete p;

	//请自行练习将各种柱体的数据写入到文件，然后从文件恢复这些柱体的功能

	return 0;
}


