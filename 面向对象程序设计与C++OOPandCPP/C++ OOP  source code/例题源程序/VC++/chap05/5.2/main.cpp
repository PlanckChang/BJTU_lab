#include<iostream>

using namespace std;

int main()
{
	cout.setf(ios::hex, ios::basefield);  //����hex��־�����dec��oct��־
	cout.setf(ios::showbase);             //������ʾ��������ǰ׺
	cout << 100 << endl;				  //���"0x64"�ͻ��з�
	cout.unsetf(ios::showbase);           //ȡ����ʾ��������ǰ׺
	cout << 100 << endl;				  //���"64"�ͻ��з�

	double f = 3.14159;
	cout.unsetf(ios::floatfield);	//ȡ�����ø��������ݱ�־
	cout.precision(5);				//���þ���Ϊ5λ����5λ��Ч����
	cout << f << endl;				//���"3.1416"�ͻ��з�
	cout.precision(10);				//���þ���Ϊ10λ����10λ��Ч����
	cout << f << endl;				//���"3.14159"�ͻ��з�
	cout.setf(ios::fixed, ios::floatfield); //���ö��㸡������־fixed
	cout << f << endl;	//���"3.1415900000"�ͻ��з�����ʱprecision������Ҫ��С�����10λ

	cout.setf(ios::dec, ios::basefield);    //����dec��־�����hex��oct��־
	cout.width(10);                 //�����ֶ����Ϊ10���ַ�
	cout << 40 << endl;				//���"        40"�ͻ��з����������ֻ����һ���ֶ���Ч
	cout << 40 << endl;             //���"40"�ͻ��з����ϴε�������ö���һ�ֶ���Ч
	char prev = cout.fill('x');		//��������ַ�Ϊ'x'
	cout.width(10);					//�������Ϊ10���ַ�
	cout << 40 << endl;             //���"xxxxxxxx40"�ͻ��з���Ĭ�����Ҷ���
	cout.width(10);                 //�������Ϊ10���ַ�
	cout.setf(ios::left);           //����Ϊ�����
	cout << 40;     				//���"40xxxxxxxx"
	cout.fill(prev);                //�ָ���ǰ������ַ�
	
	return 0;
}
