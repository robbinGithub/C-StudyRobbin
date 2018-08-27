#include <iostream>
#include <memory>
using namespace std;

void Func1(shared_ptr<int> a)
{
	cout << "Enter Func1" << endl;
	cout << "Ref count: " << a.use_count() << endl;
	cout << "Leave Func1" << endl;
}

shared_ptr<int> Func2(shared_ptr<int>& a)
{
	cout << "Enter Func2" << endl;
	cout << "Ref count: " << a.use_count() << endl;
	cout << "Leave Func2" << endl;
	return a;
}

int main()
{
	//����һ��ָ��int���Ͷ����ָ��aObj1,���ü���+1
	shared_ptr<int> aObj1(new int(10));
	cout << "Ref count: " << aObj1.use_count() << endl;

	{
		//ͬaObj1,������������������������,����aObj2�ᱻ����
		shared_ptr<int> aObj2 = aObj1;
		cout << "Ref count: " << aObj2.use_count() << endl;//���ü���-1
	}

	//�ڵ��ú���ʱ,����Ϊshared_ptr����,����Ϊ��ֵ����,����ָ�����ü���+1
	Func1(aObj1);

	//�ڵ��ú���ʱ,����Ϊshared_ptr����,����Ϊ����������,����ָ�����ü�������
	Func2(aObj1);

	shared_ptr<int> aObj3 = Func2(aObj1);//���ü���+1
	cout << "Ref count:" << aObj3.use_count() << endl;

	return 0;
}