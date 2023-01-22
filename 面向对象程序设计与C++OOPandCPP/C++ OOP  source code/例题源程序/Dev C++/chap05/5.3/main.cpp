#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << hex;  //����ʹ��16�������
	cout << setiosflags(ios::showbase | ios::uppercase);  //��д��ʽ���ǰ׺
	cout << 100 << endl;	//�����0X64���ͻ��з�
	cout << resetiosflags(ios::showbase);	//����ǰ׺��־�������ʱ������ǰ׺
	cout << 100 << endl;	//�����64���ͻ��з�
	cout << setbase(10);	//���û�Ϊ10����
	cout << 100 << endl;	//�����100���ͻ��з�

	double f = 3.14159;
	cout << resetiosflags(ios::floatfield);	//ȡ�����ø��������ݱ�־
	cout << setprecision(5);				//���þ���Ϊ5λ����5λ��Ч����
	cout << f << endl;				//���"3.1416"�ͻ��з�
	cout << setprecision(10);				//���þ���Ϊ10λ����10λ��Ч����
	cout << f << endl;				//���"3.14159"�ͻ��з�
	cout << setiosflags(ios::fixed); //���ö��㸡������־fixed
	cout << f << endl;	//���"3.1415900000"�ͻ��з�������Ҫ��С�����10λ

	cout << setiosflags(ios::dec); //����dec��־�����hex��oct��־
	cout << setw(10);          //�����ֶ����Ϊ10���ַ�
	cout << 40 << endl;		 //���"        40"�ͻ��з�
	cout << 40 << endl;      //���"40"�ͻ��з����ϴ�������ö���һ�ֶ���Ч
	cout << setfill('x');	  //��������ַ�Ϊ'x'
	cout << setw(10);				  //�������Ϊ10���ַ�
	cout << 40 << endl;           //���"xxxxxxxx40"�ͻ��з���Ĭ�����Ҷ���
	cout << setw(10);               //�������Ϊ10���ַ�
	cout << setiosflags(ios::left);         //����Ϊ�����
	cout << 40;			          //���"40xxxxxxxx"
	
	return 0;
}
