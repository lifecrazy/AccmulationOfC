/*
ʱ�䣺2014 - 11 - 29
���ߣ�
*/
#include <stdio.h>
#include <stdlib.h>

/*
1.��������
2.ð������
3.��������
4.ѡ������
5.������
6.�鲢����
7.��������
*/

#pragma region ��ӡ����
//��ӡ����
int printArr(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("��ӡ���ʧ�ܣ�����");
		return ret;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d\t", Arr[i]);
	}
	return ret;
}
#pragma endregion

#pragma region ��������Ԫ��
//��������Ԫ��
int swapNum(int *a, int *b)
{
	int ret = 0;
	if (a == NULL || b == NULL)
	{
		printf("���ݽ���ʧ�ܣ�����");
		ret = -1;
		return ret;
	}
	int temp = *a;
	*a = *b;
	*b = temp;
	return ret;
}
#pragma endregion


#pragma region 1.��������
//1.��������
//˼·����֪����Ԫ��a[0]��a[n-1]������ǰk��0 < k <=n-1����Ԫ�ش�С��������Ȼ���õ�k+1��Ԫ����ǰk��Ԫ�����ε��űȽ�֪���ҵ���һ���ȵ�k+1��Ԫ��С��Ԫ�أ�Ȼ����������Ԫ�صĺ��漴�ɣ�ֱ��k = n-1;
int insertSort(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("��������ʧ�ܣ�����");
		return ret;
	}
	for (int i = 1; i < num; i++)
	{
		int index = i - 1;
		int temp = Arr[i];//��k+1��Ԫ�� k = 0,1,2,3,...n-2
		//��ǰk��Ԫ����Ѱ�ҵ�k+1��Ԫ�ص�λ��
		while (index >= 0 && Arr[index] > temp)
		{
			Arr[index + 1] = Arr[index];
			index--;
		}
		Arr[index + 1] = temp;
	}
	return ret;
}
#pragma endregion


#pragma region 2.ð������
//2.ð������
//˼·��ÿ��ѡ��һ�����ĵ�Ԫ�ؽ�������ڱȽϵ�����Ԫ�ص����
int bubbleSort(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("ð������ʧ�ܣ�����");
		return ret;
	}
	auto flag = 0;//���
	for (int i = num - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (Arr[i] < Arr[j])
			{
				flag = 1;
				swapNum(&Arr[i], &Arr[j]);
			}

		}
		//������е�Ԫ�ض�û�з���������˵�����е�Ԫ���Ѿ�����
		if (!flag)
		{
			break;
		}
	}
	return ret;
}
#pragma endregion


#pragma region 3.��������
//3.��������
//˼·��ÿ��ѡ��һ��Ԫ�ر������Ԫ�ط������ұ߱���С��Ԫ�ط��������
int partition(int *Arr, int left, int right, int*index)
{
	int ret = 0;
	if (Arr == NULL || index == NULL)
	{
		ret = -1;
		printf("��������������ʧ�ܣ�����");
		return ret;
	}
	int temp = Arr[left];
	int i = left;
	int j = right;
	while (i != j)
	{
		//���ұ߿�ʼ�ҵ���һ����tempС��Ԫ�أ��ҵ��ͽ�Ԫ�ش����Arr[i]����Ȼ�����߿�ʼ�ҵ�һ����temp���Ԫ���ҵ�֮�����Arr[j]����ֱ��i==j�����һ������
		while (i<j&&Arr[j]>temp)
		{
			j--;
		}
		if (i < j)
		{
			Arr[i++] = Arr[j];
		}
		while (i < j&&Arr[i] < temp)
		{
			i++;
		}
		if (i < j)
		{
			Arr[j--] = Arr[i];
		}

	}
	Arr[i] = temp;
	*index = i;
	return ret;
}
int quickSort(int *Arr, int left, int right)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("��������ʧ�ܣ�����");
		return ret;
	}
	if (left <= right)
	{
		int index;
		partition(Arr, left, right, &index);
		quickSort(Arr, left, index - 1);
		quickSort(Arr, index + 1, right);
	}
	return ret;
}
#pragma endregion


#pragma region 4.ѡ������
//�ҷ����Ĵ������Ū���������������ͺ�����Ԫ����������
//4.ѡ������
//˼·������ǰk��0 < k <=n-1����Ԫ�ش�С��������ÿ�ζ���ʣ�µ�n-1-k��Ԫ����ѡ��һ��Ԫ�ؼ��뵽ǰk��Ԫ����ʹ��k+1��Ԫ������
int SelectSort(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("ѡ������ʧ�ܣ�����");
		return ret;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (Arr[i]>Arr[j])
			{
				swapNum(&Arr[i], &Arr[j]);
			}
		}
	}
	return ret;
}
#pragma endregion


