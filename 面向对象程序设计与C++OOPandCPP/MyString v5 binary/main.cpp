#include <iostream>
#include "MyString.h"

using namespace  std;

void fun(const char*p){
    cout << p << endl;
}

int main()
{

//¶þ½øÖÆ

    {
        MyString str[2];
        str[0].set_string("I love C++, yeah!");
        str[1].set_string("I score 5.");

        ofstream out("test.dat", ios_base::binary);
        int num;
        num = 2;
        out.write((char *)&num, sizeof(int));
        str[0].write(out);
        str[1].write(out);
        out.close();
    }


    ifstream in2("test.dat", ios_base::binary);
    int num2;
    MyString * p2;

    in2.read((char *)&num2, sizeof(int));
    p2 = new MyString[num2];
    for(int i = 0; i < num2; i++)
    {
        p2[i].read(in2);
        cout << p2[i] << endl;
    }
    in2.close();
    delete [] p2;

    return 0;
}
