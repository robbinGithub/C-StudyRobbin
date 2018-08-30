#include <iostream>
#include <vector>
#include <memory>

using namespace std;

/*
 1�������ͷ��ڴ棬����������»�����ڴ�й¶��
 2����ʱ������ָ�������ڴ������¾��ͷ�����������������¾ͻ�������÷Ƿ��ڴ��ָ�롣
*/

void PRINT_FUN()
{
	cout <<"PRINT_FUN"<<endl;
}

class CConnnect
{
public:
	void Disconnect() { PRINT_FUN(); }
};

void Deleter(CConnnect* obj)
{
	obj->Disconnect(); // �������ͷŻ�Ͽ����ӵȹ���
	delete obj; // ɾ������ָ��
}

struct C { int* data; };

void test_01()
{

	std::shared_ptr<int> p1;
	std::shared_ptr<int> p2(nullptr);
	std::shared_ptr<int> p3(new int);
	std::shared_ptr<int> p4(new int, std::default_delete<int>());
	std::shared_ptr<int> p5(new int, [](int* p){delete p; }, std::allocator<int>()); // 2
	std::shared_ptr<int> p6(p5);
	std::shared_ptr<int> p7(std::move(p6));
	std::shared_ptr<int> p8(std::unique_ptr<int>(new int));
	std::shared_ptr<C> obj(new C);
	std::shared_ptr<int> p9(obj, obj->data);

	std::cout << "use_count:\n";
	std::cout << "p1: " << p1.use_count() << '\n';
	std::cout << "p2: " << p2.use_count() << '\n';
	std::cout << "p3: " << p3.use_count() << '\n';
	std::cout << "p4: " << p4.use_count() << '\n';
	std::cout << "p5: " << p5.use_count() << '\n';
	std::cout << "p6: " << p6.use_count() << '\n';
	std::cout << "p7: " << p7.use_count() << '\n';
	std::cout << "p8: " << p8.use_count() << '\n';
	std::cout << "p9: " << p9.use_count() << '\n';
}



int main_05()
{
	test_01();
	system("pause");
	return 0;
}