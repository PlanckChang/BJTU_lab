#include<iostream>
using namespace std;

int main()
{
	cout << "请输入两个数（被除数在前，除数在后）：";
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
		cout << "Exception: 整数 " << e << "不能被 0 除" << endl;
	}

	cout << "继续执行后续的程序..." << endl;

	return 0;
}
