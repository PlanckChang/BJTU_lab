//ɾ��������С��maxk ���Ҵ���mink�Ľ��

int Delete_LinkList(struct LinkList *list, int mink, int maxk) {
	struct LinkList *ptr1, *ptr2, *ptr3 ;
	if (mink > maxk)
		return 0;
	ptr1 = list;
	ptr1 = ptr1->next;
	while (ptr1->data < maxk) { //���������У����ж�
		if (ptr1->data < mink) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		} else {
			ptr2->next = ptr1->next;
			ptr3 = ptr1;
			ptr1 = ptr1->next;
			free(ptr3);
		}
	}
	return 1;
}