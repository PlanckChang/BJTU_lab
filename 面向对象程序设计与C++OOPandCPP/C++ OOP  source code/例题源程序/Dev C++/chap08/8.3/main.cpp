#include<vector>
#include<iostream>
#include<algorithm>
#include"MyString.h"
using namespace std;

bool larger(int a, int b)
{
	return a > b;  //这里使用>=，在sort算法中可能会有运行错误
}

template<class T> class CLarger  // 函数类模板
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

	cout << "排序前： ";
	vector<int>::iterator iter;
	for(iter = v.begin(); iter < v.end(); iter++)
		cout << *iter << " " ;
	cout << endl;

	sort(v.begin(), v.end(), larger); //使用普通函数从大到小排序
	cout << "从大到小排序后： ";
	for_each(v.begin(), v.end(), output_int);   //使用for_each算法和普通函数输出
	cout << endl;

	v.erase(v.end() - 1);
	sort(v.begin(), v.end(), std::less<int>()); //使用STL函数对象从小到大排序
	cout << "从小到大排序后： ";
	for_each(v.begin(), v.end(), output<int>);   //使用for_each算法和模板函数输出
	cout << endl;

	sort(v.begin(), v.end(), CLarger<int>());   //使用自定义函数对象从大到小排序
	cout << "从大到小排序后： ";
	for_each(v.begin(), v.end(), output<int>);  //使用for_each算法和模板函数输出
	cout << endl;

	vector<MyString> v2;    //也适用于其他类型，此处使用MyString类型
	v2.push_back(MyString("11"));
	v2.push_back(MyString("00"));
	v2.push_back(MyString("22"));
	v2.push_back(MyString("22"));
	v2.push_back(MyString("33"));

	cout << "排序前： ";
	for_each(v2.begin(), v2.end(), output<MyString>);  //使用for_each算法实现循环
	cout << endl;

	sort(v2.begin(), v2.end(), CLarger<MyString>());   //使用自定义函数对象从大到小排序
	cout << "从大到小排序后： ";
	for_each(v2.begin(), v2.end(), output<MyString>);  //使用for_each算法和模板函数输出
	cout << endl;

	return 0;
}
