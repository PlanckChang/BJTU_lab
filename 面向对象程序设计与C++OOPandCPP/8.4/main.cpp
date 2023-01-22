#include <iostream>
#include <list>
#include <algorithm>
#include "MyString.h"
using namespace std;

template<class T> void output(const T &v) {
    cout << v <<" " ;
}

int main() {

    list<int > v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    list<int > :: iterator it = v.begin();
    ++it;

    v.insert(it, 2);

    cout << "before order reverse " ;
    for(it = v.begin(); it != v.end(); ++it)  // it can't be < v.end()
        cout << *it << " ";
    cout << endl;


    reverse(v.begin(), v.end());
    cout << "after reversed " ;
    for_each(v.begin(), v.end(), output<int>);
    cout << endl;

    list <MyString> v2;
    v2.push_back(MyString("11"));
    v2.emplace_back("00");
    v2.push_back(MyString("22"));
    v2.push_back(MyString("22"));
    v2.push_back(MyString("33"));

    cout << " before reversed " ;
    for_each(v2.begin(), v2.end(), output<MyString>);
    cout << endl;

    cout <<"after reversed ";
    reverse(v2.begin(), v2.end());
    for_each(v2.begin(), v2.end(), output<MyString>);
    cout << endl;

    return 0;
}

