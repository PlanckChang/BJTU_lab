//
// Created by Planck Chang on 2021/12/3.
//
#include "studentlist.h"
#include "student.h"
#include <iostream>

using namespace std;

char ErrorMsg[][100] = { "",					//0-�޴���
                         "���޴��ˣ�",				//1
                         "�������������ã�����ɾ����",   	//2
                         "���������У�" };		//3

void showError(int idx) { cout << ErrorMsg[idx] << endl; }
