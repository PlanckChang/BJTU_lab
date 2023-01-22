#include <iostream>       
#include <exception> 
using namespace std;
 
void unexpected_error() {
	cerr << "产生了意外异常\n";
	throw;     //抛出原异常 
}

void function() throw (int, bad_exception) {
	throw 'e';   //抛出字符型异常 
}

int main(void) 
{
	set_unexpected(unexpected_error);
	try 
	{
		function();
	}
	catch (char) { cerr << "捕获字符型异常\n"; }
	catch (bad_exception & e) { cerr << "捕获意外异常：" << e.what() ; }
	catch (...) { cerr << "捕获其它意外异常" << endl; }
	return 0;
}
