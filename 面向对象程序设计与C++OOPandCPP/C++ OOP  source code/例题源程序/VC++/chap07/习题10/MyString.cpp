#include"MyString.h"

int MyString::total = 0;

ostream & operator<< (ostream & o, const MyString & s)
{
	o << s.get_length() << " " << s.m_pbuf; return o;  // �ڳ��Ⱥ����һ���ո���Ϊ�ָ���
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
	if (this != &s)  // ��ֹ�Ը�ֵ
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
	delete[] m_pbuf;  //���Ȼ���֮ǰ���ڴ�
	int len;
	in >> len;                   //��ȡ�ַ����ĳ���
	m_pbuf = new char[len + 1];  //׼���������ݵĿռ�
	in.get();                    //�׵�����Ŀո�  
	in.read(m_pbuf, len);        //��ȡ����
	m_pbuf[len] = '\0';          //�������Ͻ�β����

	return *this;
}

MyString & MyString::read_binary(istream & in)
{
	delete[] m_pbuf;  //���Ȼ���֮ǰ���ڴ�
	int len;
	in.read((char *)&len, sizeof(int));	//�ȶ�ȡ��Ҫ��ȡ���ַ����ĳ���
	m_pbuf = new char[len + 1];			//׼���������ݵĿռ䣺Ҫ��һ���ֽ����ڱ������ַ�
	in.read(m_pbuf, len);				//��ȡlen���ֽڵ�m_pbufָ��Ŀռ�
	m_pbuf[len] = '\0';					//�������Ͻ�β����

	return *this;
}

void MyString::write_text(ostream & o)		// �ı�ģʽ�������
{
	o << *this;		//ͨ�����ò��������ʵ���ı�ģʽ�����
}

void MyString::write_binary(ostream & o)	// ������ģʽ�������
{
	int len = strlen(m_pbuf);			// ȡ���ַ���ռ�õĿռ�Ĵ�С�����ַ����ĳ���
	o.write((char *)&len, sizeof(int));	// ���������д���ַ�����ռ�ռ�Ĵ�С
	o.write(m_pbuf, len);				// ��m_pbuf��ʼд��len���ֽڣ�ע�⣺���һ�����ַ���δд��
}