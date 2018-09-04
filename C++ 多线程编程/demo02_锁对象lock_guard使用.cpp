#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <algorithm>

std::mutex my_lock;

/*
 * std::lock_guard
 * 1+2+ .. + 100的多线程实现，每个num只能由一个线程处理。：
 * @see http://www.cnblogs.com/xudong-bupt/p/9194394.html
 */
void add(int &num, int &sum) {
	while (true) {
		std::lock_guard<std::mutex> lock(my_lock);
		if (num < 100) { //运行条件
			num += 1;
			sum += num;
		}
		else {  //退出条件
			break;
		}
	}
}

int main_01() {
	int sum = 0;
	int num = 0;
	std::vector<std::thread> ver;   //保存线程的vector
	for (int i = 0; i < 20; ++i) {
		std::thread t = std::thread(add, std::ref(num), std::ref(sum));
		ver.emplace_back(std::move(t)); //保存线程
	}

	std::for_each(ver.begin(), ver.end(), std::mem_fn(&std::thread::join)); //join
	std::cout << sum << std::endl;
	return 0;
}