#include<fstream>
#include<iostream>

using namespace std;

int main() 
{
	ifstream in("test.txt");    //���ı�ģʽ���ļ�
	if (in.fail())
	{
		cout << "file does not exist." << endl;
		exit(0);
	}

	char buf[64];
	in >> buf;            	//��ȡ���ݣ������հ׷�ͣ��
	cout << buf << endl;	//����ַ�'I'�ͻ��з�

	in.get(buf, 64);   	//Ĭ�Ͻ�������'\n'����˶�ȡ����Ϊ" love C++, yeah!"
	cout << buf << "\t" << in.rdstate() << endl;	//���buf��������0�ͻ��з�

	in.get(buf, 64);   	//ʲôҲȡ�����������ô�����
	cout << buf << "\t" << in.rdstate() << endl;	//����մ���������2�ͻ��з�

	in.clear();  			//��������־���ܼ�����ȡ����

	in.seekg(2, ios_base::cur);	//���������������ֽ�����'\n'��0D0A�����ֽڣ�
	//in.get();					//Ϊ��ֹ��ͬϵͳ�н��������ֽ�����ͬ��ɴ��󣬿�ʹ��get������ȡһ���ַ�

	in.get(buf, 64);   //��ȡ����Ϊ"I love C++, yeah!"
	cout << buf << "\t" << in.rdstate() << endl;

	//���ý�������'y'����ȡ���ݣ���ʱ���ȶ�ȡ���з���Ȼ�������ȡ��
	//ֱ��������һ���е��ַ�'y'
	in.get(buf, 64, 'y');
	cout << buf << "\t" << in.rdstate() << endl;

	in.get(buf, 64);
	cout << buf << "\t" << in.rdstate() << endl;

	// ʹ��getline����
	in.getline(buf, 64);
	cout << buf << endl;

	//�����ַ�'y'ֹͣ���������������һ�ζ�ȡʱȡ�����ַ�'y'
	in.getline(buf, 64, 'y');
	cout << buf << endl;

	in.getline(buf, 64);
	cout << buf << endl;

	//// ʹ��read����
	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;

	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;

	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;

	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;

	//in.read(buf, 10);
	//buf[10] = '\0';
	//cout << buf;


	in.close();

	return 0;
}