#pragma region 5.�����򣨴���ѣ�
//5.�����򣨴���ѣ�
//˼·�������Ǵ����ѣ�Ȼ��������
//������
int MaxHeapify(int *Arr, int currentIndex, int heapSize)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("����ѵ���ʧ�ܣ�����");
		return ret;
	}
	int left = currentIndex * 2 + 1;
	int right = currentIndex * 2 + 2;
	int large = currentIndex;
	if (left < heapSize && Arr[left]>Arr[large])
	{
		large = left;
	}
	if (right <heapSize && Arr[right]>Arr[large])
	{
		large = right;
	}
	if (currentIndex != large)
	{
		swapNum(&Arr[currentIndex], &Arr[large]);
		MaxHeapify(Arr, large, heapSize);
	}
	return ret;
}
//�ӵ�����һ����Ҷ�ӽ�㿪ʼ����ֱ����һ�����
int BuildMaxHeap(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("����Ѵ���ʧ�ܣ�����");
		return ret;
	}
	for (int i = num / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(Arr, i, num);
	}
	return ret;
}
int heapSort(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("���������ʧ�ܣ�����");
		return ret;
	}
	BuildMaxHeap(Arr, num);
	for (int i = num - 1; i > 0; i--)
	{
		swapNum(&Arr[0], &Arr[i]);
		MaxHeapify(Arr, 0, i);
	}
	return ret;
}
#pragma endregion


#pragma region 6.�鲢����
//6.�鲢����
//˼·���Ȼ��֣�Ȼ���ٺϲ�
int mergeSortCore(int *Arr, int first, int mid, const int last)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�鲢����ʧ�ܣ�����");
		return ret;
	}
	int indexA = first;
	int indexB = mid + 1;
	int *temp = (int*)malloc((last + 1)*sizeof(int));
	int *cur = temp;
	while (indexA <= mid&&indexB <= last)
	{
		if (Arr[indexA] <= Arr[indexB])
		{
			*cur++ = Arr[indexA++];
		}
		else
		{
			*cur++ = Arr[indexB++];
		}
	}
	while (indexA <= mid)
	{
		*cur++ = Arr[indexA++];
	}
	while (indexB <= last)
	{
		*cur++ = Arr[indexB++];
	}
	cur = temp;
	for (int i = first; i <= last; i++)
	{
		Arr[i] = *cur;
		cur++;
	}
	free(temp);//�ͷ��ڶ��Ϸ�����ڴ�
	return ret;
}
int mergeSort(int *Arr, int first, int last)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("�鲢����ʧ�ܣ�����");
		return ret;
	}
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergeSort(Arr, first, mid);
		mergeSort(Arr, mid + 1, last);
		mergeSortCore(Arr, first, mid, last);
	}
	return ret;
}
#pragma endregion

#pragma region 7.��������
//7.��������
int getNumOfPos(int num, int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}
int msdradixSort(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("��������ʧ�ܣ�����");
		return ret;
	}
	//������ദ��nλ�� 
	int n = 10;
	//0~9 ʮ��Ͱ
	int bucketNum = 10;
	int *NumIndex[10];
	for (int i = 0; i < 10; i++)
	{
		NumIndex[i] = (int *)malloc(sizeof(int) * (num + 1));
		NumIndex[i][0] = 0;    //indexΪ0����¼�������ݵĸ���  
	}
	for (int pos = 1; pos <= n; pos++)    //�Ӹ�λ��ʼ��nλ  
	{
		for (int i = 0; i < num; i++)
		{
			//�õ�ÿ������Ԫ�ض�Ӧ��λ������
			int posNum = getNumOfPos(Arr[i], pos);
			//�õ�ÿ������Ԫ���ڶ�Ӧ��Ͱ��λ��ͬʱ��ÿ��Ͱ�ĵ�0��λ�ñ�Ͱ�Ѿ��洢�˼�������Ԫ��
			int index = ++NumIndex[posNum][0];
			//����Ԫ�طŵ���Ӧ��Ͱ�Ķ�Ӧ��λ��
			NumIndex[posNum][index] = Arr[i];
		}

		for (int i = 0, j = 0; i < bucketNum; i++)    //�ռ�  
		{
			for (int k = 1; k <= NumIndex[i][0]; k++)
			{
				Arr[j++] = NumIndex[i][k];
			}
			NumIndex[i][0] = 0;    //��λ  
		}
	}
	return ret;
}
#pragma endregion


void mainforsortlist()
{
	int num = 10;
	int a[] = { 4, 6, 2, 1, 3, 66, 33, 44, 22, 9 };
	printArr(a, num);
	msdradixSort(a, num);
	//mergeSort(a, 0, num - 1);
	printArr(a, num);



	system("pause");
}