#include "iostream"
using namespace std;

class name
{ 
public :
	name(char *pn) ;  
	//�������캯��
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
	//��д������
	void operator=(name &obj1)
	{
		cout <<" ִ��=����" << endl ;
		char *pn = obj1.getPn();
		pname = (char *)malloc(strlen(pn) +1);
		if (pname!=NULL) strcpy(pname,pn) ;
		//pname = new char[strlen(pn)+1] ;
		//if (pname!=0) strcpy(pname,pn) ;
		pname[0] = 'm';
		size = strlen(pn) ;
	}
} ;
//���ⶨ�幹�캯��
name::name(char *pn)          
{ 
	cout <<" Constructing " << pn << endl ;
	pname = (char *)malloc(strlen(pn) +1); //malloc�ڴ�ռ�
	if (pname!=0) strcpy(pname,pn) ;       //����strcpy���ַ�����������������ڴ�ռ�
	//pname = new char[strlen(pn)+1] ;
	//if (pname!=0) strcpy(pname,pn) ;
	size = strlen(pn) ;
} 
//���ⶨ����������
name :: ~ name()
{ 
	cout << " Destructing " << pname << endl ; 
	pname[0] = '\0' ;
	//delete  []pname ;
	free(pname);  //�����������ͷ�malloc�ڴ�
	size = 0 ;
}


void playmain()
{
	name obj1("name1");
	//����㲻дcopy���캯������ôC++��������������ṩһ��Ĭ�ϵ�copy���캯�� ��ǳcpy��
	name obj2 = obj1;

	//����㲻д=��������ôC++��������������ṩһ��=�������� ��ǳcpy��
	obj2 = obj1;
	cout<<obj2.getPn()<<endl;
}

// void main11001()
void main11001()
{
	playmain();

	system("pause");
}