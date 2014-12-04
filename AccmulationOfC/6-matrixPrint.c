/*
时间：2014-12-01
作者：
*/
#include <stdio.h>
#include <stdlib.h>

//1.矩阵的初始化方法一
int matrixInit(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵初始化失败！！！");
		return ret;
	}
	
	for (int i = 0; i < num*num; i++)
	{
		Arr[i / num][i%num] = i;
	}
	return ret;
}
//2.矩阵的初始化方法二
int matrixInitOfSecond(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵初始化失败！！！");
		return ret;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			Arr[i][j] = i*num + j;
		}
	}
	return ret;
}
//3.打印矩阵
int matrixPrint(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵初始化失败！！！");
		return ret;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%4d  ", Arr[i][j]);
		}
		printf("\n");
	}
	
	return ret;
}
//4.按照回型打印
int matrixPrintByEdge(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵初始化失败！！！");
		return ret;
	}
	for (int i = 0; i <num; i++)//列
	{
		for (int j = i; j <num-i; j++)//行
		{
			printf("%d  ", Arr[i][j]);
		}
		for (int j = i+1; j < num-i; j++)
		{
			printf("%d  ", Arr[j][num-i-1]);
		}
		for (int j = num-i-2; j >=i; j--)
		{
			printf("%d  ", Arr[num - i - 1][j]);
		}
		for (int j = num - i - 2; j >i; j--)
		{
			printf("%d  ", Arr[j][i]);
		}
	}
	printf("\n");
	
	return ret;
}
//5.按照主对角线从上往下打印
int matrixPrintByDiagonalFirst(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵初始化失败！！！");
		return ret;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d  ", Arr[j][i - j]);
		}
		printf("\n");
	}
	for (int i = 1; i < num; i++)
	{
		for (int j = num - 1; j >= i; j--)
		{
			printf("%d  ", Arr[num - 1 - j + i][j]);
		}
		printf("\n");
	}
	

	return ret;
}
//6.按照主对角线从下往上打印
int matrixPrintByDiagonalSec(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵初始化失败！！！");
		return ret;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d  ", Arr[i - j][j]);
		}
		printf("\n");
	}
	for (int i = 1; i < num; i++)
	{
		for (int j = num - 1; j >= i; j--)
		{
			printf("%d  ", Arr[j][num - 1 - j + i]);
		}
		printf("\n");
	}
	return ret;
}
//7.按照副对角线从上往下打印
int matrixPrintByDiagonalThird(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵初始化失败！！！");
		return ret;
	}
	for (int i = num - 1; i >= 0; i--)//列
	{
		for (int j = 0; j < num - i; j++)//行
		{
			printf("%d  ", Arr[j][i + j]);
		}
		printf("\n");
	}
	for (int i = 1; i < num; i++)//行
	{
		for (int j = 0; j < num - i; j++)//列
		{
			printf("%d  ", Arr[i + j][j]);
		}
		printf("\n");
	}
	return ret;
}
//8.按照副对角线从下往上打印
int matrixPrintByDiagonalForth(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("矩阵初始化失败！！！");
		return ret;
	}
	for (int i =0; i <num; i++)//列
	{
		for (int j = i; j >=0; j--)//行
		{
			printf("%d  ", Arr[j][num-1-(i-j)]);
		}
		printf("\n");
	}
	for (int i = 1; i < num; i++)//行
	{
		for (int j = num-1-i; j >=0; j--)//列
		{
			printf("%d  ", Arr[i+j][j]);
		}
		printf("\n");
	}
	return ret;
}
void mainformatrixPrint()
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
	printf("*********矩阵按照回型打印************\n");
	matrixPrintByEdge(a,n);
	printf("*********矩阵按照主对角线从上往下打印************\n");
	matrixPrintByDiagonalFirst(a, n);
	printf("*********矩阵按照主对角线从下往上打印************\n");
	matrixPrintByDiagonalSec(a, n);
	printf("*********矩阵按照副对角线从上往下打印************\n");
	matrixPrintByDiagonalThird(a, n);
	printf("*********矩阵按照副对角线从下往上打印************\n");
	matrixPrintByDiagonalForth(a, n);
	system("pause");
}