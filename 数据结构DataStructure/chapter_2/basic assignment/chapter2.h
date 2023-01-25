#ifndef _CHAPTER2_H_
#define _CHAPTER2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct LinkList {
	int data;
	struct LinkList *next;
};


struct DuLinkList {
	struct DuLinkList *pre;
	int data;
	int freq;
	struct DuLinkList *next;
};





#endif

