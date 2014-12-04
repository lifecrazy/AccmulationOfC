/*
时间：2014-12-04
作者：
*/
#include <stdio.h>
#include <stdlib.h>
//矩阵的查找
//题目：假设矩阵从上到下依次增大从左到右依次增大，查找每个数字是否在这个矩阵当中
//如果要查找的元素存在则返回true(1)否则返回false(0)
//思路：
int matrixSearchKey(int **Arr, int num, int key, int *result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("矩阵查找失败！！！");
		return ret;
	}
	int i = 0;
	int j = num - 1;
	while (i < num&&j >= 0)
	{
		if (Arr[i][j] > key)
		{
			j--;
		}
		else if (Arr[i][j] < key)
		{
			i++;
		}
		else
		{
			*result = 1;
			return ret;
		}
	}
	*result = 0;
	return ret;
}
//题目：将矩阵旋转九十度
int matrixRotating(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵旋转失败！！！");
		return ret;
	}
	int temp = 0;
	//按照副对角线进行翻转
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num -i; j++)
		{
			temp = Arr[i][j];
			Arr[i][j] = Arr[num - j - 1][num - i - 1];
			Arr[num - j - 1][num - i - 1] = temp;
		}
	}
	//按照中轴线上下翻转
	for (int i = 0; i < num / 2; i++)
	{
		for (int j = 0; j < num; j++)
		{
			temp = Arr[i][j];
			Arr[i][j] = Arr[num - i - 1][j];
			Arr[num - i - 1][j] = temp;
		}
	}
	return ret;
}
//转置
int matrixTransposition(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵转置失败！！！");
		return ret;
	}
	int temp = 0;
	//按照副对角线进行翻转
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			temp = Arr[i][j];
			Arr[i][j] = Arr[j][i];
			Arr[j][i] = temp;
		}
	}
	return ret;
}
void main()
{
	const int n = 4;
	int **a = (int **)malloc(n*sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int *)malloc(sizeof(int)*n);
	}
	//初始化矩阵
	matrixInit(a, n);
	//原矩阵打印
	matrixPrint(a, n);
	int result;
	matrixSearchKey(a, n, 9, &result);
	printf("查找结果：%d\n", result);
	//matrixRotating(a, n);
	//matrixPrint(a, n);
	matrixTransposition(a, n);
	matrixPrint(a, n);
	system("pause");
}