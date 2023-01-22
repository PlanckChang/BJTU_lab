#include"MyString.h"

int MyString::total = 0;

ostream & operator<< (ostream & o, const MyString & s)
{
	o << s.get_length() << " " << s.m_pbuf; return o;  // 在长度后面加一个空格作为分隔符
}

MyString::MyString()
{
	total++;
	m_pbuf = new char('\0');
}

MyString::MyString(const char * p)
{
	total++;
	if (NULL == p)
		m_pbuf = new char('\0');
	else
	{
		int len = strlen(p) + 1;
		m_pbuf = new char[len];
		strcpy_s(m_pbuf, len, p);
	}
}

MyString::MyString(const MyString & s)
{
	total++;
	int len = strlen(s.m_pbuf) + 1;
	m_pbuf = new char[len];
	strcpy_s(m_pbuf, len, s.m_pbuf);
}

MyString::~MyString()
{
	total--;
	delete[] m_pbuf;
}

const char * MyString::set_string(const char * p)
{
	delete[] m_pbuf;

	if (NULL == p)
		m_pbuf = new char('\0');
	else
	{
		int len = strlen(p) + 1;
		m_pbuf = new char[len];
		strcpy_s(m_pbuf, len, p);
	}

	return m_pbuf;
}

const char * MyString::append(const char * p)
{
	if (NULL != p)
	{
		int len = strlen(m_pbuf) + strlen(p) + 1;
		char * tmp = new char[len];
		sprintf_s(tmp, len, "%s%s", m_pbuf, p);
		delete[] m_pbuf;
		m_pbuf = tmp;
	}

	return m_pbuf;
}

MyString & MyString::append(MyString & s)
{
	int len = strlen(m_pbuf) + strlen(s.m_pbuf) + 1;
	char * tmp = new char[len];
	sprintf_s(tmp, len, "%s%s", m_pbuf, s.m_pbuf);
	delete[] m_pbuf;
	m_pbuf = tmp;

	return *this;
}

MyString & MyString::operator=(const MyString & s)
{
	if (this != &s)  // 防止自赋值
	{
		delete[] m_pbuf;
		int len = strlen(s.m_pbuf) + 1;
		m_pbuf = new char[len];
		strcpy_s(m_pbuf, len, s.m_pbuf);
	}
	return *this;
}

MyString & MyString::read_text(istream & in)
{
	delete[] m_pbuf;  //首先回收之前的内存
	int len;
	in >> len;                   //读取字符串的长度
	m_pbuf = new char[len + 1];  //准备接受数据的空间
	in.get();                    //抛掉后面的空格  
	in.read(m_pbuf, len);        //读取数据
	m_pbuf[len] = '\0';          //在最后加上结尾符号

	return *this;
}

MyString & MyString::read_binary(istream & in)
{
	delete[] m_pbuf;  //首先回收之前的内存
	int len;
	in.read((char *)&len, sizeof(int));	//先读取将要读取的字符串的长度
	m_pbuf = new char[len + 1];			//准备接受数据的空间：要多一个字节用于保存零字符
	in.read(m_pbuf, len);				//读取len个字节到m_pbuf指向的空间
	m_pbuf[len] = '\0';					//在最后加上结尾符号

	return *this;
}

void MyString::write_text(ostream & o)		// 文本模式输出函数
{
	o << *this;		//通过调用插入符函数实现文本模式的输出
}

void MyString::write_binary(ostream & o)	// 二进制模式输出函数
{
	int len = strlen(m_pbuf);			// 取得字符串占用的空间的大小，即字符串的长度
	o.write((char *)&len, sizeof(int));	// 在输出流中写入字符串所占空间的大小
	o.write(m_pbuf, len);				// 从m_pbuf开始写入len个字节；注意：最后一个零字符并未写入
}