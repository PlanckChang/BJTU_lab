#include<iostream>
#include"MyString.h"

using namespace std;

int main()
{
	{
		MyString str[2];  // 调用不带参数的构造函数进行初始化
		str[0].set_string("I love C++, yeah!");
		str[1].set_string("I score 5.");

		ofstream out("test.dat", ios_base::binary);
		int num;
		num = 2;
		out.write((char *)&num, sizeof(int));
		str[0].write(out);
		str[1].write(out);
		out.close();
	}

	// 读取数据
	ifstream in("test.dat", ios_base::binary);
	int num;
	MyString * p;
	
	in.read((char *)&num, sizeof(int));
	p = new MyString[num];
	for(int i = 0; i < num; i++)
	{
		p[i].read(in);
		cout << p[i] << endl;
	}
	in.close();
	delete [] p;

	return 0;
}
