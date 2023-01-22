// 实验目的：演示对象的作用域、生存期和可见性

#include<iostream>
#include<iomanip>
#include<fstream>
#include"MyString.h"
using namespace std;

int main()
{
	MyString str;
	str.set_string("I love C++, yeah!");
	cout << str << endl;	//可像基本数据类型一样直接输出str的内容
	return 0;
}
