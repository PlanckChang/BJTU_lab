#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in;
	in.exceptions(ios::failbit);  //�趨�쳣λ
	try
	{
		int i;
		in.open("test.txt");
		while (!in.eof()) in.get();
			in.close();
	}
	catch (ios_base::failure & e)
	{
		cerr << "���쳣��" << e.what() << endl;
	}
	return 0;
}