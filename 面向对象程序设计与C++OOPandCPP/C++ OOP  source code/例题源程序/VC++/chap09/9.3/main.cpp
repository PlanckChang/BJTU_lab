#include<iostream>
using namespace std;

int divide(int dividend, int divisor)
{
	if(divisor == 0)
		throw dividend;
	return dividend / divisor;
}

int main()
{
	cout << "����������������������ǰ�������ں󣩣�";
	int dividend, divisor;
	cin >> dividend >> divisor;
	try
	{
		int result = divide(dividend, divisor);
		cout << dividend << " / " << divisor << " = " << result << endl;
	}
	catch(int e)
	{
		cout << "Exception: ���� " << e << "���ܱ� 0 ��" << endl;
	}

	cout << "����ִ�к����ĳ���..." << endl;

	return 0;
}
