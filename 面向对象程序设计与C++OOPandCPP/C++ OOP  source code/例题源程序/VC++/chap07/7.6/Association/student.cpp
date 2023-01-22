#include"student.h"
using namespace std;

//ostream & operator<<(ostream & o, const CStudent & s)
//{
//	o << s.number << " " << s.name << " " << s.major << " " << s.score << endl;
//	return o;
//}

CStudent::CStudent(const int num, const MyString & name, const MyString & major, const double score)
	: number(num), name(name), major(major), score(score)
{
	//cout << "CStudent的有参构造函数被调用" << endl;
}

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

//ostream & operator<<(ostream & o, const CGraduate & s)
//{
//	o << (CStudent)s;
//	o << s.get_supervisor() << endl;
//	return o;
//}