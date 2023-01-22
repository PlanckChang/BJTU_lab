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

	//一个大整数与一个int型值相加
	CBigInt operator+(int num)
	{
		CBigInt tmp(num);
		return tmp += *this;
	}

	//一个大整数与一个int型值相加
	CBigInt & operator+=(int num)
	{
		CBigInt tmp(num);
		return *this += tmp;
	}

	//一个大整数与一个int型值相减
	CBigInt operator-(int num)
	{
		CBigInt tmp(*this);
		return tmp -= num;
	}

	//一个大整数与一个int型值相减
	CBigInt & operator-=(int num)
	{
		CBigInt tmp(num);
		return *this -= tmp;
	}

	//在输入数据时，除0外，要从第一个有效数字开始输入
	friend istream & operator >> (istream & in, CBigInt & val);
	friend ostream & operator << (ostream & out, CBigInt & val);

	//以十进制格式输出大整数
	void print(ostream & out = cout)
	{
		char prev;
		int i = 0;
		if (pbuf[0] < (BASE / 10))	//如果是非负数
		{
			while (i < SIZE && pbuf[i] == 0) i++;	//跳过前面可能的0
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
		else	//如果是负数
		{
			//补码转为原码
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
			//输出数值
			i = 0;
			while (i < SIZE && tmp[i] == 0) i++;	//跳过前面可能的0
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
	static int BASE;	//每个部分的计数，这里是10000
	static int SIZE;	//大整数一共多少位（当前进制下），例如99999999在万进制下是2位
	int * pbuf;			//保存大整数，高位在前，低位在后，第一位为0表示非负，9表示负
};

