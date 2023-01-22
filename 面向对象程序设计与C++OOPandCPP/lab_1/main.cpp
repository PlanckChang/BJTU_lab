#include "20271259.h"

namespace N20271259 {


	STUDENT *gStu = NULL;
	int count =  0;
	int available = 0;

	void add_student(STUDENT &stu) {
		if (0 == available) {
			STUDENT *tmp = new STUDENT[count + BLOCK];
			for (int i = 0; i < count; i++) {
				tmp[i].number = gStu[i].number;
				strcpy(tmp[i].name, gStu[i].name);
				strcpy(tmp[i].major, gStu[i].major);
				tmp[i].score = gStu[i].score;
			}
			delete[] gStu;
			gStu = tmp;
			available = BLOCK;
		}

		gStu[count].number = stu.number;
		strcpy(gStu[count].name, stu.name);
		strcpy(gStu[count].major, stu.major);
		gStu[count].score = stu.score;

		count++;
		available--;
	}


	void display(void) {
		cout << "ѧ��\t����\tרҵ\t�ɼ�" << endl;
		for (int i = 0; i < count; i++) {
			cout << gStu[i].number << "\t" << gStu[i].name << "\t" << gStu[i].major << "\t" << gStu[i].score << "\n";

		}
	}
	
	
	void display(int min, int max){
		cout << "ѧ��\t����\tרҵ\t�ɼ�" << endl;
		for (int i =0; i< count; i++){
			if (gStu[i].score < max && gStu[i].score > min){
				cout << gStu[i].number << "\t" << gStu[i].name << "\t" << gStu[i].major << "\t" << gStu[i].score << "\n";
			}
		}
		
	}
	
	int delete_student(int num) {

		int flag;
		for (int i = 0; i < count; i++) {
			if (gStu[i].number == num) {
				for (int j = i; j < count; j++) {
					gStu[j] = gStu[j + 1];
				}
				flag = 1;

				count--;
				available++;
			}
			if (flag == 1) {
				break;
			}
		if(available>=20){
			STUDENT *tmp = new STUDENT[available-BLOCK];
			for (int i = 0; i < count; i++) {
				tmp[i].number = gStu[i].number;
				strcpy(tmp[i].name, gStu[i].name);
				strcpy(tmp[i].major, gStu[i].major);
				tmp[i].score = gStu[i].score;
			}
			delete[] gStu;
			gStu = tmp;
			available = BLOCK;
		}



		}
		
		
		return flag;
*/	}

}



using namespace N20271259;

int main() {

	int  flag,num,min,max,option;
	char choice = '\0';

	STUDENT s;

	while (choice != '0') {
	
		cout << "ѧ����Ϣ����ϵͳ\n";
		cout << "1 ¼��ѧ����Ϣ \n";
		cout << "2 ��ʾѧ����Ϣ \n";
		cout << "3 ɾ��ѧ����Ϣ\n";
		cout << "0 �˳�ϵͳ \n";
		cout << "��ѡ������Ҫ�Ĳ�����";
		
		cin >> choice;
		switch (choice) {
			case '1':
				cout << "����������ѧ�š�������רҵ�ͳɼ�\n";
				cin >> s.number >> s.name >> s.major >> s.score;
				cout << endl;
				add_student(s);
				break;
			case '2':
				cout << "1 ȫ�����\n";
				cout << "2 ������ͷ���߷� ���������\n";
				
				cin >> option;
				if(option==1) display();
				if(option==2){
					cin >> min;
					cin >> max;
					display(min, max);
				} 
				
				cout << endl;
				break;
			case '3':
				cout << "������ѧ�����\n";
				cin >> num;
				flag = delete_student(num);
				if ( flag == 1) {
					cout << "ɾ���ɹ�" << "\n";
				} 
				else {
					cout << "û�����ѧ������Ϣ��������" << "\n" << endl;
				}
				break;
			case '0':
				break;
			default:
				cout << "���ѡ������������ѡ��" << endl;

		}
	}

	return 0;
}





