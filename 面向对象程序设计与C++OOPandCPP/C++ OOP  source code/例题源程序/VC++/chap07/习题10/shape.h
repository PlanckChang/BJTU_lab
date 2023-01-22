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
	CShape() : name("shape") { }			//�ṩĬ�Ϲ��캯��
	CShape(const char * p) : name(p) { }
	virtual ~CShape() { /*cout << "~CShape" << endl;*/ }  //��ʹû��ʹ�ö��ϵ��ڴ�ҲӦ��Ϊ�����ṩ����������
	virtual double area() = 0;

	//���ı�ģʽ����Ͷ�ȡ�ļ���������ģʽ����������ʵ�֣�
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
	~CRectangle() { /*cout << "~CRectangle" << endl;*/  }	//���ڻ����������������ģ����Լ�ʹ���ﲻ����Ϊ��ģ���Ҳ�����
	double area();

	//�ı�ģʽ���ļ���д
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

	//�ı�ģʽ���ļ���д
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

	//�ı�ģʽ���ļ���д
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
