

#include "iostream"
#include "Array.h"
using namespace std;


Array::Array(int length)
{
    if( length < 0 )
    {
        length = 0;
    }
    
    mLength = length;
    mSpace = new int[mLength];
}

Array::Array(const Array& obj)
{
    mLength = obj.mLength;
    
    mSpace = new int[mLength];
    
    for(int i=0; i<mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
}

int Array::length()
{
    return mLength;
}

void Array::setData(int index, int value)
{
    mSpace[index] = value;
}

int Array::getData(int index)
{
    return mSpace[index];
}

Array::~Array()
{
    mLength = -1;
    delete[] mSpace;
}

//����������
 //printf("array %d: %d\n", i, a1[i]) ;
//a1[i] = 1;
int&  Array::operator[] (int i)
{
	 return mSpace[i];
}


//Array a3(100);
//a3 = a2; //ִ��=����
// 	1)���a3�Ѿ������ڴ���Ҫ�ͷ�
//	2������a2�����ڴ�ռ� ��a2��ֵcopy��a3��
Array&  Array::operator=(Array &a2)
{
	if (this->mSpace != NULL)
	{
		delete[] mSpace;
		mLength = 0;
	}
	this->mLength = a2.mLength;
	this->mSpace = new int[this->mLength];

	for (int i=0; i<this->mLength; i++)
	{
		mSpace[i] = a2[i];
	}
	return *this;
}


//a2.operator==(a1);
//if (a2==a1)
bool Array::operator==(Array &a1)
{
	//a1��a2�ĳ����ǲ������
	if (this->mLength != a1.mLength)
	{
		return false;
	}
	//a1 a2��ÿһ������Ԫ���ǲ������
	for (int i=0; i<this->mLength; i++)
	{
		if (this->mSpace[i] != a1[i])
		{
			return false;
		}
	}
	return true;
}

//if (a2 != a1)
bool  Array::operator!=(Array &a1)
{
	return !(*this == a1 );
}


