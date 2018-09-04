
//�� unique_lock ��ͨ�û����װ���������ӳ���������������ʱ�޳��ԡ��ݹ�����������Ȩת�ƺ�����������һͬʹ�á�
//unique_lock��lock_guardʹ�ø��������ܸ���ǿ��
//ʹ��unique_lock��Ҫ���������ʱ�䡢���ܳɱ���
// @see http://www.cnblogs.com/xudong-bupt/p/9194394.html

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock
#include <vector>

std::mutex mtx;           // mutex for critical section
std::once_flag flag;

void print_block(int n, char c) {
	//unique_lock�ж��鹹�캯��, ����std::defer_lock��������״̬
	std::unique_lock<std::mutex> my_lock(mtx, std::defer_lock);
	//���Լ���, ��������ɹ���ִ��
	//(�ʺ϶�ʱִ��һ��job�ĳ���, һ���߳�ִ�оͿ���, �����ø���ʱ�������)
	if (my_lock.try_lock()) {
		for (int i = 0; i < n; ++i)
			std::cout << c;
		std::cout << '\n';
	}
}

void run_one(int &n) {
	std::call_once(flag, [&n] {n = n + 1; }); //ִֻ��һ��, �ʺ��ӳټ���; ���߳�static�������
}

int main() {
	std::vector<std::thread> ver;
	int num = 0;
	for (auto i = 0; i < 10; ++i) {
		ver.emplace_back(print_block, 50, '*');
		ver.emplace_back(run_one, std::ref(num));
	}

	for (auto &t : ver) {
		t.join();
	}
	std::cout << num << std::endl;

	system("pause");

	return 0;
}