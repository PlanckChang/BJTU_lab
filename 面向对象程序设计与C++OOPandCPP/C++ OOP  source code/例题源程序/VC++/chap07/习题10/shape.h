#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<iostream>
#include<math.h>
#include<fstream>
#include"MyString.h"

using namespace std;

#define PI 3.14159


class CShape
{
public:
	CShape() : name("shape") { }			//提供默认构造函数
	CShape(const char * p) : name(p) { }
	virtual ~CShape() { /*cout << "~CShape" << endl;*/ }  //即使没有使用堆上的内存也应该为基类提供虚析构函数
	virtual double area() = 0;

	//以文本模式保存和读取文件（二进制模式的请大家自行实现）
	virtual ostream & write_text(ostream & o)
	{
		name.write_text(o);
		return o;
	}

	virtual ifstream & read_text(ifstream & in)
	{
		name.read_text(in);
		return in;
	}
private:
	MyString name;
};

class CRectangle : public CShape
{
public:
	CRectangle() : CShape("rectangle"), height(0), width(0) { }
	CRectangle(const char * p, double h,double w);
	CRectangle(const CRectangle & r);
	~CRectangle() { /*cout << "~CRectangle" << endl;*/  }	//由于基类的析构函数是虚的，所以即使这里不声明为虚的，它也是虚的
	double area();

	//文本模式的文件读写
	virtual ostream & write_text(ostream & o)
	{
		CShape::write_text(o);
		o << " " << height << " " << width << " " << endl;
		return o;
	}

	virtual ifstream & read_text(ifstream & in)
	{
		CShape::read_text(in);
		in.get();
		in >> height >> width;
		in.get();
		return in;
	}
private:
	double height;
	double width;
}; 

class CCircle : public CShape
{
public:
	CCircle() : CShape("circle"), radius(0) { }
	CCircle(const char * p, double r);
	CCircle(const CCircle & c);
	~CCircle() { }
	double area();

	//文本模式的文件读写
	virtual ostream & write_text(ostream & o)
	{
		CShape::write_text(o);
		o << " " << radius << " " << endl;
		return o;
	}

	virtual ifstream & read_text(ifstream & in)
	{
		CShape::read_text(in);
		in.get();
		in >> radius;
		in.get();
		return in;
	}
private:
	double radius;
};

class CTriangle : public CShape
{
public:
	CTriangle() : CShape("triangle"), s1(0), s2(0), s3(0) { }
	CTriangle(const char * p, double a, double b, double c);
	CTriangle(const CTriangle & t);
	~CTriangle() { }
	double area();

	//文本模式的文件读写
	virtual ostream & write_text(ostream & o)
	{
		CShape::write_text(o);
		o << " " << s1 << " " << s2 << " " << s3 << " " << endl;
		return o;
	}

	virtual ifstream & read_text(ifstream & in)
	{
		CShape::read_text(in);
		in.get();
		in >> s1 >> s2 >> s3;
		in.get();
		return in;
	}
private:
	 double s1, s2, s3;
};

#endif
