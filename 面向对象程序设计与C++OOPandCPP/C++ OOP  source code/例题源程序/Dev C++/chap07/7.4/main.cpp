#include<iostream>
#include"animal.h"
#include"Bird.h"
#include"Sparrow.h"
using namespace std;

int main()
{
	CAnimal * p_animal;
	CSparrow  sparrow("Sparrow", 3, 30);

	p_animal = &sparrow;
	p_animal->print();
	p_animal->speak();
	p_animal->breathe();

	return 0;

}
