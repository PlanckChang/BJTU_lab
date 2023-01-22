#include<iostream>
#include"MyString.h"
#include"BigInt.h"
#include<fstream>
using namespace std;

int main()
{
//	CBigInt test(99999999);
//	test.print();
//	cout << endl;
//	test++;
//	test.print();
//	cout << endl;
//	test++;
//	test.print();
//	cout << endl;
//	//test--;
//	//test.print();
//	//cout << endl;
//	//test--;
//	//test.print();
//	//cout << endl;
//	CBigInt test2(-7892342);
//	test2.print();
//	cout << endl;
//	CBigInt test3(-9999999);
//	test3.print();
//	cout << endl;
//	(test3 - test2).print();
//	cout << endl;
//	test3-= test2;
//	test3.print();
//	cout << endl;
//	(test3 + 12).print();
//	cout << endl;
//	test3 += 12;
//	test3.print();
//	cout << endl;
//	(test3 - 120).print();
//	cout << endl;
//	test3 -= 120;
//	test3.print();
//	cout << endl;
//	cin >> test3;
//	cout << test3 << endl;
//
//	CBigInt bigint;
//	for (int i = 0; i < 99999999; i++)
//		++bigint;
//	bigint.print();
//	(bigint++).print();
//	bigint.print();
//	++bigint;
//	bigint.print();
//	for (int i = 0; i < 99999998; i++)
//		++bigint;
//	++bigint;
//	bigint.print();
//	++bigint;
//	bigint.print();
//	for (int i = 0; i < 99999999; i++)
//		++bigint;
//	bigint.print();
//	++bigint;
//	bigint.print();
//	++bigint;
//	bigint.print();
//	for (int i = 0; i < 99999998; i++)
//		++bigint;
//	++bigint;
//	bigint.print();
//	++bigint;
//	bigint.print();

	MyString str1("I love "), str2("c++!"), str3;
	str3 = str1 + str2;
	cout << str3.get_string() << endl;

	str2.operator [](0) = 'C';
	cout << str2.get_string() << endl;
    const MyString s("I love C++!");
    cout << s[7] << endl;
	str1("I can score 100!");
	cout << str1.get_string() << endl;

	return 0;
}
