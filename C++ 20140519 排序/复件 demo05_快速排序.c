void printArray05(int array[], int len)
{
	int i = 0;

	for(i=0; i<len; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}

void swap5(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/*
 * ��������
 * {12, 5, 433, 253, 216, 7};
 * 
 */
int partition(int array[], int low, int high)
{
	int pv = array[low];

	while( low < high )
	{
		// ��j��ʼ��ǰ���������ɺ�ʼ��ǰ����(j--)���ҵ���һ��С��key��ֵA[j]����A[j]��A[i]������
		while( (low < high) && (array[high] >= pv) )
		{
			high--; //�Ȼ�׼�󣬱��������ұߣ�����highǰ�ƶ�
		}
		swap5(array, low, high);

		// ��i��ʼ�������������ǰ��ʼ�������(i++)���ҵ���һ������key��A[i]����A[i]��A[j]������
		while( (low < high) && (array[low] <= pv) )
		{
			low++;
		}
		swap5(array, low, high);
	}

	return low;
}

/*
 * �ݹ����QSort
 */
void QSort(int array[], int low, int high)
{
	if( low < high )
	{   
		// ����->��->�� 
		int pivot = partition(array, low, high);

		QSort(array, low, pivot-1);
		QSort(array, pivot+1, high);
	}
}

void QuickSort(int array[], int len) // O(n*logn)
{
	QSort(array, 0, len-1);
}

int main_05()
{
	int array[] = {12, 5, 433, 253, 216, 7};
	int len = sizeof(array) / sizeof(*array); 
	printArray05(array, len);
	QuickSort(array, len);
	printArray05(array, len);
	system("pause");
	return 0;
}
