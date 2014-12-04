/*
ʱ�䣺2014-12-01
���ߣ�
*/
#include <stdio.h>
#include <stdlib.h>

//1.����ĳ�ʼ������һ
int matrixInit(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�����ʼ��ʧ�ܣ�����");
		return ret;
	}
	
	for (int i = 0; i < num*num; i++)
	{
		Arr[i / num][i%num] = i;
	}
	return ret;
}
//2.����ĳ�ʼ��������
int matrixInitOfSecond(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�����ʼ��ʧ�ܣ�����");
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
//3.��ӡ����
int matrixPrint(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�����ʼ��ʧ�ܣ�����");
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
//4.���ջ��ʹ�ӡ
int matrixPrintByEdge(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�����ʼ��ʧ�ܣ�����");
		return ret;
	}
	for (int i = 0; i <num; i++)//��
	{
		for (int j = i; j <num-i; j++)//��
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
//5.�������Խ��ߴ������´�ӡ
int matrixPrintByDiagonalFirst(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�����ʼ��ʧ�ܣ�����");
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
//6.�������Խ��ߴ������ϴ�ӡ
int matrixPrintByDiagonalSec(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�����ʼ��ʧ�ܣ�����");
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
//7.���ո��Խ��ߴ������´�ӡ
int matrixPrintByDiagonalThird(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�����ʼ��ʧ�ܣ�����");
		return ret;
	}
	for (int i = num - 1; i >= 0; i--)//��
	{
		for (int j = 0; j < num - i; j++)//��
		{
			printf("%d  ", Arr[j][i + j]);
		}
		printf("\n");
	}
	for (int i = 1; i < num; i++)//��
	{
		for (int j = 0; j < num - i; j++)//��
		{
			printf("%d  ", Arr[i + j][j]);
		}
		printf("\n");
	}
	return ret;
}
//8.���ո��Խ��ߴ������ϴ�ӡ
int matrixPrintByDiagonalForth(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�����ʼ��ʧ�ܣ�����");
		return ret;
	}
	for (int i =0; i <num; i++)//��
	{
		for (int j = i; j >=0; j--)//��
		{
			printf("%d  ", Arr[j][num-1-(i-j)]);
		}
		printf("\n");
	}
	for (int i = 1; i < num; i++)//��
	{
		for (int j = num-1-i; j >=0; j--)//��
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
	//��ʼ������
	matrixInit(a, n);
	//ԭ�����ӡ
	matrixPrint(a, n);
	printf("*********�����ջ��ʹ�ӡ************\n");
	matrixPrintByEdge(a,n);
	printf("*********���������Խ��ߴ������´�ӡ************\n");
	matrixPrintByDiagonalFirst(a, n);
	printf("*********���������Խ��ߴ������ϴ�ӡ************\n");
	matrixPrintByDiagonalSec(a, n);
	printf("*********�����ո��Խ��ߴ������´�ӡ************\n");
	matrixPrintByDiagonalThird(a, n);
	printf("*********�����ո��Խ��ߴ������ϴ�ӡ************\n");
	matrixPrintByDiagonalForth(a, n);
	system("pause");
}