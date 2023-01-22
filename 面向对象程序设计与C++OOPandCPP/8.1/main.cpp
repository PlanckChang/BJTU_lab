#include <iostream>
#include "MyString.h"
#include "stack.h"
using namespace std;


int main() {
//
//    int i = 5, j =10;
//    swap(i, j);
//    cout << i << " " << j << endl;
//
//    MyString str1("hello");
//    MyString str2("world");
//    swap(str1, str2);
//    cout << str1 << " " << str2 << endl;

STACK<int> s;
int*p;
    for (int i = 0; i < 10; ++i) {
        p = new int(i);
        s.push(p);
    }
    for(int i = 0; i<10; ++i){
        p = s.pop();
        cout << *p << ' ';
        delete p;

    }
    cout << endl;

}
template<typename T>
void swap(T &a, T &b){
    T c(a);// use a to construct c
    a = b;
    b = c;
}



