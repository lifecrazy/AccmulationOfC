/*
时间：2014-12-01
作者：
*/
#include <stdio.h>
#include <stdlib.h>

//1.二分查找
int binarySearch(int *Arr, int num, int key, int*result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("二分查找失败！！！");
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
//2.旋转数组
//方法一：
//思路：1.先确定Arr[mid]在旋转数组的前一部分还是后一部分
//      2.再确定key在Arr[mid]的左边还是右边
int rotatedArraySearch(int *Arr, int num, int key, int*result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("旋转数组查找失败！！！");
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
//方法二：
//思路：1.先确定key在Arr[mid]的左边还是右边
//      2.再确定Arr[mid]在旋转数组的前一部分还是后一部分
//思路的关键在于如何将数组分段如何查找保证不遗漏不重复
int rotatedArraySearchSec(int *Arr, int num, int key, int*result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("旋转数组查找失败！！！");
		return ret;
	}
	int low = 0;
	int high = num - 1;
	int mid = -1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < Arr[mid])//key 在Arr[mid]的左侧
		{
			if (Arr[mid] < Arr[high])//A[mid]在旋转数组的后半部分
			{
				high = mid - 1;
			}
			else//A[mid]在旋转数组的前半部分
			{
				if (key < Arr[low])//如果key比 Arr[low]还小说明在旋转数组的后半部分
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
//4.旋转数组获取最小值
int rotatedArrayMin(int *Arr, int num, int*result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("旋转数组查找失败！！！");
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
	printf("查找的结果为:%d\n", result);
	rotatedArraySearch(a, num, 234, &result);
	printf("查找的结果为:%d\n", result);
	rotatedArraySearchSec(b, num, 234, &result);
	printf("查找的结果为:%d\n", result);
	rotatedArrayMin(b, num, &result);
	printf("查找的结果为:%d\n", result);
	system("pause");
}