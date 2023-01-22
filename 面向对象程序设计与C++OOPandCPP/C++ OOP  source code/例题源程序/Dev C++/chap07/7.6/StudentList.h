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
	CStudent * get_student() { return pstu; }
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
	CStudentList() : head(NULL), count(0) { }

	virtual ~CStudentList()
	{
		CNode * tmp = head.next;
		while (NULL != tmp)	//����ɾ�������еĽӵ�
		{
			head.next = tmp->next;
			delete tmp;
			tmp = head.next;
		}
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

	//void show() const
	//{
	//	cout << "ѧ��\t����\tרҵ\t\t�ɼ�\t��ʦ\t���ü���" << endl;
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

	bool clear() //��յ�ǰ�����е����ݣ��ɹ�����true�����򷵻�false
	{
		bool flag = true;
		CNode * tmp = head.next;
		while (NULL != tmp)	//����ɾ�������еĽӵ�
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
	//��ʹ�ö�̬���޷�ʵ�ָ��ƹ��캯���͸�ֵ��������ʽ�������Ϊ˽�е�
	CStudentList(const CStudentList & stuMng);
	CStudentList & operator=(const CStudentList & stuMng);

	CNode head;
	int count;
};

//������չѧ���б��࣬������ֻʵ�ֶ�д�Ĺ��ܺ�����ע�⣺�������ܹ������ѧ����������֪��
//����ֻʵ�ֶ����Ƹ�ʽ�Ķ�д
class CStudentListEx : public CStudentList
{
public:
	void show() //const
	{
		cout << "ѧ��\t����\tרҵ\t\t�ɼ�\t��ʦ\t���ü���" << endl;
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
		//ȡ��ÿһ��ѧ�������д���ļ����������ı��Ϊ1���о����ı��Ϊ2
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
			p->write_binary(out);  //дѧ����Ϣ
			tmp = tmp->get_next();
		}
		flag = -1;
		out.write((char*)&flag, sizeof(int));	//-1��Ϊ�������
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
			if (1 == flag)	//�Ǳ�����
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

//�����಻�ڽ�����
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
		cout << "ѧ��\t����\tרҵ\t\t�ɼ�\t��ʦ\t���ü���" << endl;
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
		//ֻ��Ҫд��ѧ��
		int number;
		for (int i = 0; i < count; ++i)
		{
			number = ppList[i]->get_student()->get_number();
			out.write((char*)&number, sizeof(int));
		}
		number = -1;
		out.write((char*)&number, sizeof(int));	//-1��Ϊ�������

		//������һ�����͵Ĵ���ʵ��
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
