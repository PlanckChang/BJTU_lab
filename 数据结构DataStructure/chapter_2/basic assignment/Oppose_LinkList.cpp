#include <stdio.h>

//单链表实现就地逆置
struct LinkList {
	int data;
	struct LinkList *next;
};

int Oppose_LinkList(struct LinkList *list) {
	struct LinkList *ptr1, *ptr2, *ptr3;
	ptr1 = list;
	ptr3 = ptr2 = NULL;

	while (ptr1) {
		ptr2 = ptr1->next;
		ptr1->next = ptr3;
		ptr3 = ptr1;
		ptr1 = ptr2;
	}

	return 1;

}