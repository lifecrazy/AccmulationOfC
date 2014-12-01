/*
ʱ�䣺2014-12-01
���ߣ�
*/
#include <stdio.h>
#include <stdlib.h>

//1.���ֲ���
int binarySearch(int *Arr, int num, int key, int*result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("���ֲ���ʧ�ܣ�����");
		return ret;
	}
	int low = 0;
	int high = num - 1;
	int mid = -1;
	while (low <= high)
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
//2.��ת����
//����һ��
//˼·��1.��ȷ��Arr[mid]����ת�����ǰһ���ֻ��Ǻ�һ����
//      2.��ȷ��key��Arr[mid]����߻����ұ�
int rotatedArraySearch(int *Arr, int num, int key, int*result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("��ת�������ʧ�ܣ�����");
		return ret;
	}
	int low = 0;
	int high = num - 1;
	int mid = -1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (Arr[mid] == key)
		{
			*result = mid;
			return ret;
		}
		if (Arr[mid] > Arr[high])
		{
			if (key >= Arr[low] && key < Arr[mid])
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		else
		{
			if (key > Arr[mid] && key <= Arr[high])
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
	}
	*result = -1;
	return ret;
}
//��������
//˼·��1.��ȷ��key��Arr[mid]����߻����ұ�
//      2.��ȷ��Arr[mid]����ת�����ǰһ���ֻ��Ǻ�һ����
//˼·�Ĺؼ�������ν�����ֶ���β��ұ�֤����©���ظ�
int rotatedArraySearchSec(int *Arr, int num, int key, int*result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("��ת�������ʧ�ܣ�����");
		return ret;
	}
	int low = 0;
	int high = num - 1;
	int mid = -1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < Arr[mid])//key ��Arr[mid]�����
		{
			if (Arr[mid] < Arr[high])//A[mid]����ת����ĺ�벿��
			{
				high = mid - 1;
			}
			else//A[mid]����ת�����ǰ�벿��
			{
				if (key < Arr[low])//���key�� Arr[low]��С˵������ת����ĺ�벿��
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
		}
		else if (Arr[mid] < key)
		{
			if (Arr[low] < Arr[mid])
			{
				low = mid + 1;
			}
			else
			{
				if (key > Arr[high])
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
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
//4.��ת�����ȡ��Сֵ
int rotatedArrayMin(int *Arr, int num, int*result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("��ת�������ʧ�ܣ�����");
		return ret;
	}
	int low = 0;
	int high = num - 1;
	int mid = -1;
	if (Arr[low] < Arr[high])
	{
		*result = Arr[low];
		return ret;
	}
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (Arr[low] < Arr[mid])
		{
			low = mid;
		}
		else if (Arr[low]>Arr[mid])
		{
			high = mid;
		}	
		else if (Arr[low] == Arr[mid])
		{
			*result = Arr[low + 1];
			return ret;
		}	
	}
	return ret;
}

void mainforbinaryFirst()
{
	int num = 10;
	int a[] = { 2, 5, 6, 8, 16, 34, 41, 89, 131, 234 };
	int b[] = { 131, 234, 2, 5, 6, 8, 16, 34, 41, 89, };
	int result;
	binarySearch(a, num, 234, &result);
	printf("���ҵĽ��Ϊ:%d\n", result);
	rotatedArraySearch(a, num, 234, &result);
	printf("���ҵĽ��Ϊ:%d\n", result);
	rotatedArraySearchSec(b, num, 234, &result);
	printf("���ҵĽ��Ϊ:%d\n", result);
	rotatedArrayMin(b, num, &result);
	printf("���ҵĽ��Ϊ:%d\n", result);
	system("pause");
}