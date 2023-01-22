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
	//CStudent & get_student() { return *pstu; }
	//int increase_ref() { ++ref; }
	//int decrease_ref() { --ref; }
	//int get_ref() const { return ref; }
	//void set_next(CNode * p) { next = p; }
	//CNode * get_next() { return next; }
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

private:
	//���ƹ��캯���͸�ֵ�������������Ϊ˽�еģ���ֹ���á�
	//���⣬���Խ��������Ϊ�����࣬���������
	CStudentList(const CStudentList &);
	CStudentList & operator=(const CStudentList &);

	CNode head;
	int count;
};

class CAssociation
{
public:
	CAssociation(MyString & s) : name(s), ppList(NULL), count(0) { }
	~CAssociation() //����ѧ���������ǾۺϹ�ϵ���ʴ˴�ֻ��Ҫ����ppListָ��Ŀռ�
	{ 
		for (int i = 0; i < count; ++i)	//��ɾ��ppList֮ǰ��ѧ�������ü�����1
			--ppList[i]->ref;
		delete[] ppList; 
	}	

	int index(CNode * p) //���p����Ƿ����������У������򷵻������������򷵻�-1
	{
		int i = 0;
		for (i = 0; i < count; ++i)
			if (p == ppList[i])
				return i;
		return -1;
	}

	void add(CNode * p)	//���һ��ѧ��
	{
		if (NULL == p || index(p) >= 0)
			return;
		else
		{
			CNode ** tmp = new CNode*[count + 1];
			for (int i = 0; i < count; i++)
				tmp[i] = ppList[i];
			tmp[count] = p;
			++tmp[count]->ref;	//���ü�����1
			delete[] ppList;
			ppList = tmp;
			++count;
		}
	}

	//��������ɾ��ָ����p��ָ�룬�ɹ�ɾ������0�����ѧ�����������򷵻�3
	int del(CNode * p)
	{
		int i = index(p);
		if (i < 0)	//ѧ������������
			return 3;
		else
		{
			--ppList[i]->ref;	//���ü�����1
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
		cout << name.get_string() << "��Ա������" << endl;
		cout << "ѧ��\t����\tרҵ\t�ɼ�" << endl;
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
