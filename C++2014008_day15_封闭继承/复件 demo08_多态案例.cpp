#include <iostream>
using namespace std;

class HeroFighter
{
public:
	virtual int AttackPower()
	{
		return 10;
	}
};

class EnemyFighter
{
public:
	int DestoryPower()
	{
		return 15;
	}
};

class HeroAdv2Fighter : public HeroFighter
{
public:
	int AttackPower()
	{
		//HeroFighter::AttackPower()*2;
		return 20;
	}
protected:
private:
};

//一个模型 如果你把这个函数做成框架那。。。。。。。
void ObjFighter(HeroFighter *pBase, EnemyFighter *pEnemy)
{
	if (pBase->AttackPower() > pEnemy->DestoryPower())
	{
		printf("主角win\n");
	}
	else
	{
		printf("主角挂了\n");
	}
}
void main81()
{
	HeroFighter h1;
	EnemyFighter e1;
	HeroAdv2Fighter hAdvF;

	if (h1.AttackPower() > e1.DestoryPower())
	{
		printf("主角win\n");
	}
	else
	{
		printf("主角挂了\n");
	}

	if (hAdvF.AttackPower() > e1.DestoryPower())
	{
		printf("主角win\n");
	}
	else
	{
		printf("主角挂了\n");
	}

	system("pause");
}


void main()
{
	HeroFighter h1;
	EnemyFighter e1;
	HeroAdv2Fighter hAdvF;

	ObjFighter(&h1, &e1);

	ObjFighter(&hAdvF,  &e1);


	system("pause");
}


