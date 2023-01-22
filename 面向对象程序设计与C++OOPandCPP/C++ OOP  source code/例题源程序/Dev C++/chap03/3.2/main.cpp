#include<iostream>
#include"MyString.h"
using namespace std;

int main()
{
	for (int i = 0; i < 1; i++)
	{
		MyString str;	//在DEV-C++中，该类的数据成员m_pbuf默认被初始化NULL，因此该程序能够正常运行；
		                //但在VC++中不自动将m_pbuf初始化为NULL，因此该程序无法运行 
		cout << "类的大小：" << sizeof(MyString) << endl;
		str.set_string("I love C++, ");
		cout << "字符串长度：" << str.get_length() << "\t"
			<< str.get_string() << "\t" 
			<< "对象大小：" << sizeof(str) << endl;

		str.append("yeah!");
		cout << "字符串长度：" << str.get_length() << "\t"
			<< str.get_string() << "\t" 
			<< "对象大小：" << sizeof(str) << endl;
	}

	return 0;
}
