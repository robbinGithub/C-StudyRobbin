#include <iostream>

// using namespace std;

template<class T>

class shared_ptr {
private:

	T* m_ptr; //����װ��ָ��

	unsigned int shared_count;   //���ü���,��ʾ�ж��ٸ�����ָ�����ӵ��m_ptrָ����ڴ��

public:

	shared_ptr(T* p) :m_ptr(p), shared_count(1) { }

	~shared_ptr() { deconstruct(); }

	void deconstruct() {

		if (shared_count == 1)   //���ü���Ϊ1��ʾֻ��һ������ʹ��ָ��ָ����ڴ����

		{

			delete m_ptr;

			m_ptr = 0;

		}

		shared_count--;

	}

	T& operator*() { return *m_ptr; }

	T* operator->() { return m_ptr; }



	//���ƹ��캯��

	shared_ptr(shared_ptr& sp) :m_ptr(sp.m_ptr), shared_count(sp.shared_count) {

		std::cout << "���ø��ƹ��캯��" << std::endl;
		shared_count++;

	}

	//���������=

	shared_ptr& operator = (shared_ptr& sp) {

		std::cout << "�������������=" << std::endl;

		sp.shared_count++;

		deconstruct();  //�൱����ɾ����ֵ,Ȼ����ͨ����ֵ��ֵ.

		m_ptr = sp.m_ptr;

		shared_count = sp.shared_count;

		return *this;

	}

};


struct Arwen {

	int age;

	Arwen(int gg) :age(gg) { };

};



void main_03() {

	shared_ptr<Arwen> myPtr(new Arwen(24));

	int num = myPtr->age;

	shared_ptr<Arwen> ptrOne(myPtr); //���ƹ���

	num = myPtr->age; //�����auto_ptr�ô������.��Ϊ��myPtr���Ƹ�ptrOne��,���Լ������൱��ʧЧ��

	num = ptrOne->age;

	shared_ptr<Arwen> ptrTwo = ptrOne;

	num = ptrOne->age;//�����auto_ptr�ô�Ҳ�����,��ʱptrOneҲʧЧ��

	num = ptrTwo->age;

}