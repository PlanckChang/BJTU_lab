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
	cout << "请输入两个数（被除数在前，除数在后）：";
	int dividend, divisor;
	cin >> dividend >> divisor;
	try
	{
		int result = divide(dividend, divisor);
		cout << dividend << " / " << divisor << " = " << result << endl;
	}
	catch(int e)
	{
		cout << "Exception: 整数 " << e << "不能被 0 除" << endl;
	}

	cout << "继续执行后续的程序..." << endl;

	return 0;
}
