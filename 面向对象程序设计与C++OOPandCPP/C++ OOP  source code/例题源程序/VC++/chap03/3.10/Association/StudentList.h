#pragma once
#include"student.h"
//class CStudent;

void showError(int idx);

class CNode
{
	friend class CStudentList;
	friend class CAssociation;
public:
	//要求p指向堆上的一个CStudent对象，且构造之后由CNode负责管理该对象
	CNode(CStudent * p) : pstu(p), ref(0), next(NULL)
	{
	}

	~CNode() { delete pstu; }
	//CStudent & get_student() { return *pstu; }
	//int increase_ref() { ++ref; }
	//int decrease_ref() { --ref; }
	//int get_ref() const { return ref; }
	//void set_next(CNode * p) { next = p; }
	//CNode * get_next() { return next; }
private:
	CNode(const CNode &);		//声明为私有函数，禁止调用
	CNode & operator=(const CNode &);	//声明为私有函数，禁止调用

	CStudent * pstu;
	int ref;
	CNode * next;
};

class CStudentList
{
public:
	CStudentList() : head(NULL), count(0) { /*head = new CNode(NULL);*/ }

	~CStudentList()
	{
		CNode * tmp = head.next;
		while (NULL != tmp)	//依次删除链表中的接点
		{
			head.next = tmp->next;
			delete tmp;
			tmp = head.next;
		}
		//delete head;		//最后删除头结点
	}

	//添加一个学生到链头，其中p指向堆中的一个CStudent对象，且执行之后该对象由CStudentList管理
	void add(CStudent * p)	
	{
		CNode * tmp = new CNode(p);
		tmp->next = head.next;
		head.next = tmp;
		++count;
	}

	//根据学号删除学生，删除成功返回0；查无此人返回1；引用数不为0不能删除返回2
	int del(int num)
	{
		CNode * tmp = head.next, *pre = NULL/*head.next*/;
		while (NULL != tmp)
		{
			if (tmp->pstu->get_number() != num)
			{
				pre = tmp;
				tmp = tmp->next;
			}
			else
				break;
		}
		if (NULL == tmp)	//查无此人
			return 1;
		else if(tmp->ref > 0) //引用数不为0，不能删除
			return 2;
		else
		{
			pre->next = tmp->next;
			delete tmp;
			--count;
			return 0;
		}
	}

	//通过学号取得学生所在结点的地址，如果学生不存在则返回空指针
	CNode * get(int num) const
	{
		CNode * tmp = head.next;
		while (NULL != tmp)
		{
			if (tmp->pstu->get_number() != num)
				tmp = tmp->next;
			else
				break;
		}
		if (NULL == tmp)	//查无此人
			return NULL;
		else
			return tmp;
	}

	int get_count() const { return count; }

	void show() const
	{
		cout << "学号\t姓名\t专业\t成绩\t引用计数" << endl;
		CNode * tmp = head.next;
		while (NULL != tmp)
		{
			cout << tmp->pstu->get_number() << "\t"
				<< tmp->pstu->get_name().get_string() << "\t"
				<< tmp->pstu->get_major().get_string() << "\t"
				<< tmp->pstu->get_score() << "\t"
				<< tmp->ref << endl;
			tmp = tmp->next;
		}
	}

private:
	//复制构造函数和赋值运算符函数声明为私有的，禁止调用。
	//另外，可以将此类设计为单件类，请自行完成
	CStudentList(const CStudentList &);
	CStudentList & operator=(const CStudentList &);

	CNode head;
	int count;
};

class CAssociation
{
public:
	CAssociation(MyString & s) : name(s), ppList(NULL), count(0) { }
	~CAssociation() //由于学生与社团是聚合关系，故此处只需要回收ppList指向的空间
	{ 
		for (int i = 0; i < count; ++i)	//在删除ppList之前将学生的引用计数减1
			--ppList[i]->ref;
		delete[] ppList; 
	}	

	int index(CNode * p) //检查p结点是否已在社团中，已在则返回其索引，否则返回-1
	{
		int i = 0;
		for (i = 0; i < count; ++i)
			if (p == ppList[i])
				return i;
		return -1;
	}

	void add(CNode * p)	//添加一个学生
	{
		if (NULL == p || index(p) >= 0)
			return;
		else
		{
			CNode ** tmp = new CNode*[count + 1];
			for (int i = 0; i < count; i++)
				tmp[i] = ppList[i];
			tmp[count] = p;
			++tmp[count]->ref;	//引用计数加1
			delete[] ppList;
			ppList = tmp;
			++count;
		}
	}

	//从社团中删除指向结点p的指针，成功删除返回0；如果学生不在社团则返回3
	int del(CNode * p)
	{
		int i = index(p);
		if (i < 0)	//学生不在社团中
			return 3;
		else
		{
			--ppList[i]->ref;	//引用计数减1
			CNode ** tmp = NULL;
			if(count > 1)
				tmp = new CNode*[count - 1];

			for (int j = 0; j < count; j++)
			{
				if (j == i)
					continue;
				if (j < i)
					tmp[j] = ppList[j];
				else
					tmp[j - 1] = ppList[j];
			}
			delete[] ppList;
			ppList = tmp;
			--count;

			return 0;
		}
	}

	void show() const
	{
		cout << name.get_string() << "成员名单：" << endl;
		cout << "学号\t姓名\t专业\t成绩" << endl;
		for(int i = 0; i < count; i++)
		{
			cout << ppList[i]->pstu->get_number() << "\t"
				<< ppList[i]->pstu->get_name().get_string() << "\t"
				<< ppList[i]->pstu->get_major().get_string() << "\t"
				<< ppList[i]->pstu->get_score() << endl;
		}
	}

private:
	CAssociation(const CAssociation &);
	CAssociation & operator=(const CAssociation &);

	MyString name;
	CNode ** ppList;
	int count;
};
