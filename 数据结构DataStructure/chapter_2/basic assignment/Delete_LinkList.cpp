//删除链表中小于maxk 并且大于mink的结点

int Delete_LinkList(struct LinkList *list, int mink, int maxk) {
	struct LinkList *ptr1, *ptr2, *ptr3 ;
	if (mink > maxk)
		return 0;
	ptr1 = list;
	ptr1 = ptr1->next;
	while (ptr1->data < maxk) { //利用有序列，简化判断
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