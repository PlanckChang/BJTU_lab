#ifndef _20271259_H_
#define _20271259_H_

#include <iostream>
using namespace std;

namespace N20271259 {
#define BLOCK 10

	struct STUDENT {
		long int number;
		char name[20];
		char major[20];
		double score;
	};

	extern STUDENT *gStu;
	extern int count;
	extern int available;
	void add_student(STUDENT &stu);
	void display(void);
	void display(int min, int max);
	int delete_student(int num);

}

#endif
