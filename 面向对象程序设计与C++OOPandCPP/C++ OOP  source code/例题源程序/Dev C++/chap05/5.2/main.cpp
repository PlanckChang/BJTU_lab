#include<iostream>

using namespace std;

int main()
{
	cout.setf(ios::hex, ios::basefield);  //设置hex标志，清除dec和oct标志
	cout.setf(ios::showbase);             //设置显示整数进制前缀
	cout << 100 << endl;				  //输出"0x64"和换行符
	cout.unsetf(ios::showbase);           //取消显示整数进制前缀
	cout << 100 << endl;				  //输出"64"和换行符

	double f = 3.14159;
	cout.unsetf(ios::floatfield);	//取消设置浮点型数据标志
	cout.precision(5);				//设置精度为5位，即5位有效数字
	cout << f << endl;				//输出"3.1416"和换行符
	cout.precision(10);				//设置精度为10位，即10位有效数字
	cout << f << endl;				//输出"3.14159"和换行符
	cout.setf(ios::fixed, ios::floatfield); //设置定点浮点数标志fixed
	cout << f << endl;	//输出"3.1415900000"和换行符，此时precision的设置要求小数点后10位

	cout.setf(ios::dec, ios::basefield);    //设置dec标志，清除hex和oct标志
	cout.width(10);                 //设置字段域宽为10个字符
	cout << 40 << endl;				//输出"        40"和换行符，域宽设置只对下一个字段有效
	cout << 40 << endl;             //输出"40"和换行符，上次的域宽设置对下一字段无效
	char prev = cout.fill('x');		//设置填充字符为'x'
	cout.width(10);					//设置域宽为10个字符
	cout << 40 << endl;             //输出"xxxxxxxx40"和换行符，默认是右对齐
	cout.width(10);                 //设置域宽为10个字符
	cout.setf(ios::left);           //设置为左对齐
	cout << 40;     				//输出"40xxxxxxxx"
	cout.fill(prev);                //恢复先前的填充字符
	
	return 0;
}
