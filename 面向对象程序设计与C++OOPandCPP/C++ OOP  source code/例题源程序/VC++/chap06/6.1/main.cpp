#include<iostream>
#include"animal.h"
#include"Bird.h"
#include"Sparrow.h"
using namespace std;

int main()
{
	CAnimal * p_animal;
	CAnimal animal;
	cout << "animal��������ݣ�" << endl;
	animal.print();
	cout << "CAnimal�����Ĵ�С�ǣ�" << sizeof(animal) << "�ֽ�" << endl;

	CBird   bird;
	cout << "bird��������ݣ�" << endl;
	bird.print();	
	cout << "CBird�����Ĵ�С�ǣ�" << sizeof(bird) << "�ֽ�" << endl;
	bird.speak();
	bird.breathe();

	animal = bird;  // �����������Ը�ֵ���������
	cout << "ִ����\"animal=bird;\"��animal��������ݣ�" << endl;
	animal.print(); 
	animal.speak();
	animal.breathe();

	//CSparrow  sparrow("Sparrow", 3, 30);
	//cout << "sparrow��������ݣ�" << endl;
	//sparrow.print();
	//cout << "CSparrow�����Ĵ�С�ǣ�" << sizeof(sparrow) << "�ֽ�" << endl;
	//sparrow.speak();
	//sparrow.breathe();

	//animal = sparrow;
	//cout << "ִ����\"animal = sparrow;\"��animal��������ݣ�" << endl;
	//animal.print();
	//animal.speak();
	//animal.breathe();

	p_animal = &bird; // ����ָ�����ָ�����������
	cout << "CAnimal��ָ��ָ��CBird�����ʱ��ִ�������" << endl;
	p_animal->print();
	p_animal->speak();
	p_animal->breathe();

	//cout << "\nCAnimal��ָ��ָ��CSparrow�����ʱ��ִ�������" << endl;
	//p_animal = &sparrow;
	//p_animal->print();
	//p_animal->speak();
	//p_animal->breathe();

 	return 0;
}
