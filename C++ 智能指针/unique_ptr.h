//default deleter for unique_ptr
template<typename T>
// �ṹ��Ҳ��ʹ��ģ��
struct DefaultDeleter
{  
	// ���������():�ͷ��ڴ�ռ�
	void operator()(T *p)
	{
		if (p)
		{
			delete p;
			p = NULL;
		}
	}
};

template<typename T, typename Deleter = DefaultDeleter<T>>
class unique_ptr
{
public:
	//construct 
	unique_ptr(T *pT = NULL);
	//destroy
	~unique_ptr();

	//not allow copyable
private:
	// �ڲ�ʹ�õĿ������캯��
	unique_ptr(const unique_ptr &);
	// �ڲ�ʹ�õĸ�ֵ������=����
	unique_ptr&operator=(const unique_ptr &);

public:
	//reset 
	void reset(T *p);
	//release the own of the pointer
	T *release();
	//get the pointer
	T *get();

public:

	
	/*
		1.����const����

		const ���� ��������const unique_ptr obj

	��  ���� const ��������unique_ptr const obj

		1�����������ʱ���Խ���ָ��Ϊconst���󡣶����const�������ٱ��޸ģ�

		2��const�����ܵ��÷�const���͵ĳ�Ա������

		�ڷ�const��Ա�����ڲ����п��ܻ�Զ�������ݳ�Ա�����޸ģ�����setHour()�޸��˶����Hourֵ����const���͵ĳ�Ա�����ǲ����޸Ķ�������ݳ�Ա�ġ�

	    @see https://blog.csdn.net/lidiya007/article/details/53396815
	 */
	//convert unique_ptr to bool
	operator bool() const;
	//overload for operator *
	T &operator*();
	//overload for operator ->
	T *operator->();

private:
	//pointer
	T *m_pT;
	//deleter
	Deleter m_deleter;
	//call deleter
	void del();
};

//construct 
template<typename T, typename Deleter>
unique_ptr<T, Deleter>::unique_ptr(T *pT) :m_pT(pT)
{

}

//destroy
template<typename T, typename Deleter>
unique_ptr<T, Deleter>::~unique_ptr()
{
	del();
}

//call deleter
template<typename T, typename Deleter>
void unique_ptr<T, Deleter>::del()
{
	if (*this)
	{
		m_deleter(m_pT);
		m_pT = NULL;
	}
}

//get the pointer
template<typename T, typename Deleter>
T *unique_ptr<T, Deleter>::get()
{
	return m_pT;
}

//reset 
template<typename T, typename Deleter>
void unique_ptr<T, Deleter>::reset(T *p)
{
	del();
	m_pT = p;
}

//release the own of the pointer
template<typename T, typename Deleter>
T *unique_ptr<T, Deleter>::release()
{
	T *p = m_pT;
	m_pT = NULL;
	return p;
}

//convert unique_ptr to bool
template<typename T, typename Deleter>
unique_ptr<T, Deleter>::operator bool()const
{
	return NULL != m_pT;
}

//overload for operator *
template<typename T, typename Deleter>
T &unique_ptr<T, Deleter>::operator*()
{
	// assert(*this);
	return *m_pT;
}

//overload for operator ->
template<typename T, typename Deleter>
T *unique_ptr<T, Deleter>::operator->()
{  
	//  return *this���ص�ǰ����
	//  return this���ص�ǰ����ĵ�ַ��ָ��ǰ�����ָ�룩

	// &(T) ��ǰ��������,��ȡ��ַ ? Ϊʲô��ֱ�ӷ��� m_pT
	return &*(*this);
}