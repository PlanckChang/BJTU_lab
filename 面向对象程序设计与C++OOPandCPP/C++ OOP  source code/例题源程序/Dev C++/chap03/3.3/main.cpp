#include<iostream>
#include"MyString.h"
using namespace std;

int main()
{
	{	//例3.2的main函数的内容
		for (int i = 0; i < 1; i++)
		{
			MyString str;
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
	}

	{	//例3.2的main函数的内容（修改后的）
		MyString str;  // 调用不带参数的构造函数进行初始化
					   // 调用带一个字符指针参数的构造函数进行初始化
		MyString str2("I love C++, yeah！");
		// 调用不带参数的构造函数初始化每个对象，共调用3次无参构造函数，
		// 分别初始化str3[0]、str3[1]、str3[2] 
		MyString str3[3];

		return 0;
	}

	return 0;
}
