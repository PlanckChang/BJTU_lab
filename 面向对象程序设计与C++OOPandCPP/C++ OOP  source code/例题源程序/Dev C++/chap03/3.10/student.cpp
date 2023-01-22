#include"student.h"

CStudent::CStudent(int num, MyString & name, MyString & major, double score) 
	: number(num), name(name), major(major), score(score)
{
	//cout << "CStudent的有参构造函数被调用" << endl;
}

/*下面这个实现不好，调用该函数的执行过程是：首先调用MyString类默认构造函数构造学生类中的name和major成员（默认的初始化列表中的部分内容），然后执行该函数的函数体*/
//CStudent::CStudent(int num, MyString &name, MyString &major, double score):name(), major()
//{
//	number = num;
//	this->name = name;		//执行MyString类的赋值运算符函数
//	this->major = major;	//执行MyString类的赋值运算符函数
//	this->score = score;
//	cout << "CStudent的有参构造函数被调用" << endl;
//}


/*复制构造函数。调用该函数时的执行过程是：先调用MyString类的复制构造函数初始化学生类的成员name和major，然后执行函数体中的内容*/
CStudent::CStudent(const CStudent & stu)
	: number(stu.number), name(stu.name), major(stu.major), score(stu.score)
{
	cout << "CStudent的复制构造函数被调用" << endl;
}

/*下面这个实现不太好。调用该函数时的执行过程是：先调用MyString类的默认构造函数初始化学生类的成员name和major，然后执行函数体中的内容*/
//CStudent::CStudent(const CStudent & stu)
//{
//	number = stu.number;
//	name = stu.name;		//执行MyString类的赋值运算符函数
//	major = stu.major;		//执行MyString类的赋值运算符函数
//	score = stu.score;
//	cout << "CStudent的复制构造函数被调用" << endl;
//}

MyString & CStudent::set_name(const MyString & name)
{
	this->name = name;
	return this->name;
}

MyString & CStudent::set_major(const MyString & major)
{
	this->major = major;
	return this->major;
}
