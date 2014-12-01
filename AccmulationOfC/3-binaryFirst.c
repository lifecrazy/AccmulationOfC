/*
ʱ�䣺2014-12-01
���ߣ�
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1.���ֲ���
int binarySearch(int *Arr,int num, int key, int*result)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("���ֲ���ʧ�ܣ�����");
		return ret;
	}
	int low = 0;
	int high = num - 1;
	int mid = -1;
	while (low != high)
	{
		mid = (low + high) / 2;
		if (Arr[mid] > key)
		{
			high = mid - 1;
		}
		else if (Arr[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			*result = mid;
			return ret;
		}
	}
	*result = -1;
	return ret;
}

void main()
{
	int num = 10;
	int a[] = { 2, 5, 6, 8, 16, 34, 41, 89, 131, 234 };
	int result;
	binarySearch(a,num, 34, &result);
	printf("���ҵĽ��Ϊ:%d", result);
	system("pause");
}