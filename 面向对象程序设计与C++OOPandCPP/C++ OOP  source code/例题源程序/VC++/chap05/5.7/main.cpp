#include<iostream>
#include"MyString.h"

using namespace std;

int main()
{
	{
		MyString str[2];
		str[0].set_string("I love C++, yeah!");
		str[1].set_string("I score 5.");

		ofstream out("test.txt");
		out << 2 << " " << str[0].get_length() << " "  << str[0] 
			<< str[1].get_length() << " " << str[1];
		out.close();
	}

	// ¶ÁÈ¡Êý¾Ý
	ifstream in("test.txt");
	int num;
	MyString * p;
	
	in >> num;
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
