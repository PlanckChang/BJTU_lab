#include<iostream>
#include"animal.h"
#include"Bird.h"
#include"Sparrow.h"
using namespace std;

int main()
{
	CAnimal * p_animal;
	CAnimal animal;
	cout << "animal对象的内容：" << endl;
	animal.print();
	cout << "CAnimal类对象的大小是：" << sizeof(animal) << "字节" << endl;

	CBird   bird;
	cout << "bird对象的内容：" << endl;
	bird.print();	
	cout << "CBird类对象的大小是：" << sizeof(bird) << "字节" << endl;
	bird.speak();
	bird.breathe();

	animal = bird;  // 派生类对象可以赋值给基类对象
	cout << "执行了\"animal=bird;\"后animal对象的内容：" << endl;
	animal.print(); 
	animal.speak();
	animal.breathe();

	//CSparrow  sparrow("Sparrow", 3, 30);
	//cout << "sparrow对象的内容：" << endl;
	//sparrow.print();
	//cout << "CSparrow类对象的大小是：" << sizeof(sparrow) << "字节" << endl;
	//sparrow.speak();
	//sparrow.breathe();

	//animal = sparrow;
	//cout << "执行了\"animal = sparrow;\"后animal对象的内容：" << endl;
	//animal.print();
	//animal.speak();
	//animal.breathe();

	p_animal = &bird; // 基类指针可以指向派生类对象
	cout << "CAnimal类指针指向CBird类对象时的执行情况：" << endl;
	p_animal->print();
	p_animal->speak();
	p_animal->breathe();

	//cout << "\nCAnimal类指针指向CSparrow类对象时的执行情况：" << endl;
	//p_animal = &sparrow;
	//p_animal->print();
	//p_animal->speak();
	//p_animal->breathe();

 	return 0;
}
