// ʵ��Ŀ�ģ���ʾ����������������ںͿɼ���
#include<iostream>
#include<vector>
#include"MyString.h"
using namespace std;

MyString g_str;  // g_str��ȫ�ֱ������ļ������򣻾�̬�����ڣ������ݶ���
int main()
{
	//fun();
	MyString str; // str�Ǿֲ��������������򣻶�̬�����ڣ����ڿɼ�����ջ��
	MyString * p_str;
	str.set_string("I love C++, ");
	cout << "�ַ������ȣ�" << str.get_length() << "\t"
		<< str.get_string() << endl;

	str.append("yeah!");
	cout << "�ַ������ȣ�" << str.get_length() << "\t"
		<< str.get_string() << endl;

	str.append();  // ʹ����Ĭ���β�ֵ
	cout << "�ַ������ȣ�" << str.get_length() << "\t"
		<< str.get_string() << endl;

	p_str = &str;  // ʹ�ö���ָ��
	cout << "�ַ������ȣ�" << p_str->get_length() << "\t"
		<< p_str->get_string() << endl;

	str.append(str.get_string());
	cout << "�ַ������ȣ�" << str.get_length() << "\t"
		<< str.get_string() << endl;

	g_str.set_string("I am Lisi. ");
	g_str.append(str);
	cout << "�ַ������ȣ�" << g_str.get_length() << "\t"
		<< g_str.get_string() << endl;

	{
		static MyString str;  // ��̬�ֲ��������������򣻾�̬�����ڣ�
							  // ���ڿɼ�������str���ɼ��������ݶ���
		str.append(::g_str);
		cout << "static�ַ������ȣ�" << str.get_length() << "\t"
			<< str.get_string() << endl;
	}

	return 0;
}
