#include "iostream"
#include "algorithm" //�㷨 
#include "cmath"     //��ѧ���
#include "vector"
using namespace std;

//����һ����ʦ

//��ӡ��ҵ�����ݽṹ�����ϲ�����飬stl����û�б�Ҫȥ���ģ�
void callbakFunc(int &v)
{
	cout<<v<<endl;
}
int comp(const int &a, const int &b)
{
	return a<b;
}
void main_05()
{
	vector<int> v(5);
	for (int i=0; i<5; i++)
	{
		v[i] = rand()%10;
	}

	for (int i=0; i<5; i++)
	{
		printf("%d ", v[i]);
	}

	for_each(v.begin(),v.end(), callbakFunc);

	sort(v.begin(),v.end(), comp);

	for (int i=0; i<5; i++)
	{
		printf("%d ", v[i]);
	}


	
	
	system("pause");
}
