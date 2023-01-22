#include"BigInt.h"

int CBigInt::BASE = 10000;
int CBigInt::SIZE = MINI;// SMALL;

//在输入数据时，除0外，要从第一个有效数字开始输入
istream & operator >> (istream & in, CBigInt & val)
{
	char * tmp = new char[CBigInt::SIZE * sizeof(int) + 3]; //以字符串形式保存输入的数据
	in >> tmp;
	int size = strlen(tmp);
	//检查是否有非法字符
	int i = 0;
	if (tmp[0] == '-')
		i++;
	while (isdigit(tmp[i])) i++;
	if (i < size)
		exit(1);
	//无非法字符。赋值，如果是负数，需要转为补码
	int degree = 1, value = 0, j = size - 1;
	if (tmp[0] == '-')
	{
		i = CBigInt::SIZE - 1;
		while (i >= 0 && j > 0)
		{
			degree = 1;
			value = 0;
			while (degree < CBigInt::BASE && j > 0)
			{
				value = value + (tmp[j] - '0') * degree;
				degree *= 10;
				j--;
			}
			val.pbuf[i] = CBigInt::BASE - 1 - value;
			i--;
		}

		while (i >= 0)
		{
			val.pbuf[i] = CBigInt::BASE - 1;
			i--;
		}
		val.operator++();
		val.pbuf[0] = ((val.pbuf[0] / (CBigInt::BASE / 10)) % 2) * 9000 + val.pbuf[0] % (CBigInt::BASE / 10);
	}
	else  //是非负数
	{
		i = CBigInt::SIZE - 1;
		while (i >= 0 && j >= 0)
		{
			degree = 1;
			value = 0;
			while (degree < CBigInt::BASE && j >= 0)
			{
				value = value + (tmp[j] - '0') * degree;
				degree *= 10;
				j--;
			}
			val.pbuf[i] = value;
			i--;
		}

		while (i >= 0)
		{
			val.pbuf[i] = 0;
			i--;
		}

		val.pbuf[0] = ((val.pbuf[0] / (CBigInt::BASE / 10)) % 2) * 9000 + val.pbuf[0] % (CBigInt::BASE / 10);
	}

	return in;
}

ostream & operator << (ostream & out, CBigInt & val)
{
	val.print(out);
	return out;
}