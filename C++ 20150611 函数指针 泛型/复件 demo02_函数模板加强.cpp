
#include "iostream"
using namespace std;

template<typename T>
void sortArray(T *a, int num)
{
	int i =0, j = 0;
	T tmp;

	for (i=0; i<num; i++)
	{
		for (j=i; j<num; j++)
		{
			if (a[i] < a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

template<class T>
void printfArray(T *a, int num)
{
	cout<<endl;
	for (int i=0; i<num; i++)
	{
		cout<<a[i]<<" ";
	}
}
void main_02()
{
	int a[10] = {1, 3, 4, 5,2, 3,44, 6,3};
	int num = sizeof(a)/sizeof(*a);
	sortArray<int>(a, num);
	printfArray<int>(a, num);

	char buf[] = "163addeadfdsafdsaf";
	int len = strlen(buf);

	sortArray<char>(buf, len);
	printfArray<char>(buf, len);



	system("pause");
}