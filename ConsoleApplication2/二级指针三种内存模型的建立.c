#include <stdlib.h>
#include <stdio.h>


int main_066()
{

	int i = 0;

	// ָ������
	char *p1[] = { "123", "456", "789" };

	// ��ά����
	char p2[3][4] = { "123", "456", "789" };

	// �ֹ���ά�ڴ�
	char **p3 = (char **)malloc(3 * sizeof(char *));
	for (i = 0; i < 3; i++)
	{
		p3[i] = (char *)malloc(10 * sizeof(char));
		sprintf(p3[i], "%d%d%d", i, i, i);
	}

	system("pause");
}

int main_072()
{
	/*
	��ָ�����顿
	 p1 = 0x0020fbe8 {0x003e7884 "123", 0x003e789c "456", 0x003e78c0 "789"}
	 p1:ָ�������׵�ַ
	 p1�ĵ�ַ��0x0020FBE8
	 p1��ֵ:0x003e7884 (�����׸�Ԫ�صĵ�ַ) ָ�볣��
	 &p1:0x003e7884 ָ����������ָ��(ָ������ָ��)

	 0x0020FBE8  84 78 3e 00

	 0x003e7884
	 0x003e789c
	 0x003e78c0

	*/
	char * p1[] = { "123", "456", "789" }; // ���� 3*4 �ֽ��ڴ�
	printf("p1 value:%p \n", p1);
	printf("&p1 value:%p \n", &p1);

	/*
	������ָ�롿
	*/
	//  char(*p2)[5] = { "123", "456", "789" }; //Error ָ��һ�������ָ��(4���ֽ�)��ÿ����5 * sizeof(char) = 5���ֽ�

	system("pause");
}
