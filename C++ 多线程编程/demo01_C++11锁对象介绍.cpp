/*
Mutex 系列类(四种)

std::mutex，最基本的 Mutex 类。
std::recursive_mutex，递归 Mutex 类。
std::time_mutex，定时 Mutex 类。
std::recursive_timed_mutex，定时递归 Mutex 类。

Lock 类（三种）

std::lock_guard，与 Mutex RAII 相关，方便线程对互斥量上锁。
std::unique_lock，与 Mutex RAII 相关，方便线程对互斥量上锁，但提供了更好的上锁和解锁控制。
std::shared_lock,

@see https://blog.csdn.net/u010100466/article/details/78172600
*/