//双向循环链表的Locate函数

#include "chapter2.h"

int DuLinkList_Locate(struct DuLinkList*dulinklist, int x){
	struct DuLinkList *q, *p; 
	p = dulinklist->next;
	
	while(p!=list&&p->data!=x) p= p->next;
	if(p= list) return 0;
	else{
		p->freq++;
		q = p->pre;
		while(p->pre != list && q->qreq < p->qreq ){	
			q->next = p->next;
			p->pre = q->pre;
			p->next = q;
			q->pre = p;			
		} 		
	}
	return 1;
};