#include <iostream>     
#include <fstream>
using namespace std;

int main() 
{
	ifstream in("test.dat", ios_base::in);	//�򿪲����ڵ��ļ���������failbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		 << " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	in.open("test.txt");	//�������ļ�������goodbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	int i;
	in >> i;	//��ȡ�������޷�תΪ���ͣ�����failbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	in.clear();	//�������״̬������goodbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	char buf[32];
	in >> buf;	//������ȡ���ݣ����ȡ�󵽴��ļ�β������eofbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	in >> buf;	//�ٴ���ȡ���ݣ����޷���ȡ���ݶ���������failbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	in.close();

	return 0;
}