#include<iostream>
using namespace std;

int & larger(int & a, int & b)
{
    return a > b ? a : b;

	//int i = a > b ? a : b;
    //return i;
}

int main()
{
    int x = 2, y = 5;
	cout << "x = " << x << " y = " << y <<endl;
	cout << (larger(x, y) += 5) << endl;
	cout << "x = " << x << " y = " << y <<endl;

    return 0;
}

