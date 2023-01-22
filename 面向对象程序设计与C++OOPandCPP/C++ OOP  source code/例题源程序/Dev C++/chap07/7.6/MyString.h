#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
#include<cstring> 
using namespace std;

class MyString
{
public:
	MyString();
	MyString(const char * p);
	MyString(const MyString & s);
	~MyString();
	MyString & operator=(const MyString & s);

	const char * get_string() const { return m_pbuf; }	// ȡ���ַ������׵�ַ
	const char * set_string(const char * p = NULL);	// �� p ָ����ַ���������MyString����
	const char * append(const char * p = NULL);		// �� p ָ����ַ���׷�ӵ�ԭ���ַ���֮��
	MyString & append(MyString & s);				// �� s �����е��ַ���׷�ӵ���ǰ������ַ���֮�󲢷��ض���
	int get_length() const { return strlen(m_pbuf); }		// ȡ�ñ�����ַ����ĳ���

	friend ostream & operator<< (ostream & o, const MyString & s);	// ��������ı�ģʽ

	void write_binary(ostream & o) const	// ������ģʽ�������
	{
		int len = strlen(m_pbuf);			// ȡ���ַ���ռ�õĿռ�Ĵ�С�����ַ����ĳ���
		o.write((char *)&len, sizeof(int));	// ���������д���ַ�����ռ�ռ�Ĵ�С
		o.write(m_pbuf, len);				// ��m_pbuf��ʼд��len���ֽڣ�ע�⣺���һ�����ַ�δд��
	}

	MyString & read_binary(istream & in)	// ������ģʽ��ȡ����
	{
		delete[] m_pbuf;  //���Ȼ���֮ǰ���ڴ�
		int len;
		in.read((char *)&len, sizeof(int));	//�ȶ�ȡ��Ҫ��ȡ���ַ����ĳ���
		m_pbuf = new char[len + 1];			//׼���������ݵĿռ䣺Ҫ��һ���ֽ����ڱ������ַ�
		in.read(m_pbuf, len);				//��ȡlen���ֽڵ�m_pbufָ��Ŀռ�
		m_pbuf[len] = '\0';					//�������Ͻ�β����

		return *this;
	}

private:
	char * m_pbuf;
};

#endif
