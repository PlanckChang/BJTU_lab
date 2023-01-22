#include <iostream>
#include <vector>
#include <algorithm>
#include "MyString.h"

using namespace std;

bool larger(int a, int b){
    return a>b;
}

template<class T> class CLarger
{
public:
    bool operator()(const T &a , const T&b){return a>b;}
};
void output_int(int i){cout << i << " ";}
template <class T> void output(const T&v){cout << v << " ";}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    v.insert(v.begin() + 2, 0);
    v.insert(v.begin(), 2);

    cout << "before sorted ";
    vector<int>::iterator iter;
    for(iter = v.begin(); iter < v.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    sort(v.begin(), v.end(), larger);
    cout << "after sorted from small to big " ;
    for_each(v.begin(), v.end(), output<int>);
    cout << endl;

    v.erase(v.end()-1);

    sort(v.begin(), v.end(), std:: less<int>());
    cout << "sorted from small to big " ;
    for_each(v.begin(), v.end(), output<int>);
    cout << endl;

    sort(v.begin(), v.end(), CLarger<int>());
    cout << "sorted from big to small ";
    for_each(v.begin(), v.end(), output<int>);
    cout << endl;

    vector <MyString> v2;
    v2.push_back(MyString("11"));
    v2.push_back(MyString("00"));
    v2.push_back(MyString("22"));
    v2.push_back(MyString("22"));
    v2.push_back(MyString("33"));

    cout << "before sorted ";
    for_each(v2.begin(), v2.end(), output<MyString>);
    cout << endl;

    sort(v2.begin(), v2.end(), CLarger<MyString>());
    cout << "sorted from big to small " ;
    for_each(v2.begin(), v2.end(), output<MyString>);
    cout << endl;

    return 0;
}
