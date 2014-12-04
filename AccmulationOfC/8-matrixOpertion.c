/*
时间：2014-12-04
作者：
*/
#include <stdio.h>
#include <stdlib.h>
//矩阵的查找
//题目：假设矩阵从上到下依次增大从左到右依次增大，查找每个数字是否在这个矩阵当中
//如果要查找的元素存在则返回true(1)否则返回false(0)
//思路：从右上角开始查找
//                       如果Arr[i][j] > key即key小于右上角的那个元素那么key就一定在左边的列当中所以行递减
//                       如果Arr[i][j] > key即key小于右上角的那个元素那么key就一定在下边的行当中所以列递增
//                       如果Arr[i][j] = key即为找到
//也可以从左下角开始查找思路与上边一样
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
//思路：将整个矩阵先按照副对角线翻转，然后按照中轴线上下翻转就能使其旋转九十度
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
//题目：矩阵转置
//将整个矩阵按照主对角线翻转就能得到结果
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
	printf("矩阵旋转九十度：\n");
	matrixRotating(a, n);
	matrixPrint(a, n);
	printf("矩阵转置：\n");
	matrixTransposition(a, n);
	matrixPrint(a, n);
	system("pause");
}