#include"BigInt.h"

int CBigInt::BASE = 10000;
int CBigInt::SIZE = MINI;// SMALL;

//����������ʱ����0�⣬Ҫ�ӵ�һ����Ч���ֿ�ʼ����
istream & operator >> (istream & in, CBigInt & val)
{
	char * tmp = new char[CBigInt::SIZE * sizeof(int) + 3]; //���ַ�����ʽ�������������
	in >> tmp;
	int size = strlen(tmp);
	//����Ƿ��зǷ��ַ�
	int i = 0;
	if (tmp[0] == '-')
		i++;
	while (isdigit(tmp[i])) i++;
	if (i < size)
		exit(1);
	//�޷Ƿ��ַ�����ֵ������Ǹ�������ҪתΪ����
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
	else  //�ǷǸ���
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