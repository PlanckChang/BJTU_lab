#include <iostream>     
#include <fstream>
using namespace std;

int main() 
{
	ifstream in("test.dat", ios_base::in);	//打开不存在的文件，会设置failbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		 << " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	in.open("test.txt");	//正常打开文件，设置goodbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	int i;
	in >> i;	//提取的数据无法转为整型，设置failbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	in.clear();	//清除错误状态，设置goodbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	char buf[32];
	in >> buf;	//正常读取数据，因读取后到达文件尾而设置eofbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	in >> buf;	//再次提取数据，因无法读取数据而增加设置failbit
	cout << "good()=" << in.good() << " eof()=" << in.eof()
		<< " fail()=" << in.fail() << " bad()=" << in.bad() << endl;

	in.close();

	return 0;
}