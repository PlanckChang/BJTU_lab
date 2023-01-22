#include <iostream>
#include <stdexcept>
#include<bitset>
#include<vector>
using namespace std;
int main()
{
	try
	{
		bitset<4> b;
		b.set(5, true);
	}
	catch (out_of_range & e)
	{
		cerr << e.what() << endl;
	}
	try
	{
		vector<int> v(10);
		v.at(20) = 10;
	}
	catch (out_of_range & e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}
