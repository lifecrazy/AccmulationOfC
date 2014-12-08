/*
ʱ�䣺2014-12-01
���ߣ�
*/
#include <stdio.h>
#include <stdlib.h>
#pragma region 1.��ӡһ�����Ķ����Ʊ�ʾ
//1.��ӡһ�����Ķ����Ʊ�ʾ
//����Ҫ���׼���������е����ֶ����ò����ʾ�ģ�
//��ô����Ǹ�������ĺ�����ӡ���������ǲ���
//32λ�������int��4���ֽڣ������������i = 31λ���32λ���ڴ�������ĵ�һλ����i���εݼ��Ϳ��Դ����������δ�ӡ��һ������32Ϊ�����Ʊ�ʾ
void printBitOfInt(int num)
{
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", num >> i & 0x1);
	}
}
#pragma endregion

#pragma region 2.���дһ�� C �������ú�������һ���ֽ��б��� 1 ��λ�ĸ�����
//2.���дһ�� C �������ú�������һ���ֽ��б��� 1 ��λ�ĸ�����
//˼·��һ���ֽ���ô��ʾ char������һ���ֽھ���char��ʾ
//����Ҫ�õ����ֽڵĶ����Ʊ�ʾȻ�����ж��Ƿ�Ϊһ����ͳ��
int getCharCount(char c, int*count)
{
	int ret = 0;
	if (count == NULL)
	{
		ret = -1;
		printf("func getCharCount err:%d", ret);
		return ret;
	}
	int result = 0;
	for (int i = 0; i < 8; i++)
	{
		int temp = c >> i & 0x1;
		if (temp == 1)
		{
			result++;
		}
	}
	*count = result;
	return ret;
}
#pragma endregion

//3.�ж�һ�����Ƿ�Ϊ2��N����
//˼·�����ӣ�8 �Ķ�����1000
//            7 �Ķ�����0111
//���������Ľ��Ϊ0��ʾ��2��N�����������0����
int isPowerTwo(int n)
{
	return (n>0) && (n&(n - 1));
}
//�����������:��ͬΪ�㣬����Ϊһ
//4.һ���������һ�����ĸ���Ϊһ�����������ĸ�������ż���������Ǹ�����Ϊһ������
//˼·����ͬ�����ֽ���������֮�󶼱�Ϊ��0������ʣ���Ǹ�����
int getEvenSingleOne(int *Arr, int num, int *result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("func getEvenSingleOne err :%d", ret);
		return ret;
	}
	int numResult = Arr[0];
	for (int i = 1; i < num; i++)
	{
		numResult ^= Arr[i];
	}
	*result = numResult;
	return ret;
}
//5.һ���������һ�����ĸ���Ϊһ�����������ĸ������������������Ǹ�����Ϊһ������
//˼·����һ����32��Ԫ�ص������ʾ���е����ֵ�32λ���ѳ��ֵĴ�����Ȼ���3ȡ�����������Եó��Ǹ����������ֵĶ����Ʊ�ʾ
int getOddSingleOne(int *Arr, int num, int *result)
{
	int ret = 0;
	if (Arr == NULL || result == NULL)
	{
		ret = -1;
		printf("func getEvenSingleOne err :%d", ret);
		return ret;
	}
	int count[32] = { 0 };
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			count[j] += Arr[i] >> j & 1;
			
		}
	}
	int numResult = 0;
	for (int i = 0; i < 32; i++)
	{
		count[i] %= 3;
		numResult += (count[i] << i);
	}
	*result = numResult;
	return ret;
}
void main()
{
	printf("5�Ķ����Ʊ�ʾ��    ");
	printBitOfInt(5);
	printf("\n");
	printf("-5�Ķ����Ʊ�ʾ��   ");
	printBitOfInt(-5);
	printf("\n");
	int count = 0;
	getCharCount('A', &count);
	printf("�ַ�A�к���1�ĸ����ǣ�%d\n", count);
	printf("�ж�0�Ƿ�Ϊ2��N���ݣ�%d\n", isPowerTwo(0));
	printf("�ж�16�Ƿ�Ϊ2��N���ݣ�%d\n", isPowerTwo(16));
	printf("�ж�15�Ƿ�Ϊ2��N���ݣ�%d\n", isPowerTwo(15));
	int num = 21;
	int a[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 0, 0, 20 };
	int result = 0;
	getEvenSingleOne(a, num, &result);
	printf("%d\n", result);
	int b[] = { 1, 1, 1, 3, 3, 3, 4, 4, 4, 6, 6, 6, 7, 7, 7, 9, 9, 9, 0, 0, 0, 20 };
	int resultOdd = 0;
	getOddSingleOne(b, num + 1, &resultOdd);
	printf("%d\n", resultOdd);
	system("pause");
}