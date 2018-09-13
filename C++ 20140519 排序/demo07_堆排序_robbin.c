#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
 * 堆排序是利用堆这种数据结构而设计的一种排序算法，堆排序是一种选择排序，它的最坏，最好，平均时间复杂度均为O(nlogn)，它也是不稳定排序。首先简单了解下堆结构。
 　
   堆排序的基本思想是：将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。
   将其与末尾元素进行交换，此时末尾就为最大值。然后将剩余n-1个元素重新构造成一个堆，
   这样会得到n个元素的次小值。如此反复执行，便能得到一个有序序列了
 
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
* 调整大顶堆（仅是调整过程，建立在大顶堆已构建的基础上）
* @param arr
* @param i
* @param length
*/
 static void adjustHeap(int arr[], int i, int length) {
	int temp = arr[i];//先取出当前元素i
	for (int k = i * 2 + 1;k<length;k = k * 2 + 1) {//从i结点的左子结点开始，也就是2i+1处开始
		
		if (k + 1<length && arr[k]<arr[k + 1]) {//如果左子结点小于右子结点，k指向右子结点
			k++;
		}
		if (arr[k] >temp) {//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
			arr[i] = arr[k];
			i = k;
		}
		else {
			break;
		}
	}
	arr[i] = temp;//将temp值放到最终的位置
}

void HeapSort(int arr[], int len)
{
   // 堆排序时间复杂度一般认为就是O(nlogn)级

   // 1.构建初始堆,复杂度为O(n)
	for (int i = len / 2 - 1;i >= 0;i--) {
		//从第一个非叶子结点从下至上，从右至左调整结构
		adjustHeap(arr, i, len);
	}

    // 2.交换堆顶元素和末尾元素并重建堆,交换n-1次 根据完全二叉树的性质，[log2(n-1),log2(n-2)...1]逐步递减，近似为nlogn
	for (int j = len - 1;j > 0;j--) {
		swap(arr, 0, j);//将堆顶元素与末尾元素进行交换
		adjustHeap(arr, 0, j);//重新对堆进行调整
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