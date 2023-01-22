#include <iostream>
#include <typeinfo>
using namespace std;
class Base { public: virtual ~Base() { } };
class Derived : Base { };
int main()
{
	try
	{
		Base b;
		Derived & d = dynamic_cast<Derived&>(b);
	}
	catch (bad_cast & e)
	{
		cerr << "bad_castÒì³£: " << e.what() << endl;
	}
	return 0;
}