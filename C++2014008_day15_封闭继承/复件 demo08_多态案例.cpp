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

//һ��ģ�� ����������������ɿ���ǡ�������������
void ObjFighter(HeroFighter *pBase, EnemyFighter *pEnemy)
{
	if (pBase->AttackPower() > pEnemy->DestoryPower())
	{
		printf("����win\n");
	}
	else
	{
		printf("���ǹ���\n");
	}
}
void main81()
{
	HeroFighter h1;
	EnemyFighter e1;
	HeroAdv2Fighter hAdvF;

	if (h1.AttackPower() > e1.DestoryPower())
	{
		printf("����win\n");
	}
	else
	{
		printf("���ǹ���\n");
	}

	if (hAdvF.AttackPower() > e1.DestoryPower())
	{
		printf("����win\n");
	}
	else
	{
		printf("���ǹ���\n");
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


