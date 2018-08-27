#include "iostream"
using namespace std;

class base
{
public:
	int k;

	void printI()
	{
		//cout<<i<<endl;
	}
protected:
private:

};

class base1 : virtual public base
{
public:
	int i;
	void printI()
	{
		cout<<i<<endl;
	}
protected:
private:

};

class base2 : virtual public base
{
public:
	int j;
	void printJ()
	{
		cout<<j<<endl;
	}
protected:
private:
};

class  C : public base1, public base2
{
public:
protected:
private:
};

void main080()
{

	C c1;
	c1.k = 100;
	//c1.i = 10;
	//c1.j = 20;
	//c1.printI();
	//c1.printJ();

	system("pause");
}