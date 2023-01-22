#ifndef __STACK_H__
#define __STACK_H__

#include"MyString.h"
template<class T> class STACKIterator;

// STACK类模板的定义
template<class T> class STACK
{
	friend class STACKIterator<T>;
public:
	STACK() : head(NULL) {  }
	virtual ~STACK()
	{
		LINK * cur = head;
		while(NULL != head)
		{
			cur = cur->next;
			delete head->data;
			delete head;
			head = cur;
		}
	}

	void push(T * data){ head = new LINK(data, head); }

	T * pop()
	{
		if(NULL == head)
			return NULL;
		else
		{
			T * result = head->data;
			LINK * oldhead = head;
			head = head->next;
			delete oldhead;
			return result;
		}
	}
	T * peek() const { return head->data; }
public:
	struct LINK
	{
		LINK * next;
		T * data;

		LINK(T * data, LINK * next)
		{
			this->data = data;
			this->next = next;
		}
	};
private:
	LINK * head;
};

// STACK类模板的迭代器的定义
template<class T> class STACKIterator
{
private:
	typename STACK<T>::LINK * p;
public:
	STACKIterator(const STACK<T> & t) : p(t.head) {  }
	STACKIterator(const STACKIterator & t) : p(t.p) {  }

	STACKIterator & operator++()  //前置++，返回引用
	{
		if(NULL != p->next)
			p = p->next;
		else
			p = NULL;
		return *this;
	}

	const STACKIterator operator++(int)  //后置++，返回常对象而非引用
	{
		STACKIterator old(*this);
		if (NULL != p->next)
			p = p->next;
		else
			p = NULL;

		return old;
	}

	T * current() const
	{
		if(NULL == p)
			return NULL;
		return p->data;
	}

	operator bool() const  //自动类型转换
	{
		return NULL == p ? false : true;
	}


};

//派生出有名STACK的类模板
template<class T> class CNamedStack : public STACK<T>
{
public:
	CNamedStack(const MyString & s) : name(s) { }
	MyString & set_name(const MyString & s) { name = s; return name; }
	const MyString & get_name() const { return name; }

private:
	MyString name;
};

//派生出一个普通类
class CIntStack : public STACK<int>
{

};


#endif