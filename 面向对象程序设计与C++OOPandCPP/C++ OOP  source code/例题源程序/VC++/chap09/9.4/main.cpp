#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int i;
	while(true)
	{
		cout << "������һ��������";
		cin >> i;
		try
		{
			if(i > 0) throw 1;
			else if(i == 0) throw 'a';
			else if(i < 0) throw 1.1;
		}
		catch(int)
		{
			cout << "���������쳣" << endl;
		}
		catch(char)
		{
			cout << "�����ַ����쳣" << endl;
		}
		catch(...)
		{
			cout << "����һ���������͵��쳣" << endl;
		}

		cout << "�� e �˳���������������...";
		if(getch() == 'e')
			break;
		cout << endl;
	}

	return 0;
}