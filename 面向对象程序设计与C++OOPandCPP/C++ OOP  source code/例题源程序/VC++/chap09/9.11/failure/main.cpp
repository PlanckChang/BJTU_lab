#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in;
	in.exceptions(ios::failbit);  //设定异常位
	try
	{
		int i;
		in.open("test.txt");
		while (!in.eof()) in.get();
			in.close();
	}
	catch (ios_base::failure & e)
	{
		cerr << "流异常：" << e.what() << endl;
	}
	return 0;
}