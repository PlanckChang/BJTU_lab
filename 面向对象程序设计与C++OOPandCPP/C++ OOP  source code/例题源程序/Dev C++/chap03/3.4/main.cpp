// ʵ��Ŀ�ģ���ʾ���ƹ��캯����ʹ�ú͸�ֵ�������ʹ��

#include<iostream>
#include"MyString.h"
using namespace std;
MyString print(MyString str)
{
	cout << str.get_string() << endl;
	return str;
}

//int main()
//{
//	MyString str1("I love C++, yeah!");
//	MyString str2(str1);
//	print(str2);
//	return 0;
//}

int main()
{
    MyString str("I love C++, yeah!");
    {
        MyString str2(str);
        cout << str2.get_string() << endl;
    }
    cout << str.get_string() << endl;

	//MyString str3;
	//str3 = str;

	return 0;
}