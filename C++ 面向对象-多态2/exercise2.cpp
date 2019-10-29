#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/**
*  定义动物类：Animal
*  成员函数：eat()、move()
*/
class Animal
{
public:
	// 默认构造函数
	Animal(){ cout << "Animal" << endl; }
	// 含参构造函数
	Animal(string name){ m_strName = name; cout << "Animal" << endl; }
	// 析构函数
	virtual ~Animal(){ cout << "~Animal" << endl; }
	// 成员函数eat()
	virtual void eat(){ cout << "Animal -- eat" << endl; }
	// 成员函数move()
	virtual void move() = 0;
public :
	string m_strName;
};

/**
* 定义狗类：Dog
* 此类公有继承动物类
* 成员函数：父类中的成员函数
*/
class Dog : public Animal
{
public:
	// 默认构造函数
	Dog(string name){ cout << "Dog" << endl; }
	// 含参构造函数
	Dog(string name):Animal(name){ cout << "Dog" << endl; }
	// 析构函数
	virtual ~Dog(){ cout << "~Dog" << endl; }
	// 成员函数eat()
	virtual void eat(){ cout << "Dog -- eat" << endl; }
	// 成员函数move()
	virtual void move(){ cout << "Dog -- move" << endl; }
};

int main3(void)
{
	// 通过父类对象实例化狗类
	Animal* animal = new  Dog();

	// 调用成员函数
	animal->eat();
	// 释放内存
	delete animal;
	animal = NULL;

	return 0;
}