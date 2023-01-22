#include<fstream>
#include<iostream>

using namespace std;

int main() 
{
	ifstream in("test.txt");    //以文本模式打开文件
	if (in.fail())
	{
		cout << "file does not exist." << endl;
		exit(0);
	}

	char buf[64];
	in >> buf;            	//提取数据，遇到空白符停下
	cout << buf << endl;	//输出字符'I'和换行符

	in.get(buf, 64);   	//默认结束符是'\n'，因此读取内容为" love C++, yeah!"
	cout << buf << "\t" << in.rdstate() << endl;	//输出buf、错误码0和换行符

	in.get(buf, 64);   	//什么也取不到，并设置错误码
	cout << buf << "\t" << in.rdstate() << endl;	//输出空串、错误码2和换行符

	in.clear();  			//清除错误标志才能继续读取数据

	in.seekg(2, ios_base::cur);	//跳过结束符，在字节流中'\n'是0D0A两个字节；
	//in.get();					//为防止因不同系统中结束符的字节数不同造成错误，可使用get函数读取一个字符

	in.get(buf, 64);   //读取内容为"I love C++, yeah!"
	cout << buf << "\t" << in.rdstate() << endl;

	//设置结束符是'y'并读取数据，此时首先读取换行符，然后继续读取，
	//直到遇到下一行中的字符'y'
	in.get(buf, 64, 'y');
	cout << buf << "\t" << in.rdstate() << endl;

	in.get(buf, 64);
	cout << buf << "\t" << in.rdstate() << endl;

	// 使用getline函数
	in.getline(buf, 64);
	cout << buf << endl;

	//遇到字符'y'停止并抛弃它，因此下一次读取时取不到字符'y'
	in.getline(buf, 64, 'y');
	cout << buf << endl;

	in.getline(buf, 64);
	cout << buf << endl;

	//// 使用read函数
	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;

	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;

	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;

	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;

	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;


	in.close();

	return 0;
}
