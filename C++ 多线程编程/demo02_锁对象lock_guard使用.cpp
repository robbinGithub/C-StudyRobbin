#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <algorithm>

std::mutex my_lock;

/*
 * std::lock_guard
 * 1+2+ .. + 100�Ķ��߳�ʵ�֣�ÿ��numֻ����һ���̴߳�����
 * @see http://www.cnblogs.com/xudong-bupt/p/9194394.html
 */
void add(int &num, int &sum) {
	while (true) {
		std::lock_guard<std::mutex> lock(my_lock);
		if (num < 100) { //��������
			num += 1;
			sum += num;
		}
		else {  //�˳�����
			break;
		}
	}
}

int main_01() {
	int sum = 0;
	int num = 0;
	std::vector<std::thread> ver;   //�����̵߳�vector
	for (int i = 0; i < 20; ++i) {
		std::thread t = std::thread(add, std::ref(num), std::ref(sum));
		ver.emplace_back(std::move(t)); //�����߳�
	}

	std::for_each(ver.begin(), ver.end(), std::mem_fn(&std::thread::join)); //join
	std::cout << sum << std::endl;
	return 0;
}