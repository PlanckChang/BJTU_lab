#include<vector>
#include<iostream>
#include<algorithm>
#include"MyString.h"
using namespace std;

bool larger(int a, int b)
{
	return a > b;  //����ʹ��>=����sort�㷨�п��ܻ������д���
}

template<class T> class CLarger  // ������ģ��
{
public:
	bool operator()(const T & a, const T & b)
	{
		return  a > b;
	}
};

void output_int(int i) { cout << i << " "; }
template<class T> void output(const T & v) { cout << v << " "; }

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(3);
	v.insert(v.begin() + 2, 0);
	v.insert(v.begin(), 2);

	cout << "����ǰ�� ";
	vector<int>::iterator iter;
	for(iter = v.begin(); iter < v.end(); iter++)
		cout << *iter << " " ;
	cout << endl;

	sort(v.begin(), v.end(), larger); //ʹ����ͨ�����Ӵ�С����
	cout << "�Ӵ�С����� ";
	for_each(v.begin(), v.end(), output_int);   //ʹ��for_each�㷨����ͨ�������
	cout << endl;

	v.erase(v.end() - 1);
	sort(v.begin(), v.end(), std::less<>()); //ʹ��STL���������С��������
	cout << "��С��������� ";
	for_each(v.begin(), v.end(), output<int>);   //ʹ��for_each�㷨��ģ�庯�����
	cout << endl;

	sort(v.begin(), v.end(), CLarger<int>());   //ʹ���Զ��庯������Ӵ�С����
	cout << "�Ӵ�С����� ";
	for_each(v.begin(), v.end(), output<int>);  //ʹ��for_each�㷨��ģ�庯�����
	cout << endl;

	vector<MyString> v2;    //Ҳ�������������ͣ��˴�ʹ��MyString����
	v2.push_back(MyString("11"));
	v2.push_back(MyString("00"));
	v2.push_back(MyString("22"));
	v2.push_back(MyString("22"));
	v2.push_back(MyString("33"));

	cout << "����ǰ�� ";
	for_each(v2.begin(), v2.end(), output<MyString>);  //ʹ��for_each�㷨ʵ��ѭ��
	cout << endl;

	sort(v2.begin(), v2.end(), CLarger<MyString>());   //ʹ���Զ��庯������Ӵ�С����
	cout << "�Ӵ�С����� ";
	for_each(v2.begin(), v2.end(), output<MyString>);  //ʹ��for_each�㷨��ģ�庯�����
	cout << endl;

	return 0;
}