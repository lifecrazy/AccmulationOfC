/*
ʱ�䣺2014-12-01
���ߣ�
*/
#include <stdio.h>
#include <stdlib.h>
//��ת�������ظ���Ԫ�� ʹ�ö��ֲ���
//���Ҫ���ҵ�Ԫ�ش����򷵻�true(1)���򷵻�false (0)
//˼·���ȽϵĹؼ�����Ҫȷ��mid���������ǰ�벿�ֻ��Ǻ�벿��
//���û���ظ�Ԫ��Arr[low]һ����Arr[high]����Arr[mid]������һ�����ȽϾͿ����ж�Arr[mid]��ǰ�벿�ֻ��Ǻ�벿�֣������������ظ�Ԫ�ؾͲ���ȷ��Arr[low]һ����Arr[high]�󣬾ͷ�Ϊ���������һ��������ǵ�Arr[low]����Arr[high]��ʱ����û���ظ�Ԫ�صĴ����ڶ����������Arr[low]����Arr[high]��ʱ��ͬʱArr[mid]Ҳ������ȵ�ʱ�����δ�������ǰ�벿���ǵ����ģ���low ����ֱ��Arr[low]��Arr[high]����ȾͿ����ٴο��԰��ղ���ȵ�ʱ����
int rotatedArraySearchKey(int *Arr, int num, int key, int *result)
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
			low++;//ȥ���ظ�Ԫ��
		}
	}
	*result = 0;
	return ret;
}
//���������Ѿ�����õ����飬�ҵ���������Ԫ���е���λ��
//˼·1��һ���˼·�ǽ���������ϲ�Ϊһ������Ȼ���ҳ��м���Ǹ�����������ʱ�临�Ӷ�ΪO(m+n)
//˼·2�����Զ�������ָ��ֱ�ָ����������ĵ�һԪ��Ȼ���ٶ���һ�����������ֱ�Ƚ�����ָ��ָ�������Ԫ��ֱ���������Ĵ�СΪ��������ĸ����͵�һ��Ϊֹ
//˼·3�����Ƕ��ֲ��ң��������������Ԫ�صĸ����ĺ�θtotalNum�������������Ԫ�صĸ���������totalNum/2
//��ô�ҾͿ�����Arr1[totalNum/2]��Arr2[totalNum/2]�Ƚϣ����Arr1[totalNum/2]<Arr2[totalNum/2]˵��Arr1[totalNum/2]С������������������Ԫ�ص���λ������ô��Arr1[0]��Arr1[totalNum/2]������Ԫ�ؾͿ����ų���ͬ��Arr1[totalNum/2]>Arr2[totalNum/2]ʱ����Arr2[0]��Arr2[totalNum/2]������Ԫ�ؾͿ����ų�����Arr1[totalNum/2]=Arr2[totalNum/2]ʱ��˵��Arr1[totalNum/2]��Arr2[totalNum/2]������λ����
int sortedArraySearchMedian(int *Arr1, int num1, int *Arr2, int num2, int *result)
{
	int ret = 0;
	if (Arr1 == NULL || result == NULL || Arr2 == NULL)
	{
		ret = -1;
		printf("��λ������ʧ�ܣ�����");
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
		printf("��k��������ʧ�ܣ�����");
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
	printf("���ҵĽ����%d\n", result);
	int b[] = { 1, 2, 3 ,4,5,6,7,8,9};
	int c[] = { 6, 7 ,8,9,10};
	int mideaNum = 0;
	sortedArraySearchMedian(b, 9, c, 5, &mideaNum);
	printf("��λ����:%d\n", mideaNum);
	system("pause");
}