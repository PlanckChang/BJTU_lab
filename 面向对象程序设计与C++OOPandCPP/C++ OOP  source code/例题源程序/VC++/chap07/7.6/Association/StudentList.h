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
	CStudent * get_student() { return pstu; }
	int get_ref() const { return ref; }
	void set_next(CNode * p) { next = p; }
	CNode * get_next() { return next; }
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
	CStudentList() : head(NULL), count(0) { }

	virtual ~CStudentList()
	{
		CNode * tmp = head.next;
		while (NULL != tmp)	//依次删除链表中的接点
		{
			head.next = tmp->next;
			delete tmp;
			tmp = head.next;
		}
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
		CNode * tmp = head.next, *pre = NULL;
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

	//void show() const
	//{
	//	cout << "学号\t姓名\t专业\t\t成绩\t导师\t引用计数" << endl;
	//	CNode * tmp = head->next;
	//	while (NULL != tmp)
	//	{
	//		tmp->get_student()->display(cout);
	//		cout << "\t";
	//		if (NULL == dynamic_cast<CGraduate*>(tmp->get_student()))
	//			cout << "\t";

	//		cout << tmp->ref << endl;
	//		tmp = tmp->next;
	//	}
	//}

	bool clear() //清空当前对象中的数据，成功返回true，否则返回false
	{
		bool flag = true;
		CNode * tmp = head.next;
		while (NULL != tmp)	//依次删除链表中的接点
		{
			if (0 == tmp->ref)
			{
				head.next = tmp->next;
				delete tmp;
				tmp = head.next;
				--count;
			}
			else
			{
				flag = false;
				break;
			}
		}
		return flag;
	}

protected:
	//因使用多态，无法实现复制构造函数和赋值运算符，故将它们设为私有的
	CStudentList(const CStudentList & stuMng);
	CStudentList & operator=(const CStudentList & stuMng);

	CNode head;
	int count;
};

//可以扩展学生列表类，在其中只实现读写的功能函数。注意：该类中能够管理的学生类型是已知的
//这里只实现二进制格式的读写
class CStudentListEx : public CStudentList
{
public:
	void show() //const
	{
		cout << "学号\t姓名\t专业\t\t成绩\t导师\t引用计数" << endl;
		CNode * tmp = head.get_next();
		while (NULL != tmp)
		{
			tmp->get_student()->show(cout);
			cout << "\t";
			if (NULL == dynamic_cast<CGraduate*>(tmp->get_student()))
				cout << "\t";

			cout << tmp->get_ref() << endl;
			tmp = tmp->get_next();
		}
	}

	void write_binary(ostream & out)
	{
		//取得每一个学生并逐个写入文件：本科生的标记为1，研究生的标记为2
		int flag = 1;
		CStudent * p = NULL;
		CNode * tmp = head.get_next();
		while (NULL != tmp)
		{
			flag = 1;
			p = tmp->get_student();
			if (dynamic_cast<CGraduate*>(p))
				flag = 2;
			out.write((char*)&flag, sizeof(int));
			p->write_binary(out);  //写学生信息
			tmp = tmp->get_next();
		}
		flag = -1;
		out.write((char*)&flag, sizeof(int));	//-1作为结束标记
	}

	bool read_binary(istream & in)
	{
		if (!this->clear())
			return false;

		int flag;
		CStudent * p = NULL;
		in.read((char*)&flag, sizeof(int));
		while (-1 != flag)
		{
			if (1 == flag)	//是本科生
				p = new CStudent;
			else
				p = new CGraduate;
			p->read_binary(in);
			this->add(p);
			in.read((char*)&flag, sizeof(int));
		}
		return true;
	}
};

//社团类不在讲义中
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
		cout << "学号\t姓名\t专业\t\t成绩\t导师\t引用计数" << endl;
		for(int i = 0; i < count; ++i)
		{
			ppList[i]->get_student()->show(cout);
			cout << "\t";
			if (NULL == dynamic_cast<CGraduate*>(ppList[i]->get_student()))
				cout << "\t";

			cout << ppList[i]->get_ref() << endl;
		}
	}

	void clear()
	{
		for (int i = 0; i < count; ++i)
			--ppList[i]->ref;
		delete ppList;
		ppList = NULL;
		count = 0;
	}

	void write_binary(ostream & out)
	{
		//只需要写入学号
		int number;
		for (int i = 0; i < count; ++i)
		{
			number = ppList[i]->get_student()->get_number();
			out.write((char*)&number, sizeof(int));
		}
		number = -1;
		out.write((char*)&number, sizeof(int));	//-1作为结束标记

		//以下是一个典型的错误实现
		//CStudent * p = NULL;
		//CNode * tmp = ppList[0];
		//while (NULL != tmp)
		//{
		//	int num = tmp->get_student()->get_number();
		//	out.write((char*)&num, sizeof(int));
		//	tmp = tmp->get_next();
		//}
	}

	bool read_binary(istream & in, const CStudentList & list)
	{
		this->clear();
		int number;
		in.read((char*)&number, sizeof(int));
		while (-1 != number)
		{
			CNode * p = list.get(number);
			this->add(p);
			in.read((char*)&number, sizeof(int));
		}
		return true;
	}
private:
	CAssociation(const CAssociation &);
	CAssociation & operator=(const CAssociation &);

	MyString name;
	CNode ** ppList;
	int count;
};
