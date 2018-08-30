//default deleter for unique_ptr
template<typename T>
// 结构体也可使用模板
struct DefaultDeleter
{  
	// 运算符重载():释放内存空间
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
	// 内部使用的拷贝构造函数
	unique_ptr(const unique_ptr &);
	// 内部使用的赋值操作符=重载
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
		1.定义const对象

		const 类名 对象名；const unique_ptr obj

	　  类名 const 对象名；unique_ptr const obj

		1）定义类对象时可以将其指定为const对象。定义后const对象不能再被修改；

		2）const对象不能调用非const类型的成员函数。

		在非const成员函数内部，有可能会对对象的数据成员进行修改，比如setHour()修改了对象的Hour值。而const类型的成员函数是不会修改对象的数据成员的。

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
	//  return *this返回当前对象
	//  return this返回当前对象的地址（指向当前对象的指针）

	// &(T) 当前保存内容,再取地址 ? 为什么不直接返回 m_pT
	return &*(*this);
}