/*
Mutex ϵ����(����)

std::mutex��������� Mutex �ࡣ
std::recursive_mutex���ݹ� Mutex �ࡣ
std::time_mutex����ʱ Mutex �ࡣ
std::recursive_timed_mutex����ʱ�ݹ� Mutex �ࡣ

Lock �ࣨ���֣�

std::lock_guard���� Mutex RAII ��أ������̶߳Ի�����������
std::unique_lock���� Mutex RAII ��أ������̶߳Ի��������������ṩ�˸��õ������ͽ������ơ�
std::shared_lock,

@see https://blog.csdn.net/u010100466/article/details/78172600
*/