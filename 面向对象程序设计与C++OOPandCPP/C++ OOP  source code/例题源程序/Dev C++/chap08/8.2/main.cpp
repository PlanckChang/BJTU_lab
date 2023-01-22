
#include<iostream>
#include"stack.h"
using namespace std;

int main()
{
	STACK<int> s;
	for(int i = 0; i < 10; i++)
	{
		int * p = new int(i);
		s.push(p);
	}

	STACKIterator<int> iter(s);
	while(iter)
	{
		cout << *iter.current() << ' ';
		iter++;
	}
	cout << endl;

	////ÓÐÃûSTACK
	//CNamedStack<int> stack("test");
	//cout << stack.get_name();
	//CIntStack int_s;

	return 0;
}