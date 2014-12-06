/*
时间：2014 - 11 - 29
作者：
*/
#include <stdio.h>
#include <stdlib.h>

/*
1.插入排序
2.冒泡排序
3.快速排序
4.选择排序
5.堆排序
6.归并排序
7.基数排序
*/

#pragma region 打印数组
//打印数组
int printArr(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("打印输出失败！！！");
		return ret;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d\t", Arr[i]);
	}
	return ret;
}
#pragma endregion

#pragma region 交换数据元素
//交换数据元素
int swapNum(int *a, int *b)
{
	int ret = 0;
	if (a == NULL || b == NULL)
	{
		printf("数据交换失败！！！");
		ret = -1;
		return ret;
	}
	int temp = *a;
	*a = *b;
	*b = temp;
	return ret;
}
#pragma endregion


#pragma region 1.插入排序
//1.插入排序
//思路：已知数据元素a[0]到a[n-1]，假设前k（0 < k <=n-1）个元素从小到大有序，然后让第k+1个元素与前k个元素依次倒着比较知道找到第一个比第k+1个元素小的元素，然后将其插入这个元素的后面即可，直到k = n-1;
int insertSort(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("插入排序失败！！！");
		return ret;
	}
	for (int i = 1; i < num; i++)
	{
		int index = i - 1;
		int temp = Arr[i];//第k+1个元素 k = 0,1,2,3,...n-2
		//在前k个元素中寻找第k+1个元素的位置
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


#pragma region 2.冒泡排序
//2.冒泡排序
//思路：每次选择一个最大的的元素将其放置在比较的数组元素的最后
int bubbleSort(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("冒泡排序失败！！！");
		return ret;
	}
	auto flag = 0;//标记
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
		//如果所有的元素都没有发生交换则说明所有的元素已经有序
		if (!flag)
		{
			break;
		}
	}
	return ret;
}
#pragma endregion


#pragma region 3.快速排序
//3.快速排序
//思路：每次选择一个元素比它大的元素放在它右边比它小的元素放在它左边
int partition(int *Arr, int left, int right, int*index)
{
	int ret = 0;
	if (Arr == NULL || index == NULL)
	{
		ret = -1;
		printf("快速排序单趟排序失败！！！");
		return ret;
	}
	int temp = Arr[left];
	int i = left;
	int j = right;
	while (i != j)
	{
		//从右边开始找到第一个比temp小的元素，找到就将元素存放在Arr[i]处，然后从左边开始找第一个比temp大的元素找到之后放在Arr[j]处，直到i==j。完成一趟排序
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
		printf("快速排序失败！！！");
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


#pragma region 4.选择排序
//我犯过的错误就是弄错了数组数据类型和数据元素数据类型
//4.选择排序
//思路：假设前k（0 < k <=n-1）个元素从小到大有序，每次都从剩下的n-1-k个元素中选择一个元素加入到前k个元素中使其k+1个元素有序。
int SelectSort(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("选择排序失败！！！");
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


#pragma region 5.堆排序（大根堆）
//5.堆排序（大根堆）
//思路：首先是创建堆，然后是排序
//调整堆
int MaxHeapify(int *Arr, int currentIndex, int heapSize)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("大根堆调整失败！！！");
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
//从倒数第一个非叶子结点开始调整直到第一个结点
int BuildMaxHeap(int *Arr, int num)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("大根堆创建失败！！！");
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
		printf("大根堆排序失败！！！");
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


#pragma region 6.归并排序
//6.归并排序
//思路：先划分，然后再合并
int mergeSortCore(int *Arr, int first, int mid, const int last)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("归并排序失败！！！");
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
	free(temp);//释放在堆上分配的内存
	return ret;
}
int mergeSort(int *Arr, int first, int last)
{
	int ret = 0;
	if (Arr == NULL)
	{
		ret = -1;
		printf("归并排序失败！！！");
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

#pragma region 7.基数排序
//7.基数排序
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
		printf("基数排序失败！！！");
		return ret;
	}
	//假设最多处理n位数 
	int n = 10;
	//0~9 十个桶
	int bucketNum = 10;
	int *NumIndex[10];
	for (int i = 0; i < 10; i++)
	{
		NumIndex[i] = (int *)malloc(sizeof(int) * (num + 1));
		NumIndex[i][0] = 0;    //index为0处记录这组数据的个数  
	}
	for (int pos = 1; pos <= n; pos++)    //从个位开始到n位  
	{
		for (int i = 0; i < num; i++)
		{
			//得到每个数组元素对应的位的数字
			int posNum = getNumOfPos(Arr[i], pos);
			//得到每个数组元素在对应的桶的位置同时在每个桶的第0个位置本桶已经存储了几个数据元素
			int index = ++NumIndex[posNum][0];
			//将该元素放到对应的桶的对应的位置
			NumIndex[posNum][index] = Arr[i];
		}

		for (int i = 0, j = 0; i < bucketNum; i++)    //收集  
		{
			for (int k = 1; k <= NumIndex[i][0]; k++)
			{
				Arr[j++] = NumIndex[i][k];
			}
			NumIndex[i][0] = 0;    //复位  
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