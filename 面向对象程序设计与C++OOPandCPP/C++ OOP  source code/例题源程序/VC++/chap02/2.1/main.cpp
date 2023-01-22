#include<iostream>
using namespace std;

const int g = 0;      // g在数据段（如果不引用其地址，则不占内存）

int main()
{
    const int c = 5;     // c在栈中
    int * p = (int*)&c;  // 普通指针指向常量数据。
                         // 在C++中不允许，需要强制转换。
	                     // 这里只是举例，实际编程时一定不要这样做。
    c = 10;              // 编译出错，不能给常变量赋值
    p = (int*)&g;        // 普通指针指向常量数据。
                         // 在C++中不允许，需要强制转换。
    *p = 20;             // 修改失败，会出现运行错误
    int i = 10;
	const int * p2 = &i; // p2是指向常量的指针。从p2的角度看，它指向
                         // 的数据是常量，并不意味着该数据真的是常量
	*p2 = 20;            // 从p2的角度看，它指向的数据是常量，不能修改，
                         // 因此会出现编译错误
    return 0;
}
