#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/**
*  ���嶯���ࣺAnimal
*  ��Ա������eat()��move()
*/
class Animal
{
public:
	// Ĭ�Ϲ��캯��
	Animal(){ cout << "Animal" << endl; }
	// ���ι��캯��
	Animal(string name){ m_strName = name; cout << "Animal" << endl; }
	// ��������
	virtual ~Animal(){ cout << "~Animal" << endl; }
	// ��Ա����eat()
	virtual void eat(){ cout << "Animal -- eat" << endl; }
	// ��Ա����move()
	virtual void move() = 0;
public :
	string m_strName;
};

/**
* ���幷�ࣺDog
* ���๫�м̳ж�����
* ��Ա�����������еĳ�Ա����
*/
class Dog : public Animal
{
public:
	// Ĭ�Ϲ��캯��
	Dog(string name){ cout << "Dog" << endl; }
	// ���ι��캯��
	Dog(string name):Animal(name){ cout << "Dog" << endl; }
	// ��������
	virtual ~Dog(){ cout << "~Dog" << endl; }
	// ��Ա����eat()
	virtual void eat(){ cout << "Dog -- eat" << endl; }
	// ��Ա����move()
	virtual void move(){ cout << "Dog -- move" << endl; }
};

int main3(void)
{
	// ͨ���������ʵ��������
	Animal* animal = new  Dog();

	// ���ó�Ա����
	animal->eat();
	// �ͷ��ڴ�
	delete animal;
	animal = NULL;

	return 0;
}