#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <stdlib.h>
#include <windows.h>

struct Base
{
	Base() { std::cout << "  Base::Base()\n"; }
	// Note: non-virtual destructor is OK here
	~Base() { std::cout << "  Base::~Base()\n"; }
};

struct Derived : public Base
{
	Derived() { std::cout << "  Derived::Derived()\n"; }
	~Derived() { std::cout << "  Derived::~Derived()\n"; }
};


void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
	std::shared_ptr<Base> lp = p; // thread-safe, even though the
                                  // shared use_count is incremented
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << "local pointer in a thread:\n"
                  << "  lp.get() = " << lp.get()
                  << ", lp.use_count() = " << lp.use_count() << '\n';
    }
}
 
struct A
{
    int i;
};
 
 
void Free(void* data)
{
    std::cout << "free: " << (int*)data << std::endl;
    free(data);
}
 
struct D
{
    void operator()(void* data)
    {
        std::cout << "free: " << (int*)data << std::endl;
        free(data);
    }
};
 
// 使用shared_ptr来调用特殊的释放函数.
void TestCPointer()
{
    A* a = (A*)malloc(sizeof(A));
    a->i = 10;
    std::cout << (int*)a << std::endl;
    // 自定义释放函数.
	std::shared_ptr<A> ar(a, D());
    // 也可以这样
    //std::shared_ptr ar(a,free);
    std::cout << ar.get()->i << std::endl;
}
 
int main_06()
{
	std::shared_ptr<Derived> p = std::make_shared<Derived>();
	std::cout << "Created a shared Derived (as a pointer to Base)\n" << " p.get() = " << p.get() << ", p.use_count() = " << p.use_count() << '\n';
	std::thread t1(thr, p),t2(thr, p), t3(thr, p); 
	std::cout << "Shared ownership between 3 threads and released\n" << "ownership from main:\n" << " p.get() = " << p.get() << ", p.use_count() = " << p.use_count() << '\n'; 
	t1.detach(); t2.detach(); t3.detach(); 
	// t1.join(); t2.join(); t3.join();
	std::cout << "线程运行完毕! threads and released\n" << "ownership from main:\n" << " p.get() = " << p.get() << ", p.use_count() = " << p.use_count() << '\n';
	while (1) { if (p.use_count() == 1) { break; } Sleep(500); } 
	std::cout << "All threads completed, the last one deleted Derived\n"; 
	
	system("pause");
	//TestCPointer(); return 0; 
}