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

	const char * get_string() const { return m_pbuf; }	// 取得字符串的首地址
	const char * set_string(const char * p = NULL);	// 将 p 指向的字符串保存在MyString类中
	const char * append(const char * p = NULL);		// 将 p 指向的字符串追加到原有字符串之后
	MyString & append(MyString & s);				// 将 s 对象中的字符串追加到当前对象的字符串之后并返回对象
	int get_length() const { return strlen(m_pbuf); }		// 取得保存的字符串的长度

	friend ostream & operator<< (ostream & o, const MyString & s);	// 插入符，文本模式

	void write_binary(ostream & o) const	// 二进制模式输出函数
	{
		int len = strlen(m_pbuf);			// 取得字符串占用的空间的大小，即字符串的长度
		o.write((char *)&len, sizeof(int));	// 在输出流中写入字符串所占空间的大小
		o.write(m_pbuf, len);				// 从m_pbuf开始写入len个字节；注意：最后一个零字符未写入
	}

	MyString & read_binary(istream & in)	// 二进制模式读取函数
	{
		delete[] m_pbuf;  //首先回收之前的内存
		int len;
		in.read((char *)&len, sizeof(int));	//先读取将要读取的字符串的长度
		m_pbuf = new char[len + 1];			//准备接受数据的空间：要多一个字节用于保存零字符
		in.read(m_pbuf, len);				//读取len个字节到m_pbuf指向的空间
		m_pbuf[len] = '\0';					//在最后加上结尾符号

		return *this;
	}

private:
	char * m_pbuf;
};

#endif
