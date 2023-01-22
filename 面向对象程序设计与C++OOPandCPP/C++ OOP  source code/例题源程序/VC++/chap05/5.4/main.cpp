#include<fstream>
#include<iostream>

using namespace std;

int main() 
{
	ofstream out("test.txt"/*, ios_base::app*/);
	int i = out.tellp();
	cout << i << endl;
	out << "i love C++, Yeah!";
	out.flush();
	i = out.tellp();
	cout << i << endl;
	out.seekp(0);
	out << "I";
	out.seekp(-5, ios_base::end );
	out << "y";

	out.close();

	return 0;
}
