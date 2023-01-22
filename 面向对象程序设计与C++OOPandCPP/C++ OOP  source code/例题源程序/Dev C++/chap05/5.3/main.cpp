#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << hex;  //整数使用16进制输出
	cout << setiosflags(ios::showbase | ios::uppercase);  //大写形式输出前缀
	cout << 100 << endl;	//输出“0X64”和换行符
	cout << resetiosflags(ios::showbase);	//重置前缀标志，即输出时不带基前缀
	cout << 100 << endl;	//输出“64”和换行符
	cout << setbase(10);	//设置基为10进制
	cout << 100 << endl;	//输出“100”和换行符

	double f = 3.14159;
	cout << resetiosflags(ios::floatfield);	//取消设置浮点型数据标志
	cout << setprecision(5);				//设置精度为5位，即5位有效数字
	cout << f << endl;				//输出"3.1416"和换行符
	cout << setprecision(10);				//设置精度为10位，即10位有效数字
	cout << f << endl;				//输出"3.14159"和换行符
	cout << setiosflags(ios::fixed); //设置定点浮点数标志fixed
	cout << f << endl;	//输出"3.1415900000"和换行符，精度要求小数点后10位

	cout << setiosflags(ios::dec); //设置dec标志，清除hex和oct标志
	cout << setw(10);          //设置字段域宽为10个字符
	cout << 40 << endl;		 //输出"        40"和换行符
	cout << 40 << endl;      //输出"40"和换行符，上次域宽设置对下一字段无效
	cout << setfill('x');	  //设置填充字符为'x'
	cout << setw(10);				  //设置域宽为10个字符
	cout << 40 << endl;           //输出"xxxxxxxx40"和换行符，默认是右对齐
	cout << setw(10);               //设置域宽为10个字符
	cout << setiosflags(ios::left);         //设置为左对齐
	cout << 40;			          //输出"40xxxxxxxx"
	
	return 0;
}
