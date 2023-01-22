#include <iostream>       
#include <exception> 
using namespace std;
 
void unexpected_error() {
	cerr << "�����������쳣\n";
	throw;     //�׳�ԭ�쳣 
}

void function() throw (int, bad_exception) {
	throw 'e';   //�׳��ַ����쳣 
}

int main(void) 
{
	set_unexpected(unexpected_error);
	try 
	{
		function();
	}
	catch (char) { cerr << "�����ַ����쳣\n"; }
	catch (bad_exception & e) { cerr << "���������쳣��" << e.what() ; }
	catch (...) { cerr << "�������������쳣" << endl; }
	return 0;
}
