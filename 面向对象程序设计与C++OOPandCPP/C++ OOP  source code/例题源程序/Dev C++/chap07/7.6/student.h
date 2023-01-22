#pragma once
#include"MyString.h"

class CStudent
{
public:
	CStudent() : number(0), score(0) { /*cout << "CStudent的默认构造函数被调用" << endl;*/ }		//提供默认的构造函数，从而为new一个数组提供可能
	CStudent(const int num, const MyString & name, const MyString & major, const double score);
	virtual ~CStudent() { }		//为方便可能的派生，定义虚析构函数
	void set_number(int num) { number = num; }
	int get_number() const { return number; }		//该函数不改变成员的值，故设计为常成员函数
	MyString & set_name(const MyString & name);
	MyString & get_name() { return name; }			//返回引用，从而可以对name作进一步运算
	const MyString get_name() const { return name; }		//常成员函数返回值对象，给常对象使用；调用该函数时会调用MyString的复制构造函数初始化返回值对象，等返回语句执行完毕，会调用析构函数析构该临时对象
	MyString & set_major(const MyString & major);
	MyString & get_major() { return major; }
	const MyString get_major() const { return major; }
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

	//friend ostream & operator<<(ostream & o, const CStudent & s);

	//以二进制模式写文件
	virtual void write_binary(ostream & out) const
	{
		out.write((char*)&number, sizeof(int));	//写入学号
		name.write_binary(out);					//写入姓名
		major.write_binary(out);				//写入专业
		out.write((char*)&score, sizeof(double));	//写入成绩
	}

	//以二进制模式读文件
	virtual CStudent* read_binary(istream & in)
	{
		in.read((char*)&number, sizeof(int));    //读取学号
		name.read_binary(in);					 //读取名字
		major.read_binary(in);					 //读取专业
		in.read((char*)&score, sizeof(double));  //读取成绩
		return this;
	}

	virtual void show(ostream & o) const {
		o << number << "\t" << name << "\t" << major << "\t" << score;
	}

private:
	int  number;
	MyString name;
	MyString major;
	double score;
};

class CGraduate : public CStudent
{
public:
	CGraduate() { }
	CGraduate(const int number, const MyString & name,
		const MyString & major, const double score, const MyString & supervisor)
		: CStudent(number, name, major, score), supervisor(supervisor)
	{ }
	virtual ~CGraduate() { }
	MyString & get_supervisor() { return supervisor; }
	const MyString get_supervisor() const { return supervisor; }
	//MyString & set_supervisor(const char * p) { supervisor.set_string(p); return supervisor; }
	MyString & set_supervisor(const MyString & s) { supervisor = s; return supervisor; }

	//friend ostream & operator<<(ostream & o, const CGraduate & s);

	virtual void write_binary(ostream & out) const
	{
		this->CStudent::write_binary(out);
		supervisor.write_binary(out);
	}

	virtual CStudent * read_binary(istream & in)
	{
		this->CStudent::read_binary(in);
		supervisor.read_binary(in);
		return this;
	}

	virtual void show(ostream & o) const {
		CStudent::show(o);
		o << "\t" << supervisor;
	}

private:
	MyString supervisor;
};

