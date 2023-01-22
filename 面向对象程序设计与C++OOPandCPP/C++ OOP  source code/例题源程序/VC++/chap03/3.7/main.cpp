// 实验目的：演示类的静态成员

#include<iostream>
#include"MyString.h"
using namespace std;

int main()
{
    cout << MyString::get_total() << endl; // 此时输出为0
    MyString str;  // 调用不带参数的构造函数进行初始化
    cout << str.get_total() << endl;  // 此时输出为1
    {
        MyString str2(str);
        cout << str2.get_total() << endl;  // 此时输出为2
    }
    cout << str.get_total() << endl;  // 此时输出为1

    return 0;
}