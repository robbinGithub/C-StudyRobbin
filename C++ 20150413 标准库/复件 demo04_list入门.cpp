#include "iostream"
#include "list"
using namespace std;

//size push_back insert
void main_0401()
{
	//������һ������
	list<int> l;
	int len = l.size();
	cout<<len<<endl;

	//��������Ԫ�أ�β�鷨��
	for (int i=0; i<5; i++)
	{
		l.push_back(i);
	}
	 len = l.size();
	cout<<len<<endl;

	//����������һ��ָ��iterator
	list<int>::iterator current = l.begin();
	//l.end();

	while(current != l.end())
	{
		cout<<*current<<endl;
		current++;
	}

	cout<<"zouni"<<endl;
	//���������λ�ø���������ָ��
	current = l.begin();
	current ++;
	current ++;
	current ++;
	l.insert(current,100);

	for (list<int>::iterator p = l.begin(); p!=l.end(); p++)
	{
		cout<<(*p)<<endl;
	}


	system("pause");
}