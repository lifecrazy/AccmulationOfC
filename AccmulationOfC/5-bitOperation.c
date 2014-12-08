/*
时间：2014-12-01
作者：
*/
#include <stdio.h>
#include <stdlib.h>
#pragma region 1.打印一个数的二进制表示
//1.打印一个数的二进制表示
//首先要明白计算机中所有的数字都是用补码表示的，
//那么如果是负数下面的函数打印出来的则是补码
//32位计算机的int是4个字节，将这个数左移i = 31位则第32位就在从右向左的第一位，将i依次递减就可以从右至左依次打印出一个数的32为二进制表示
void printBitOfInt(int num)
{
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", num >> i & 0x1);
	}
}
#pragma endregion

#pragma region 2.请编写一个 C 函数，该函数给出一个字节中被置 1 的位的个数。
//2.请编写一个 C 函数，该函数给出一个字节中被置 1 的位的个数。
//思路：一个字节怎么表示 char正好是一个字节就用char表示
//首先要得到该字节的二进制表示然后在判断是否为一进行统计
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

//3.判断一个数是否为2的N次幂
//思路：例子：8 的二进制1000
//            7 的二进制0111
//如果与运算的结果为0表示是2的N次幂如果不是0则不是
int isPowerTwo(int n)
{
	return (n>0) && (n&(n - 1));
}
//关于异或运算:相同为零，相异为一
//4.一个数组除了一个数的个数为一个，其余数的个数都是偶数个，求那个个数为一个的数
//思路：相同的数字进行与运算之后都变为了0，最后就剩下那个数了
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
//5.一个数组除了一个数的个数为一个，其余数的个数都是奇数个，求那个个数为一个的数
//思路：用一个有32个元素的数组表示所有的数字的32位上已出现的次数，然后和3取余数，最后可以得出那个单独的数字的二进制表示
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
	printf("5的二进制表示：    ");
	printBitOfInt(5);
	printf("\n");
	printf("-5的二进制表示：   ");
	printBitOfInt(-5);
	printf("\n");
	int count = 0;
	getCharCount('A', &count);
	printf("字符A中含有1的个数是：%d\n", count);
	printf("判断0是否为2的N次幂：%d\n", isPowerTwo(0));
	printf("判断16是否为2的N次幂：%d\n", isPowerTwo(16));
	printf("判断15是否为2的N次幂：%d\n", isPowerTwo(15));
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