#include "iostream"
using namespace std;


class Goods 
{ 
public :
	Goods ( int  w) { weight = w ;  total_weight += w ; }
	~ Goods() { total_weight -= weight ; }
	int  Weight() { return  weight ; } ;	
	static  int  TotalWeight() { return  total_weight ; }  
	Goods *next ;
private :
	int  weight ;     //重量
	static  int  total_weight ; //总重量
} ;

int  Goods::total_weight = 0 ;

//买货物
void purchase(Goods * &f, Goods *& r, int w) // f为头结点，r为结尾结点
{
	Goods *p = new Goods(w);
	p->next = NULL;
	if (f == NULL)  f = r = p; //头结点为NULL
	else { r->next = p;    r = r->next; }
}
//卖货物
void sale( Goods * & f , Goods * & r ) //r是参数但是没有用
{ 
	if ( f == NULL ) { cout << "No any goods!\n" ;  return ; }
	Goods *q = f ;  f = f -> next ;  delete q ; //删除第一个元素
	cout << "saled.\n" ;
}

void main020()
{ 
	Goods * front = NULL , * rear = NULL ;
	int  w ;  int  choice ;  
	do 
	{ 
		cout << "Please choice:\n" ;
		cout << "Key in 1 is purchase,\nKey in 2 is sale,\nKey in 0 is over.\n" ;
		cin >> choice;          //(cin与scanf不同参数不是地址(可能内部会有转换)
		switch ( choice )		// 操作选择
		{ 
		case 1 :                                               // 键入1，购进1箱货物
			{  cout << "Input weight: " ;
			cin >> w ;
			purchase( front, rear, w ) ;          // 从表尾插入1个结点
			break ;
			}
		case 2 : 		            // 键入2，售出1箱货物
			{ sale( front, rear ) ;    break ; }       // 从表头删除1个结点
		case 0 :  break ; 		            // 键入0，结束
		}
		cout << "Now total weight is:" << Goods::TotalWeight() << endl ; 
	} while ( choice ) ;
} 



