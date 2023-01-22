#pragma once
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

enum {MINI = 4, SMALL = 16, NORMAL = 32, BIG = 64, LARGE = 128};
class CBigInt
{
public:

	CBigInt()
	{
		pbuf = new int[SIZE];
		memset(pbuf, 0, SIZE * sizeof(int));
	}

	CBigInt(int val)
	{
		pbuf = new int[SIZE];
		memset(pbuf, 0, SIZE * sizeof(int));
		int i = SIZE - 1, k = 0;
		if (val >= 0)
		{
			while (val > 0)
			{
				k = val % BASE;
				val = val / BASE;
				pbuf[i] = k;
				i--;
			}
		}
		else
		{
			while (val < 0)
			{
				k = val % BASE;
				val = val / BASE;
				pbuf[i] = BASE - 1 + k;
				i--;
			}

			while (i >= 0)
			{
				pbuf[i] = BASE - 1;
				i--;
			}

			operator++();
		}
	}

	CBigInt(const CBigInt & big)
	{
		pbuf = new int[SIZE];
		memcpy(pbuf, big.pbuf, SIZE * sizeof(int));
	}

	~CBigInt()
	{
		delete[] pbuf;
	}

	CBigInt & operator++()
	{
		int i = SIZE - 1;
		while(i >= 0)
		{
			pbuf[i]++;
			if (pbuf[i] >= BASE)
			{
				pbuf[i] -= BASE;
				i--;
			}
			else
				break;
		}
		if(pbuf[0] >= BASE / 10)
			pbuf[0] = (pbuf[0] / (BASE / 10)) % 2 * 9000 + pbuf[0] % (BASE / 10);
		return *this;
	}

	CBigInt operator++(int)
	{
		CBigInt big(*this);
		this->operator++();
		return big;
	}

	CBigInt & operator--()
	{
		int i = SIZE - 1;
		while (i >= 0)
		{
			pbuf[i]--;
			if (pbuf[i] < 0)
			{
				pbuf[i] = BASE + pbuf[i];
				i--;
			}
			else
				break;
		}
		pbuf[0] = (pbuf[0] / (BASE / 10)) % 2 * 9000 + pbuf[0] % (BASE / 10);
		return *this;
	}

	CBigInt operator--(int)
	{
		CBigInt big(*this);
		this->operator--();
		return big;
	}

	CBigInt operator+(const CBigInt & val)
	{
		CBigInt tmp(*this);
		int i = SIZE - 1, pos = 0;
		while (i >= 0)
		{
			tmp.pbuf[i] += val.pbuf[i] + pos;
			if (tmp.pbuf[i] >= BASE)
			{
				tmp.pbuf[i] -= BASE;
				pos = 1;
			}
			else
				pos = 0;
			i--;
		}
		tmp.pbuf[0] = (tmp.pbuf[0] / (BASE / 10)) % 2 * 9000 + tmp.pbuf[0] % (BASE / 10);
		return tmp;
	}

	CBigInt & operator+=(const CBigInt & val)
	{
		int i = SIZE - 1, pos = 0;
		while (i >= 0)
		{
			pbuf[i] += val.pbuf[i] + pos;
			if (pbuf[i] >= BASE)
			{
				pbuf[i] -= BASE;
				pos = 1;
			}
			else
				pos = 0;
			i--;
		}
		pbuf[0] = (pbuf[0] / (BASE / 10)) % 2 * 9000 + pbuf[0] % (BASE / 10);
		return *this;
	}

	CBigInt operator-(const CBigInt & val)
	{
		CBigInt tmp(*this);
		int i = SIZE - 1, pos = 0;
		while (i >= 0)
		{
			tmp.pbuf[i] -= val.pbuf[i] + pos;
			if (tmp.pbuf[i] < 0)
			{
				tmp.pbuf[i] += BASE;
				pos = 1;
			}
			else
				pos = 0;
			i--;
		}
		tmp.pbuf[0] = (tmp.pbuf[0] / (BASE / 10)) % 2 * 9000 + tmp.pbuf[0] % (BASE / 10);
		return tmp;
	}

	CBigInt & operator-=(const CBigInt & val)
	{
		int i = SIZE - 1, pos = 0;
		while (i >= 0)
		{
			pbuf[i] -= val.pbuf[i] + pos;
			if (pbuf[i] < 0)
			{
				pbuf[i] += BASE;
				pos = 1;
			}
			else
				pos = 0;
			i--;
		}
		pbuf[0] = (pbuf[0] / (BASE / 10)) % 2 * 9000 + pbuf[0] % (BASE / 10);
		return *this;
	}

	//һ����������һ��int��ֵ���
	CBigInt operator+(int num)
	{
		CBigInt tmp(num);
		return tmp += *this;
	}

	//һ����������һ��int��ֵ���
	CBigInt & operator+=(int num)
	{
		CBigInt tmp(num);
		return *this += tmp;
	}

	//һ����������һ��int��ֵ���
	CBigInt operator-(int num)
	{
		CBigInt tmp(*this);
		return tmp -= num;
	}

	//һ����������һ��int��ֵ���
	CBigInt & operator-=(int num)
	{
		CBigInt tmp(num);
		return *this -= tmp;
	}

	//����������ʱ����0�⣬Ҫ�ӵ�һ����Ч���ֿ�ʼ����
	friend istream & operator >> (istream & in, CBigInt & val);
	friend ostream & operator << (ostream & out, CBigInt & val);

	//��ʮ���Ƹ�ʽ���������
	void print(ostream & out = cout)
	{
		char prev;
		int i = 0;
		if (pbuf[0] < (BASE / 10))	//����ǷǸ���
		{
			while (i < SIZE && pbuf[i] == 0) i++;	//����ǰ����ܵ�0
			if (i < SIZE)
			{
				out << pbuf[i];
				prev = out.fill('0');
				i++;
				while (i < SIZE)
				{
					out << setw(4) << pbuf[i];
					i++;
				}
				out.fill(prev);
			}
			else
				out << 0;

		}
		else	//����Ǹ���
		{
			//����תΪԭ��
			int * tmp = new int[SIZE];
			for (i = 0; i < SIZE; i++)
				tmp[i] = BASE - 1 - pbuf[i];
			i = SIZE - 1;
			while (i >= 0)
			{
				tmp[i]++;
				if (tmp[i] >= BASE)
				{
					tmp[i] -= BASE;
					i--;
				}
				else
					break;
			}
			//�����ֵ
			i = 0;
			while (i < SIZE && tmp[i] == 0) i++;	//����ǰ����ܵ�0
			out << "-" << tmp[i];
			prev = out.fill('0');
			i++;
			while (i < SIZE)
			{
				out << setw(4) << tmp[i];
				i++;
			}
			out.fill(prev);
		}		
	}
private:
	static int BASE;	//ÿ�����ֵļ�����������10000
	static int SIZE;	//������һ������λ����ǰ�����£�������99999999�����������2λ
	int * pbuf;			//�������������λ��ǰ����λ�ں󣬵�һλΪ0��ʾ�Ǹ���9��ʾ��
};

