#include <iostream>
#include "MyString.h"

using namespace  std;

void fun(const char*p){
    cout << p << endl;
}

int main() {
    MyString str1("I love "), str2("c++!"), str3;
    str3 = str1 + str2;
    cout << str3.get_string() << endl;

    str2.operator [](0) = 'C';
    cout << str2.get_string() << endl;
    const MyString s("I love C++!");
    cout << s[7] << endl;
    str1("I can score 100!");
    cout << str1.get_string() << endl;

    fun(str1);

    if(str1>str2) cout<<"str1>str2\n";
    else cout <<"str1<=str2\n";

    if(str1>=str2) cout << "str1>=str2\n";
    else cout << "str1 < str2\n";

    if(str1<str2) cout << "str1<str2\n";
    else cout << "str1 >= str2\n";

    if(str1<=str2) cout << " str1<=str2\n";
    else cout << " str1 > str2\n";
    return 0;
}
