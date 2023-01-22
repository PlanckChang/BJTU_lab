#pragma once
#include"student.h"
//class CStudent;

void showError(int idx);

class CNode
{
	friend class CStudentList;
	friend class CAssociation;
public:
	//Ҫ��pָ����ϵ�һ��CStudent�����ҹ���֮����CNode�������ö���
	CNode(CStudent * p) : pstu(p), ref(0), next(NULL)
	{
	}

	~CNode() { delete pstu; }
	CStudent & get_student() { return *pstu; }
	int increase_ref() { ++ref; }
	int decrease_ref() { --ref; }
	int get_ref() const { return ref; }
	void set_next(CNode * p) { next = p; }
	CNode * get_next() { return next; }
private:
	CNode(const CNode &);		//����Ϊ˽�к�������ֹ����
	CNode & operator=(const CNode &);	//����Ϊ˽�к�������ֹ����

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
		while (NULL != tmp)	//����ɾ�������еĽӵ�
		{
			head.next = tmp->next;
			delete tmp;
			tmp = head.next;
		}
		//delete head;		//���ɾ��ͷ���
	}

	//���һ��ѧ������ͷ������pָ����е�һ��CStudent������ִ��֮��ö�����CStudentList����
	void add(CStudent * p)	
	{
		CNode * tmp = new CNode(p);
		tmp->next = head.next;
		head.next = tmp;
		++count;
	}

	//����ѧ��ɾ��ѧ����ɾ���ɹ�����0�����޴��˷���1����������Ϊ0����ɾ������2
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
		if (NULL == tmp)	//���޴���
			return 1;
		else if(tmp->ref > 0) //��������Ϊ0������ɾ��
			return 2;
		else
		{
			pre->next = tmp->next;
			delete tmp;
			--count;
			return 0;
		}
	}

	//ͨ��ѧ��ȡ��ѧ�����ڽ��ĵ�ַ�����ѧ���������򷵻ؿ�ָ��
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
		if (NULL == tmp)	//���޴���
			return NULL;
		else
			return tmp;
	}

	int get_count() const { return count; }

	void show() const
	{
		cout << "ѧ��\t����\tרҵ\t�ɼ�\t���ü���" << endl;
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

	ofstream & write_text(ofstream & out)
	{
		CNode * p = head.next;
		while (NULL != p)
		{
			p->pstu->write_text(out);
			p = p->next;
		}
		return out;
	}

	ifstream & read_text(ifstream & in)
	{
		CStudent * p;
		in.get();
		while (!in.eof())
		{
			in.seekg(-1, ios_base::cur);
			p = new CStudent;
			p->read_text(in);
			add(p);
			in.get();
		}
		return in;
	}
private:
	//���ƹ��캯���͸�ֵ�������������Ϊ˽�еģ���ֹ���á�
	//���⣬���Խ��������Ϊ�����࣬���������
	CStudentList(const CStudentList &);
	CStudentList & operator=(const CStudentList &);

	CNode head;
	int count;
};

