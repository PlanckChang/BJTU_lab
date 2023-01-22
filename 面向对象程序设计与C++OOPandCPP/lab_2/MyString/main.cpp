#include <iostream>
#include "MyString.h"
#include "MyString.cpp"

using namespace std;
int main(){
    MyString str;
    str.set_string("I love C++, ");
    cout << "字符串长度：" << str.get_length() << "\t" << str.get_string() << endl;
    str.append("yeah!");
    cout << "字符串长度：" << str.get_length() << "\t" << str.get_string() << endl;
    {
        MyString str("I like C++ programming!");
        MyString str2(str), str3 = str;
    }
    MyString str2;
    cout << str.get_string() << endl;
    str2 = str;
    str2.append(str2);
    cout << str2.get_string() << endl;
    return 0;
}