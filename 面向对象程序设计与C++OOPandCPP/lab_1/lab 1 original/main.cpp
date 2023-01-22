#include "20271259.h"

namespace N20271259{

	STUDENT * gStu = NULL;
	int count =  0; 
	int available = 0;
	
	void add_student(STUDENT &stu){
		if (0 == available){
			STUDENT * tmp = new STUDENT[count + BLOCK]; 
			for (int i = 0; i < count; i++){
				tmp[i].number = gStu[i].number; 
				strcpy_s(tmp[i].name, 20, gStu[i].name);
				strcpy_s(tmp[i].major, 20, gStu[i].major); 
				tmp[i].score = gStu[i].score;
			}
		delete[] gStu; 
		gStu = tmp; 
		available = BLOCK;
		}
		
		gStu[count].number = stu.number;
		strcpy_s(gStu[count].name, stu.name); 
		strcpy_s(gStu[count].major, stu.major); 
		gStu[count].score = stu.score;
		
		count++; 
		available--;
	}


	void display(){
		cout << "ѧ��\t����\tרҵ\t�ɼ�" << endl; 
			for (int i = 0; i<count; i++){	
			cout << gStu[i].number << "\t" << gStu[i].name << "\t"<< gStu[i].major << "\t" << gStu[i].score << "\n";
		}	
	}	

}

using namespace N20271259; 

int main(){
	char choice = '\0'; 
	STUDENT s;
	
	while (choice != '0'){
		cout << "ѧ����Ϣ����ϵͳ\n"; 
		cout << "1 ¼��ѧ����Ϣ \n"; 
		cout << "2 ��ʾѧ����Ϣ \n"; 
		cout << "0 �˳�ϵͳ \n";
		cout << "��ѡ������Ҫ�Ĳ�����"; 
		cin >> choice;
	
	
		switch (choice){
			case '1':
				cout << "����������ѧ�š�������רҵ�ͳɼ�\n"; 
				cin >> s.number >> s.name >> s.major >> s.score; add_student(s);
				cout << endl; 
				break;
			case '2':
				display(); 
				cout << endl; 
				break;
			case '0':
				break; 
			default:
				cout << "���ѡ������������ѡ��" << endl;
		}
	}
	return 0;
}