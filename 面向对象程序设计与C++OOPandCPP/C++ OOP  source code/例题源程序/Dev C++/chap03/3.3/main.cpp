#include<iostream>
#include"MyString.h"
using namespace std;

int main()
{
	{	//��3.2��main����������
		for (int i = 0; i < 1; i++)
		{
			MyString str;
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
	}

	{	//��3.2��main���������ݣ��޸ĺ�ģ�
		MyString str;  // ���ò��������Ĺ��캯�����г�ʼ��
					   // ���ô�һ���ַ�ָ������Ĺ��캯�����г�ʼ��
		MyString str2("I love C++, yeah��");
		// ���ò��������Ĺ��캯����ʼ��ÿ�����󣬹�����3���޲ι��캯����
		// �ֱ��ʼ��str3[0]��str3[1]��str3[2] 
		MyString str3[3];

		return 0;
	}

	return 0;
}
