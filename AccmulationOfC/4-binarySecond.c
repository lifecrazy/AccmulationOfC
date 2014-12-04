/*
时间：2014-12-01
作者：
*/
#include <stdio.h>
#include <stdlib.h>
//旋转数组有重复的元素 使用二分查找
//如果要查找的元素存在则返回true(1)否则返回false (0)
//思路：比较的关键就是要确定mid是在数组的前半部分还是后半部分
//如果没有重复元素Arr[low]一定比Arr[high]大让Arr[mid]和其中一个作比较就可以判断Arr[mid]在前半部分还是后半部分，但是现在有重复元素就不能确定Arr[low]一定比Arr[high]大，就分为两种情况第一种情况就是当Arr[low]大于Arr[high]的时候按照没有重复元素的处理，第二种情况就是Arr[low]等于Arr[high]的时候，同时Arr[mid]也与其相等的时候该如何处理：由于前半部分是递增的，让low 自增直到Arr[low]和Arr[high]不相等就可以再次可以按照不相等的时候处理
int rotatedArraySearchKey(int *Arr, int num, int key, int *result)
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
			*result = 1;
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
		else if (Arr[mid] < Arr[high])
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
		else
		{
			low++;//去除重复元素
		}
	}
	*result = 0;
	return ret;
}
//给定两个已经排序好的数组，找到两者所有元素中的中位数
//思路1：一般的思路是将两个数组合并为一个数组然后找出中间的那个数但这样的时间复杂度为O(m+n)
//思路2：可以定义两个指针分别指向两个数组的第一元素然后再定义一个计数器，分别比较两个指针指向的数据元素直到计数器的大小为两个数组的个数和的一半为止
//思路3：就是二分查找，假设两个数组的元素的个数的和胃totalNum，且两个数组的元素的个数都大于totalNum/2
//那么我就可以让Arr1[totalNum/2]和Arr2[totalNum/2]比较，如果Arr1[totalNum/2]<Arr2[totalNum/2]说明Arr1[totalNum/2]小于是两个数组中所有元素的中位数，那么从Arr1[0]到Arr1[totalNum/2]的所有元素就可以排除。同理当Arr1[totalNum/2]>Arr2[totalNum/2]时，从Arr2[0]到Arr2[totalNum/2]的所有元素就可以排除。当Arr1[totalNum/2]=Arr2[totalNum/2]时，说明Arr1[totalNum/2]或Arr2[totalNum/2]就是中位数。
int sortedArraySearchMedian(int *Arr1, int num1, int *Arr2, int num2, int *result)
{
	int ret = 0;
	if (Arr1 == NULL || result == NULL || Arr2 == NULL)
	{
		ret = -1;
		printf("中位数查找失败！！！");
		return ret;
	}
	int totalNum = num1 + num2;
	int temp = 0;
	if (totalNum % 2 == 1)
	{
		findkth(Arr1, num1, Arr2, num2, totalNum / 2 + 1, &temp);
		*result = temp;
	}
	else
	{
		findkth(Arr1, num1, Arr2, num2, totalNum / 2, &temp);
		int tempResult = 0;
		findkth(Arr1, num1, Arr2, num2, totalNum / 2 + 1, &tempResult);
		*result = (temp + tempResult) / 2;
	}
	return ret;
}
int findkth(int *Arr1, int num1, int *Arr2, int num2, int k, int *result)
{
	int ret = 0;
	if (Arr1 == NULL || result == NULL || Arr2 == NULL)
	{
		ret = -1;
		printf("第k大数查找失败！！！");
		return ret;
	}
	if (num1 > num2)
	{
		findkth(Arr2, num2, Arr1, num1, k, result);
	}
	if (num1 == 0)
	{
		*result = Arr2[k - 1];
		return ret;
	}
	if (k == 1)
	{
		*result = (Arr1[0] > Arr2[0] ? Arr2[0] : Arr1[0]);
		return ret;
	}
	//divide k into two parts
	int indexA = k / 2 > num1 ? num1 : k / 2;
	int indexB = k - indexA;
	if (Arr1[indexA - 1] < Arr2[indexB - 1])
	{
		findkth(Arr1 + indexA, num1 - indexA, Arr2, num2, k - indexA, result);
	}

	else if (Arr1[indexA - 1] > Arr2[indexB - 1])
	{
		findkth(Arr1, num1, Arr2 + indexB, num2 - indexB, k - indexB, result);
	}
	else
	{
		*result = Arr1[indexA - 1];
		return ret;
	}
	return ret;
}
void main04()
{
	int result = -1;
	int num = 10;
	int a[] = { 3, 3, 4, 5, 6, 1, 1, 1, 2, 3 };
	rotatedArraySearchKey(a, num, 3, &result);
	printf("查找的结果：%d\n", result);
	int b[] = { 1, 2, 3 ,4,5,6,7,8,9};
	int c[] = { 6, 7 ,8,9,10};
	int mideaNum = 0;
	sortedArraySearchMedian(b, 9, c, 5, &mideaNum);
	printf("中位数是:%d\n", mideaNum);
	system("pause");
}