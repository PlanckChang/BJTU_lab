#include<iostream>
#include"MyString.h"
using namespace std;

int main()
{
	for (int i = 0; i < 1; i++)
	{
		MyString str;	//��DEV-C++�У���������ݳ�Աm_pbufĬ�ϱ���ʼ��NULL����˸ó����ܹ��������У�
		                //����VC++�в��Զ���m_pbuf��ʼ��ΪNULL����˸ó����޷����� 
		cout << "��Ĵ�С��" << sizeof(MyString) << endl;
		str.set_string("I love C++, ");
		cout << "�ַ������ȣ�" << str.get_length() << "\t"
			<< str.get_string() << "\t" 
			<< "�����С��" << sizeof(str) << endl;

		str.append("yeah!");
		cout << "�ַ������ȣ�" << str.get_length() << "\t"
			<< str.get_string() << "\t" 
			<< "�����С��" << sizeof(str) << endl;
	}

	return 0;
}
