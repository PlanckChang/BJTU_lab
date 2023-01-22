#ifndef __STACK_H__
#define __STACK_H__
#include<iostream>

template<class T> class STACK
{
public:
	STACK() : head(NULL) {  }
	virtual ~STACK();
	void push(T * data) { head = new link(data, head); }
	T * pop();
	T * peek() const { return head->data; }
private:
	struct link
	{
		link * next;
		T * data;

		link(T * data, link * next)
		{
			this->data = data;
			this->next = next;
		}
	} *head;
};

template<class T> T * STACK<T>::pop()
{
	if (NULL == head)
		return NULL;
	else
	{
		T * result = head->data;
		link * oldhead = head;
		head = head->next;
		delete oldhead;
		return result;
	}
}

template<class T> STACK<T>::~STACK()
{
	link * cur = head;
	while (NULL != head)
	{
		cur = cur->next;
		delete head->data;
		delete head;
		head = cur;
	}
}

#endif
