#pragma once
#include"MyString.h"

class CStudent
{
public:
	CStudent() : number(0), score(0) { /*cout << "CStudent��Ĭ�Ϲ��캯��������" << endl;*/ }		//�ṩĬ�ϵĹ��캯�����Ӷ�Ϊnewһ�������ṩ����
	CStudent(int num, MyString & name, MyString & major, double score);
	CStudent(const CStudent & stu);
	//~CStudent() { cout << "CStudent����������������" << endl; }		//Ĭ�ϵ���������������ʡȥ
	void set_number(int num) { number = num; }
	int get_number() const { return number; }		//�ú������ı��Ա��ֵ�������Ϊ����Ա����
	MyString & set_name(const MyString & name);
	MyString & get_name() { return name; }			//�������ã��Ӷ����Զ�name����һ������
	MyString get_name() const { return name; }		//����Ա��������ֵ���󣬸�������ʹ�ã����øú���ʱ�����MyString�ĸ��ƹ��캯����ʼ������ֵ���󣬵ȷ������ִ����ϣ����������������������ʱ����
	MyString & set_major(const MyString & major);
	MyString & get_major() { return major; }
	MyString get_major() const { return major; }
	void set_score(double score) { this->score = score; }
	double get_score() const { return score; }
	//Ĭ�ϵĸ�ֵ�����
	CStudent & operator=(const CStudent & stu)
	{
		if (this != &stu)
		{
			number = stu.number;
			name = stu.name;		//����MyString��ĸ�ֵ���������
			major = stu.major;		//����MyString��ĸ�ֵ���������
			score = stu.score;
		}
		//cout << "CStudent�ĸ�ֵ���������������" << endl;
		return *this;
	}

	ofstream & write_text(ofstream & out)
	{
		out << number << " ";
		name.write_text(out);
		major.write_text(out);
		out << score << " ";
		return out;
	}

	ifstream & read_text(ifstream & in)
	{
		in >> number;
		in.get();
		name.read_text(in);
		major.read_text(in);
		in >> score;
		in.get();
		return in;
	}
private:
	int  number;
	MyString name;
	MyString major;
	double score;
};