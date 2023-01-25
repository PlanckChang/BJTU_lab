










#include "chapter2.h"














////删除链表中小于maxk 并且大于mink的结点
int Delete_LinkList(struct LinkList *list, int mink, int maxk){
	struct LinkList*ptr1, *ptr2, *ptr3= NULL;
	ptr1 = list;
	ptr2 = ptr1;
	ptr1 = ptr1->next;
	while(ptr1!=NULL && ptr1->data < maxk){ //利用有序列，简化判断
		if(ptr1->data <= mink){
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		else{
			ptr2->next = ptr1->next;
			ptr3 = ptr1;
			ptr1 = ptr1->next;
			free(ptr3);
		}
	}
	return 1;
}

//创建一个链表
struct LinkList *CreatLink(struct LinkList *head) {
	struct LinkList *p = NULL, *q = NULL;
	int data;
	p = (struct LinkList *)malloc(sizeof(struct LinkList));
	head = p;
	q = p;
	scanf("%d", &data);
	while (data != -1) {
		p = (struct LinkList *)malloc(sizeof(struct LinkList));
		p->data = data;
		q->next = p;
		q = p;
		scanf("%d", &data);
	}
	p->next = NULL;
	return head;
}

////显示链表data
void Display_LinkList(struct LinkList *head) {
	struct LinkList *h = head->next;//跳过头节点
	if (h == NULL) {//判空
		printf("The Link is null");
		return;
	}
	while (h != NULL) {
		printf("%d ", h->data);
		h = h->next;
	}
}



//
////顺序表就地逆置
//int Oppose_List(int list[], int length ){
//	int tem;
//	for(int i=0; i<length/2; i++){
//		tem = list[i];
//		list[i] = list[length-i-1];
//		list[length-i-1] = tem;
//	}
//
//	return 1;
//}
//
//
//单链表实现就地逆置


//struct LinkList *Oppose_LinkList(struct LinkList *list) {
//	struct LinkList *ptr1, *ptr2, *ptr3;
//	ptr1 = list;
//	ptr3 = ptr2 = NULL;
//
//	ptr2 = ptr1->next;
//	ptr1->next = ptr3;
//	ptr3 = ptr1;
//	ptr1 = ptr2;
//	ptr3 = NULL;
//
//
//	while (ptr1) {
//		ptr2 = ptr1->next;
//		ptr1->next = ptr3;
//		ptr3 = ptr1;
//		ptr1 = ptr2;
//	}
//
//	return ptr3;
//
//}


//int Oppose_List(int *list, int length ){
//	int tem;
//int Oppose_LinkList(struct LinkList *list) {


//		tem = list[i];
//		list[i] = list[length-i-1];
//		list[length-i-1] = tem;
//	}
//
//	return 1;
//}
//


//双向循环链表的Locate函数



//DuLinkList *DuLinkList_Locate(DuLinkList *linklist, int x) {
//	struct DuLinkList *q, *p;
//	p = linklist->next;
//
//	while (p != linklist && p->data != x)
//		p = p->next;
//	if (p = linklist)
//		return NULL;
//	else {
//		p->freq = (p->freq ) + 1;
//		q = p->pre;
//		while (p->pre != linklist && q->freq < p->freq ) {
//			q->pre->next = p;
//			p->next->pre = q;
//			q->next = p->next;
//			p->pre = q->pre;
//			p->next = q;
//			q->pre = p;
//		}
//	}
//	return linklist;
//}

//	DuLinkList *p, *q;
//	p = linklist->next;
//	while (p != linklist && p->data != x)
//		p = p->next;
//	if (p == linklist)
//		return NULL;
//	else {
//		p->freq++;
//		// 删除结点
//		p->pre->next = p->next;
//		p->next->pre = p->pre;
//		// 插入到合适的位置
//		q = linklist->next;
//		while (q != linklist && q->freq > p->freq)
//			q = q->next;
//		if (q == linklist){
//			q->pre->next = p;
//			p->pre = q->pre;
//			p->next = q;
//			q->pre = p;
//		} else {
//			p->next = q->next;
//			q->next->pre = p;
//			p->pre = q;
//			q->next = p;
//		}
//
//	}
//	return p;
//};


//DuLinkList *DuLinkList_Locate(DuLinkList *L, int x) {
//	DuLinkList *p = L->next, *q = L->next, *r;
//	while (q != L && q->data != x) {		
//		q = q->next;
//	}
//	if (q == L) return NULL;
//	q->freq++;
//
//	if (q->pre == L || q->pre->freq == q->freq) return NULL	;
//	
//	q->pre->next = q->next;
//	q->next->pre = q->pre; //删除结点q
//	q->next = p;
//	q->pre = p->pre;
//	p->pre->next = q;
//	p->pre = q;
//	
//	return L;
//	}

//DuLinkList *DuLinkList_Locate(DuLinkList *L, int x) {
//	DuLinkList *p = L, *q = L->next, *r;
//
//	while (q != L && q->data != x) {
//		q = q->next;
//	}
//	if (q == L)
//		return NULL;
//	q->freq++;
//	p = q->pre;
//
//	while(q->pre == L || q->pre->freq == q->freq)
//		return NULL;
//	while(q->freq > q->pre->freq){
//	q->pre->next = q->next;
//	q->next->pre = q->pre; //删除结点q
//	q->next = p;
//	q->pre = p->pre;
//	p->pre->next = q;
//	p->pre = q;
//	p = q->pre;
//}
//	return L;
//}

//建立双向链表
//struct DuLinkList *CreateList(int n) {
//	DuLinkList *head = (DuLinkList *)malloc(sizeof(DuLinkList));
//	DuLinkList *p, *q;
//	int x;
//	p = head;
//	head->data = 0;
//	head->freq = 0;
//	for (int i = 0; i < n; i++) {
//		q = (DuLinkList *)malloc(sizeof(DuLinkList));
//		scanf("%d", &x);
//		q->data = x;
//		q->freq = 0;
//		p->next = q;
//		q->pre = p;
//		p = q;
//	}
//	p->next = head;
//	head->pre = p ;
//	return head;
//}
//
////输出双向链表
//void ShowDuLinkList(struct DuLinkList *linklist) {
//	DuLinkList *p = linklist;
//	DuLinkList *q = linklist->next;
//	while (q != p) {
//		printf("%d ", q->data);
//		q = q->next;
//	}
//	printf("\n");
//}

int main() {
	struct LinkList *head = NULL;
	struct LinkList *linklist = CreatLink(head);
	Display_LinkList(linklist);
	printf("\n");
	int n, x;

//	printf("please enter the length of dulinklist\n");
//	scanf("%d", &n);
//	struct DuLinkList *linklist = CreateList( n);
//	ShowDuLinkList(linklist);


	int mink, maxk;


	int length;

	char chioce = '\0';

	printf("please enter a chioce\n");
	scanf( "%s", &chioce);

	switch (chioce) {
	case '1':
		printf("please enter the mink and maxk\n");
		scanf( "%d", &mink);
		scanf("%d", &maxk);
		Delete_LinkList(linklist, mink, maxk);
		Display_LinkList(linklist);
		break;
//	case '2':
//		printf("please enter the length of array\n");
//		scanf("%d", &length);
//		int list[length];
//		printf("please enter an array\n");
//		for(int i=0; i<length; i++){
//			scanf("%d", list[i]);
//		}
//		Oppose_List(list, length);
//		for(int j=0; j<length; j ++){
//			printf("%d\t", list[j]);
//		}
//
//		break;
//		case '3':
//			struct LinkList *tem =  Oppose_LinkList(linklist);
//			while (tem != NULL) {
//				printf("%d ", tem->data);
//				tem = tem->next;
//			}
//			break;
//		case '4':
//			while (chioce != 0) {
//				printf("please enter the number you want to locate\n");
//				scanf("%d", &x);
//				linklist = DuLinkList_Locate(linklist, x);
//				ShowDuLinkList(linklist);
//			}
//
//			break;

	}
}