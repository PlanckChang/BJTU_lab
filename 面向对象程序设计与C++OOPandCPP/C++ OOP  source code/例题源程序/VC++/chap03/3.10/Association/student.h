#pragma once
#include"MyString.h"

class CStudent
{
public:
	CStudent() : number(0), score(0) { /*cout << "CStudent的默认构造函数被调用" << endl;*/ }		//提供默认的构造函数，从而为new一个数组提供可能
	CStudent(int num, MyString & name, MyString & major, double score);
	CStudent(const CStudent & stu);
	//~CStudent() { cout << "CStudent的析构函数被调用" << endl; }		//默认的析构函数，可以省去
	void set_number(int num) { number = num; }
	int get_number() const { return number; }		//该函数不改变成员的值，故设计为常成员函数
	MyString & set_name(const MyString & name);
	MyString & get_name() { return name; }			//返回引用，从而可以对name作进一步运算
	MyString get_name() const { return name; }		//常成员函数返回值对象，给常对象使用；调用该函数时会调用MyString的复制构造函数初始化返回值对象，等返回语句执行完毕，会调用析构函数析构该临时对象
	MyString & set_major(const MyString & major);
	MyString & get_major() { return major; }
	MyString get_major() const { return major; }
	void set_score(double score) { this->score = score; }
	double get_score() const { return score; }
	//默认的赋值运算符
	CStudent & operator=(const CStudent & stu)
	{
		if (this != &stu)
		{
			number = stu.number;
			name = stu.name;		//调用MyString类的赋值运算符函数
			major = stu.major;		//调用MyString类的赋值运算符函数
			score = stu.score;
		}
		//cout << "CStudent的赋值运算符函数被调用" << endl;
		return *this;
	}

private:
	int  number;
	MyString name;
	MyString major;
	double score;
};