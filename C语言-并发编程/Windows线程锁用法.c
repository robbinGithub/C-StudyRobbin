
/*
InitializeCriticalSection(&cs);//初始化临界区
EnterCriticalSection(&cs);//进入临界区
//操作数据
MyMoney*=10;//所有访问MyMoney变量的程序都需要这样写Enter.. Leave...
LeaveCriticalSection(&cs);//离开临界区
DeleteCriticalSection(&cs);//删除临界区
 */


/*
 线程锁的概念函数EnterCriticalSection和LeaveCriticalSection的用法
*/
