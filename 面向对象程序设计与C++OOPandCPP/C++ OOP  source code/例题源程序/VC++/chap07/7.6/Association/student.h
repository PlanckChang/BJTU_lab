#pragma once
#include"MyString.h"

class CStudent
{
public:
	CStudent() : number(0), score(0) { /*cout << "CStudent��Ĭ�Ϲ��캯��������" << endl;*/ }		//�ṩĬ�ϵĹ��캯�����Ӷ�Ϊnewһ�������ṩ����
	CStudent(const int num, const MyString & name, const MyString & major, const double score);
	virtual ~CStudent() { }		//Ϊ������ܵ���������������������
	void set_number(int num) { number = num; }
	int get_number() const { return number; }		//�ú������ı��Ա��ֵ�������Ϊ����Ա����
	MyString & set_name(const MyString & name);
	MyString & get_name() { return name; }			//�������ã��Ӷ����Զ�name����һ������
	const MyString get_name() const { return name; }		//����Ա��������ֵ���󣬸�������ʹ�ã����øú���ʱ�����MyString�ĸ��ƹ��캯����ʼ������ֵ���󣬵ȷ������ִ����ϣ����������������������ʱ����
	MyString & set_major(const MyString & major);
	MyString & get_major() { return major; }
	const MyString get_major() const { return major; }
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

	//friend ostream & operator<<(ostream & o, const CStudent & s);

	//�Զ�����ģʽд�ļ�
	virtual void write_binary(ostream & out) const
	{
		out.write((char*)&number, sizeof(int));	//д��ѧ��
		name.write_binary(out);					//д������
		major.write_binary(out);				//д��רҵ
		out.write((char*)&score, sizeof(double));	//д��ɼ�
	}

	//�Զ�����ģʽ���ļ�
	virtual CStudent* read_binary(istream & in)
	{
		in.read((char*)&number, sizeof(int));    //��ȡѧ��
		name.read_binary(in);					 //��ȡ����
		major.read_binary(in);					 //��ȡרҵ
		in.read((char*)&score, sizeof(double));  //��ȡ�ɼ�
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

