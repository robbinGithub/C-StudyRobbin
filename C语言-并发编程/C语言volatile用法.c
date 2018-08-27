#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
   һ��volatile ����
    ��ʾһ������Ҳ��ᱻ��̨����ı䣬�ؼ��� volatile ���� const ���Զ����ġ���ָʾһ������Ҳ��ᱻĳ�ַ�ʽ�޸ģ�

	����Ϊʲôʹ�� volatile(volatile������)
 
	1.��Ϊָ��ؼ���,ȷ������ָ��ᱻ���������Ż�������ָ��������
	2.ÿ�����´������ڵ��ڴ��ȡ���ݣ�
	3.д���ݱ�֤�����̵߳Ŀɼ��ԡ�


	@see http://blog.csdn.net/qq_29350001/article/details/54024070
  */

static int i = 0; //i Ϊ���Զ�����  

int main_023()
{  
	
	volatile int i = 10;
	int a = i; //�Ż�
	int b = i;

	printf("i = %d\n", b);
	system("pause");

	return 0;
}


/*
   2��һ���жϷ����ӳ����л���ʵ��ķ��Զ�������Non-automatic variables)
   ����ı�����ϣ�� ISR_2 �жϲ���ʱ����main�����е��� dosomething ������
   ���ǣ����ڱ������ж��� main ��������û���޸Ĺ� i����˿���ִֻ��һ�ζԴ�i��ĳ�Ĵ����Ķ�������
   Ȼ��ÿ��if�ж϶�ֻʹ������Ĵ�������ġ�i������������ dosomething ��ԶҲ���ᱻ���á�
   ������������� volatile ���Σ����������֤�Դ˱����Ķ�д���������ᱻ�Ż����϶�ִ�У���
 */
void dosomething2();

int main_02(void)
{

	while (1){
		if (i) dosomething2();
	}
}

void dosomething2()
{
	printf("dosomething");
}

/* Interrupt service routine. */
void ISR_2(void)
{
	i = 1;
}


/*

3�����߳�Ӧ���б�����������ı���

	�������̶߳�Ҫ�õ�ĳһ�������Ҹñ�����ֵ�ᱻ�ı�ʱ��Ӧ���� volatile ������
	�ùؼ��ֵ������Ƿ�ֹ�Ż��������ѱ������ڴ�װ��CPU�Ĵ����С�
	���������װ��Ĵ�������ô�����߳��п���һ��ʹ���ڴ��еı�����һ��ʹ�üĴ����еı�����
	�����ɳ���Ĵ���ִ�С�volatile����˼���ñ�����ÿ�β����ñ���ʱһ��Ҫ���ڴ�������ȡ����
	������ʹ���Ѿ����ڼĴ����е�ֵ������
*/

/*
 volatile  BOOL  bStop  =  FALSE;  //bStop  Ϊ����ȫ�ֱ���  
(1) ��һ���߳��У�    
  while(  !bStop  )  {  ...  }    
  bStop  =  FALSE;    
  return;      
  
(2) ������һ���߳��У�Ҫ��ֹ������߳�ѭ����    
  bStop  =  TRUE;    
  while(  bStop  )

*/