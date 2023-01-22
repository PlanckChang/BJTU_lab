#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int i;
	while(true)
	{
		cout << "请输入一个整数：";
		cin >> i;
		try
		{
			if(i > 0) throw 1;
			else if(i == 0) throw 'a';
			else if(i < 0) throw 1.1;
		}
		catch(int)
		{
			cout << "捕获到整型异常" << endl;
		}
		catch(char)
		{
			cout << "捕获到字符型异常" << endl;
		}
		catch(...)
		{
			cout << "捕获到一个不明类型的异常" << endl;
		}

		cout << "按 e 退出，按其他键继续...";
		if(getch() == 'e')
			break;
		cout << endl;
	}

	return 0;
}