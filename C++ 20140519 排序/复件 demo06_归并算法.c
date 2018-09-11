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

	while( (i <= mid) && (j <= high) ) //将小的放到目的地中
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

	while( i <= mid )  //若还剩几个尾部元素
	{
		des[k++] = src[i++];
	}

	while( j <= high ) //若还剩几个尾部元素
	{
		des[k++] = src[j++];
	}
}

//每次分为两路 当只剩下一个元素时，就不需要在划分
void MSort(int src[], int des[], int low, int high, int max)
{
	if( low == high ) //只有一个元素，不需要归并，结果赋给des[low]
	{
		des[low] = src[low]; 
	}
	else //如果多个元素，进行两路划分
	{
		int mid = (low + high) / 2;
		int* space = (int*)malloc(sizeof(int) * max);

		//递归进行两路，两路的划分 
		//当剩下一个元素的时，递归划分结束，然后开始merge归并操作
		if( space != NULL )
		{ 
			//左边归并排序，使得左子序列有序
			MSort(src, space, low, mid, max);  

			//右边归并排序，使得右子序列有序
			MSort(src, space, mid+1, high, max);

			//将两个有序子数组合并操作
			Merge(space, des, low, mid, high); //调用归并函数进行归并
		}

		free(space);
	}
}

/*
 * 归并排序（MERGE-SORT）是利用归并的思想实现的排序方法，该算法采用经典的分治（divide-and-conquer）策略
 *（分治法将问题分(divide)成一些小的问题然后递归求解，而治(conquer)的阶段则将分的阶段得到的各答案"修补"在一起，即分而治之)。
 */
void MergeSort(int array[], int len) // O(n*logn)
{
	MSort(array, array, 0, len-1, len);
}

// robbin版本
// @see https://www.cnblogs.com/chengxiao/p/6194356.html

void _merge(int arr[], int left, int mid, int right, int temp[])
{
	int i = left;    //左序列指针
	int j = mid + 1; //右序列指针
	int t = 0;       //临时数组指针

	// 4 5 7 8  ===  1 2 3 6
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[t++] = arr[i++];
		}
		else {
			temp[t++] = arr[j++];
		}
	}

	while (i <= mid) {//将左边剩余元素填充进temp中
		temp[t++] = arr[i++];
	}
	while (j <= right) {//将右序列剩余元素填充进temp中
		temp[t++] = arr[j++];
	}

	t = 0;

	//将temp中的元素全部拷贝到原数组中
	while (left <= right) {
		arr[left++] = temp[t++];
	}
}

void _sort(int arr[] , int left, int right, int temp[])
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		_sort(arr, left, mid, temp);    //左边归并排序，使得左子序列有序
		_sort(arr, mid+1, right, temp); //右边归并排序，使得右子序列有序
		_merge(arr, left, mid, right, temp); //将两个有序子数组合并操作
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

	// robbin版本测试
	int array[] = { 8, 4, 5, 7, 1, 3, 6, 2 };
	int temp[8] = {0};
	int len = sizeof(array) / sizeof(*array);
	printArray06(array, len);
	_sort(array, 0, len-1, temp);
	printArray06(array, len);

	system("pause");
	return 0;
}
