// 实验目的：演示对象的作用域、生存期和可见性
#include<iostream>
#include<vector>
#include"MyString.h"
using namespace std;

MyString g_str;  // g_str是全局变量；文件作用域；静态生存期；在数据段中
int main()
{
	//fun();
	MyString str; // str是局部变量；块作用域；动态生存期；块内可见；在栈中
	MyString * p_str;
	str.set_string("I love C++, ");
	cout << "字符串长度：" << str.get_length() << "\t"
		<< str.get_string() << endl;

	str.append("yeah!");
	cout << "字符串长度：" << str.get_length() << "\t"
		<< str.get_string() << endl;

	str.append();  // 使用了默认形参值
	cout << "字符串长度：" << str.get_length() << "\t"
		<< str.get_string() << endl;

	p_str = &str;  // 使用对象指针
	cout << "字符串长度：" << p_str->get_length() << "\t"
		<< p_str->get_string() << endl;

	str.append(str.get_string());
	cout << "字符串长度：" << str.get_length() << "\t"
		<< str.get_string() << endl;

	g_str.set_string("I am Lisi. ");
	g_str.append(str);
	cout << "字符串长度：" << g_str.get_length() << "\t"
		<< g_str.get_string() << endl;

	{
		static MyString str;  // 静态局部变量；块作用域；静态生存期；
							  // 块内可见，外层的str不可见；在数据段中
		str.append(::g_str);
		cout << "static字符串长度：" << str.get_length() << "\t"
			<< str.get_string() << endl;
	}

	return 0;
}
