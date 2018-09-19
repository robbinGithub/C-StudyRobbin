#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
 * �����������ö��������ݽṹ����Ƶ�һ�������㷨����������һ��ѡ���������������ã�ƽ��ʱ�临�ӶȾ�ΪO(nlogn)����Ҳ�ǲ��ȶ��������ȼ��˽��¶ѽṹ��
 ��
   ������Ļ���˼���ǣ������������й����һ���󶥶ѣ���ʱ���������е����ֵ���ǶѶ��ĸ��ڵ㡣
   ������ĩβԪ�ؽ��н�������ʱĩβ��Ϊ���ֵ��Ȼ��ʣ��n-1��Ԫ�����¹����һ���ѣ�
   ������õ�n��Ԫ�صĴ�Сֵ����˷���ִ�У����ܵõ�һ������������
 
 * @see https://www.cnblogs.com/chengxiao/p/6129630.html
 *      https://blog.csdn.net/guoweimelon/article/details/50904346
 *      https://blog.csdn.net/guoweimelon/article/details/50904231
 */

void static printArray(int array[], int len)
{
	int i = 0;
	for (i = 0; i<len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void static swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
* �����󶥶ѣ����ǵ������̣������ڴ󶥶��ѹ����Ļ����ϣ�
* @param arr
* @param i
* @param length
*/
 static void adjustHeap(int arr[], int i, int length) {
	int temp = arr[i];//��ȡ����ǰԪ��i
	for (int k = i * 2 + 1;k<length;k = k * 2 + 1) {//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
		
		if (k + 1<length && arr[k]<arr[k + 1]) {//������ӽ��С�����ӽ�㣬kָ�����ӽ��
			k++;
		}
		if (arr[k] >temp) {//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
			arr[i] = arr[k];
			i = k;
		}
		else {
			break;
		}
	}
	arr[i] = temp;//��tempֵ�ŵ����յ�λ��
}

void HeapSort(int arr[], int len)
{
   // ������ʱ�临�Ӷ�һ����Ϊ����O(nlogn)��

   // 1.������ʼ��,���Ӷ�ΪO(n)
	for (int i = len / 2 - 1;i >= 0;i--) {
		//�ӵ�һ����Ҷ�ӽ��������ϣ�������������ṹ
		adjustHeap(arr, i, len);
	}

    // 2.�����Ѷ�Ԫ�غ�ĩβԪ�ز��ؽ���,����n-1�� ������ȫ�����������ʣ�[log2(n-1),log2(n-2)...1]�𲽵ݼ�������Ϊnlogn
	for (int j = len - 1;j > 0;j--) {
		swap(arr, 0, j);//���Ѷ�Ԫ����ĩβԪ�ؽ��н���
		adjustHeap(arr, 0, j);//���¶Զѽ��е���
	}

}

int main()
{

	// int array[] = {4, 6, 8, 5, 9};
	int array[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int len = sizeof(array) / sizeof(*array);

	printArray(array, len);
	HeapSort(array, len);
	printArray(array, len);
	system("pause");
	return 0;
}