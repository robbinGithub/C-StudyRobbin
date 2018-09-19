#include <stdio.h>
#include <malloc.h>

void printArray06(int array[], int len)
{
	int i = 0;
	for(i=0; i<len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap6(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void Merge(int src[], int des[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while( (i <= mid) && (j <= high) ) //��С�ķŵ�Ŀ�ĵ���
	{
		if( src[i] < src[j] )
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while( i <= mid )  //����ʣ����β��Ԫ��
	{
		des[k++] = src[i++];
	}

	while( j <= high ) //����ʣ����β��Ԫ��
	{
		des[k++] = src[j++];
	}
}

//ÿ�η�Ϊ��· ��ֻʣ��һ��Ԫ��ʱ���Ͳ���Ҫ�ڻ���
void MSort(int src[], int des[], int low, int high, int max)
{
	if( low == high ) //ֻ��һ��Ԫ�أ�����Ҫ�鲢���������des[low]
	{
		des[low] = src[low]; 
	}
	else //������Ԫ�أ�������·����
	{
		int mid = (low + high) / 2;
		int* space = (int*)malloc(sizeof(int) * max);

		//�ݹ������·����·�Ļ��� 
		//��ʣ��һ��Ԫ�ص�ʱ���ݹ黮�ֽ�����Ȼ��ʼmerge�鲢����
		if( space != NULL )
		{ 
			//��߹鲢����ʹ��������������
			MSort(src, space, low, mid, max);  

			//�ұ߹鲢����ʹ��������������
			MSort(src, space, mid+1, high, max);

			//����������������ϲ�����
			Merge(space, des, low, mid, high); //���ù鲢�������й鲢
		}

		free(space);
	}
}

/*
 * �鲢����MERGE-SORT�������ù鲢��˼��ʵ�ֵ����򷽷������㷨���þ���ķ��Σ�divide-and-conquer������
 *�����η��������(divide)��һЩС������Ȼ��ݹ���⣬����(conquer)�Ľ׶��򽫷ֵĽ׶εõ��ĸ���"�޲�"��һ�𣬼��ֶ���֮)��
 */
void MergeSort(int array[], int len) // O(n*logn)
{
	MSort(array, array, 0, len-1, len);
}

// robbin�汾
// @see https://www.cnblogs.com/chengxiao/p/6194356.html

void _merge(int arr[], int left, int mid, int right, int temp[])
{
	int i = left;    //������ָ��
	int j = mid + 1; //������ָ��
	int t = 0;       //��ʱ����ָ��

	// 4 5 7 8  ===  1 2 3 6
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[t++] = arr[i++];
		}
		else {
			temp[t++] = arr[j++];
		}
	}

	while (i <= mid) {//�����ʣ��Ԫ������temp��
		temp[t++] = arr[i++];
	}
	while (j <= right) {//��������ʣ��Ԫ������temp��
		temp[t++] = arr[j++];
	}

	t = 0;

	//��temp�е�Ԫ��ȫ��������ԭ������
	while (left <= right) {
		arr[left++] = temp[t++];
	}
}

void _sort(int arr[] , int left, int right, int temp[])
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		_sort(arr, left, mid, temp);    //��߹鲢����ʹ��������������
		_sort(arr, mid+1, right, temp); //�ұ߹鲢����ʹ��������������
		_merge(arr, left, mid, right, temp); //����������������ϲ�����
	}
}



int main_06()
{
	
	//int array[] = {21, 25, 49, 25, 16, 8};
	//int array[] = {21, 25};

	/*
	int array[] = { 8, 4, 5, 7, 1, 3, 6, 2 };
	int len = sizeof(array) / sizeof(*array); 
	printArray06(array, len);
	MergeSort(array, len);
	printArray06(array, len);
	*/

	// robbin�汾����
	int array[] = { 8, 4, 5, 7, 1, 3, 6, 2 };
	int temp[8] = {0};
	int len = sizeof(array) / sizeof(*array);
	printArray06(array, len);
	_sort(array, 0, len-1, temp);
	printArray06(array, len);

	system("pause");
	return 0;
}
