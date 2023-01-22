#include<list>
#include<iostream>
#include<algorithm>
#include"MyString.h"
using namespace std;

template<class T> void output(const T & v)
{
	cout << v << " ";
}

int main()
{
	list<int> v;
	v.push_back(1);	
	v.push_back(0);
	v.push_back(2);
	v.push_back(3);
	list<int>::iterator it = v.begin();
	++it;
	v.insert(it, 2);

	cout << "����ǰ�� ";
	for (it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;

	reverse(v.begin(), v.end()); // ����
	cout << "����� ";
	for_each(v.begin(), v.end(), output<int>);
	cout << endl;

	// ��ʾvector�ͺ��������
	list<MyString> v2;
	v2.push_back(MyString("11"));
	v2.push_back(MyString("00"));
	v2.push_back(MyString("22"));
	v2.push_back(MyString("22"));
	v2.push_back(MyString("33"));

	cout << "����ǰ�� ";
	for_each(v2.begin(), v2.end(), output<MyString>);
	cout << endl;

	reverse(v2.begin(), v2.end()); // ����
	cout << "����� ";
	for_each(v2.begin(), v2.end(), output<MyString>);
	cout << endl;

	return 0;
}