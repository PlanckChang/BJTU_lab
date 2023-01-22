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
		cout << "学号\t姓名\t专业\t成绩" << endl;
		for (int i = 0; i < count; i++) {
			cout << gStu[i].number << "\t" << gStu[i].name << "\t" << gStu[i].major << "\t" << gStu[i].score << "\n";

		}
	}
	
	
	void display(int min, int max){
		cout << "学号\t姓名\t专业\t成绩" << endl;
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
	
		cout << "学生信息管理系统\n";
		cout << "1 录入学生信息 \n";
		cout << "2 显示学生信息 \n";
		cout << "3 删除学生信息\n";
		cout << "0 退出系统 \n";
		cout << "请选择所需要的操作：";
		
		cin >> choice;
		switch (choice) {
			case '1':
				cout << "请依次输入学号、姓名、专业和成绩\n";
				cin >> s.number >> s.name >> s.major >> s.score;
				cout << endl;
				add_student(s);
				break;
			case '2':
				cout << "1 全部输出\n";
				cout << "2 输入最低分最高分 按区间输出\n";
				
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
				cout << "请输入学生编号\n";
				cin >> num;
				flag = delete_student(num);
				if ( flag == 1) {
					cout << "删除成功" << "\n";
				} 
				else {
					cout << "没有这个学生的信息，请重输" << "\n" << endl;
				}
				break;
			case '0':
				break;
			default:
				cout << "你的选择有误，请重新选择！" << endl;

		}
	}

	return 0;
}





