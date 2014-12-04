/*
ʱ�䣺2014-12-04
���ߣ�
*/
#include <stdio.h>
#include <stdlib.h>
//����Ĳ���
//��Ŀ�����������ϵ�����������������������󣬲���ÿ�������Ƿ������������
//���Ҫ���ҵ�Ԫ�ش����򷵻�true(1)���򷵻�false(0)
//˼·��
int matrixSearchKey(int **Arr, int num, int key, int *result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("�������ʧ�ܣ�����");
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
//��Ŀ����������ת��ʮ��
int matrixRotating(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("������תʧ�ܣ�����");
		return ret;
	}
	int temp = 0;
	//���ո��Խ��߽��з�ת
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num -i; j++)
		{
			temp = Arr[i][j];
			Arr[i][j] = Arr[num - j - 1][num - i - 1];
			Arr[num - j - 1][num - i - 1] = temp;
		}
	}
	//�������������·�ת
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
//ת��
int matrixTransposition(int **Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("����ת��ʧ�ܣ�����");
		return ret;
	}
	int temp = 0;
	//���ո��Խ��߽��з�ת
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
	//��ʼ������
	matrixInit(a, n);
	//ԭ�����ӡ
	matrixPrint(a, n);
	int result;
	matrixSearchKey(a, n, 9, &result);
	printf("���ҽ����%d\n", result);
	//matrixRotating(a, n);
	//matrixPrint(a, n);
	matrixTransposition(a, n);
	matrixPrint(a, n);
	system("pause");
}