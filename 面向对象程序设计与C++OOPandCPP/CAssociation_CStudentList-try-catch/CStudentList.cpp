#include <iostream>
#include "CStudentList.h"
using namespace std;

char ErrorMsg[][100] = { "",					//0-�޴���
                         "���޴��ˣ�",				//1
                         "�������������ã�����ɾ����",   	//2
                         "���������У�" };		//3

void showError(int idx) { cout << ErrorMsg[idx] << endl; }