#include "iostream"
using namespace std;

class name
{ 
public :
	name(char *pn) ;  
	//拷贝构造函数
	name( name &obj)
	{
		cout <<" copy Constructing " << endl ;
		char *pn = obj.getPn();
		pname = (char *)malloc(strlen(pn) +1);
		if (pname!=NULL) strcpy(pname,pn) ;
		//pname = new char[strlen(pn)+1] ;
		//if (pname!=0) strcpy(pname,pn) ;
		size = strlen(pn) ;
	}
	~ name() ;
protected : 
	char *pname ;       int size ;
public:
	char * getPn()
	{
		return pname;
	}	
	//重写操作符
	void operator=(name &obj1)
	{
		cout <<" 执行=操作" << endl ;
		char *pn = obj1.getPn();
		pname = (char *)malloc(strlen(pn) +1);
		if (pname!=NULL) strcpy(pname,pn) ;
		//pname = new char[strlen(pn)+1] ;
		//if (pname!=0) strcpy(pname,pn) ;
		pname[0] = 'm';
		size = strlen(pn) ;
	}
} ;
//类外定义构造函数
name::name(char *pn)          
{ 
	cout <<" Constructing " << pn << endl ;
	pname = (char *)malloc(strlen(pn) +1); //malloc内存空间
	if (pname!=0) strcpy(pname,pn) ;       //调用strcpy将字符串复制至刚申请的内存空间
	//pname = new char[strlen(pn)+1] ;
	//if (pname!=0) strcpy(pname,pn) ;
	size = strlen(pn) ;
} 
//类外定义析构函数
name :: ~ name()
{ 
	cout << " Destructing " << pname << endl ; 
	pname[0] = '\0' ;
	//delete  []pname ;
	free(pname);  //对象析构后释放malloc内存
	size = 0 ;
}


void playmain()
{
	name obj1("name1");
	//如果你不写copy构造函数，那么C++编译器会给我们提供一个默认的copy构造函数 （浅cpy）
	name obj2 = obj1;

	//如果你不写=操作，那么C++编译器会给我们提供一个=操作函数 （浅cpy）
	obj2 = obj1;
	cout<<obj2.getPn()<<endl;
}

// void main11001()
void main11001()
{
	playmain();

	system("pause");
}