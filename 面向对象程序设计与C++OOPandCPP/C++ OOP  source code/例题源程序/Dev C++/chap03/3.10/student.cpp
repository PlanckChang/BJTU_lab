#include"student.h"

CStudent::CStudent(int num, MyString & name, MyString & major, double score) 
	: number(num), name(name), major(major), score(score)
{
	//cout << "CStudent���вι��캯��������" << endl;
}

/*�������ʵ�ֲ��ã����øú�����ִ�й����ǣ����ȵ���MyString��Ĭ�Ϲ��캯������ѧ�����е�name��major��Ա��Ĭ�ϵĳ�ʼ���б��еĲ������ݣ���Ȼ��ִ�иú����ĺ�����*/
//CStudent::CStudent(int num, MyString &name, MyString &major, double score):name(), major()
//{
//	number = num;
//	this->name = name;		//ִ��MyString��ĸ�ֵ���������
//	this->major = major;	//ִ��MyString��ĸ�ֵ���������
//	this->score = score;
//	cout << "CStudent���вι��캯��������" << endl;
//}


/*���ƹ��캯�������øú���ʱ��ִ�й����ǣ��ȵ���MyString��ĸ��ƹ��캯����ʼ��ѧ����ĳ�Աname��major��Ȼ��ִ�к������е�����*/
CStudent::CStudent(const CStudent & stu)
	: number(stu.number), name(stu.name), major(stu.major), score(stu.score)
{
	cout << "CStudent�ĸ��ƹ��캯��������" << endl;
}

/*�������ʵ�ֲ�̫�á����øú���ʱ��ִ�й����ǣ��ȵ���MyString���Ĭ�Ϲ��캯����ʼ��ѧ����ĳ�Աname��major��Ȼ��ִ�к������е�����*/
//CStudent::CStudent(const CStudent & stu)
//{
//	number = stu.number;
//	name = stu.name;		//ִ��MyString��ĸ�ֵ���������
//	major = stu.major;		//ִ��MyString��ĸ�ֵ���������
//	score = stu.score;
//	cout << "CStudent�ĸ��ƹ��캯��������" << endl;
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
