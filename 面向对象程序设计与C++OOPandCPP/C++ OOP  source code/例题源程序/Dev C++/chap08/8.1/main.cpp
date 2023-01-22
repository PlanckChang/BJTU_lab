#include<iostream>
#include"stack.h"

using namespace std;

int main()
{
	STACK<int> s;
	int i, *p;
	for (i = 0; i < 10; i++)
	{
		p = new int(i);
		s.push(p);
	}
	for (i = 0; i < 10; i++)
	{
		p = s.pop();
		cout << *p << ' ';
		delete p;
	}
	cout << endl;

	return 0;
}
