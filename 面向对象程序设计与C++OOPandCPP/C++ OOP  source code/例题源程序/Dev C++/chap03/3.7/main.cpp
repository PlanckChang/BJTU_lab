// ʵ��Ŀ�ģ���ʾ��ľ�̬��Ա

#include<iostream>
#include"MyString.h"
using namespace std;

int main()
{
    cout << MyString::get_total() << endl; // ��ʱ���Ϊ0
    MyString str;  // ���ò��������Ĺ��캯�����г�ʼ��
    cout << str.get_total() << endl;  // ��ʱ���Ϊ1
    {
        MyString str2(str);
        cout << str2.get_total() << endl;  // ��ʱ���Ϊ2
    }
    cout << str.get_total() << endl;  // ��ʱ���Ϊ1

    return 0;
}