#include<iostream>
using namespace std;

int main()
{
	cout << "����������������������ǰ�������ں󣩣�";
	int dividend, divisor;
	cin >> dividend >> divisor;
	try
	{
		if(divisor == 0)
			throw dividend;
      
		cout << dividend << " / " << divisor << " = " 
			 << dividend / divisor << endl;
	}
	catch(int e)
	{
		cout << "Exception: ���� " << e << "���ܱ� 0 ��" << endl;
	}

	cout << "����ִ�к����ĳ���..." << endl;

	return 0;
}
