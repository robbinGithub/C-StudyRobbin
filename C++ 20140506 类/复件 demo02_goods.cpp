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
	int  weight ;     //����
	static  int  total_weight ; //������
} ;

int  Goods::total_weight = 0 ;

//�����
void purchase(Goods * &f, Goods *& r, int w) // fΪͷ��㣬rΪ��β���
{
	Goods *p = new Goods(w);
	p->next = NULL;
	if (f == NULL)  f = r = p; //ͷ���ΪNULL
	else { r->next = p;    r = r->next; }
}
//������
void sale( Goods * & f , Goods * & r ) //r�ǲ�������û����
{ 
	if ( f == NULL ) { cout << "No any goods!\n" ;  return ; }
	Goods *q = f ;  f = f -> next ;  delete q ; //ɾ����һ��Ԫ��
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
		cin >> choice;          //(cin��scanf��ͬ�������ǵ�ַ(�����ڲ�����ת��)
		switch ( choice )		// ����ѡ��
		{ 
		case 1 :                                               // ����1������1�����
			{  cout << "Input weight: " ;
			cin >> w ;
			purchase( front, rear, w ) ;          // �ӱ�β����1�����
			break ;
			}
		case 2 : 		            // ����2���۳�1�����
			{ sale( front, rear ) ;    break ; }       // �ӱ�ͷɾ��1�����
		case 0 :  break ; 		            // ����0������
		}
		cout << "Now total weight is:" << Goods::TotalWeight() << endl ; 
	} while ( choice ) ;
} 



