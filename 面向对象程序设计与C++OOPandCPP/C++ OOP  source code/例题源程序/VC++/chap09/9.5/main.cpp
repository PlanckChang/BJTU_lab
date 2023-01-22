#include<iostream>
using namespace std;

void fun() //throw(char, bad_exception)
{
	try
	{
		throw 12; 
	}
	catch(int)
	{
		cout << "int exception.\n";
		throw;
	}
}

int main()
{
	try
	{
		fun(); 
	}
	catch(int)
	{
		cout << "int exception.\n";
	}
	//catch (char)
	//{
	//	cout << "char exception" << endl;
	//}
	return 0;
}
