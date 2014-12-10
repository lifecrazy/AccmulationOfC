#include <stdio.h>
#include <stdlib.h>
//题目：字符串压缩
//例子： "aaaaaaaaaaaabbbbbbbbbccccccd"→9a3a9b6c1d
//思路：1.首先定义一个指针指向要被压缩的字符串然后定义一个统计变量count
//      2.首先自增统计一个字符，然后依次和前一个字符比较如果相同统计变量count自增，如果count自增到9就记录依次然后让count 重新回1继续统计，如果不相等就记录直到末尾结束。
//      3.结束之后如果count不等于1表示最后一个字符没有统计，添加上即可。
//附：如果为"11111112222223333"可以这样统计"7[1]6[2]4[3]",方法如下
int getResult(char *str, char *outbuf)
{
	int ret = 0;
	if (str == NULL || outbuf == NULL)
	{
		ret = -1;
		printf("func getResult err :%d", ret);
		return ret;
	}
	char *p = str;
	char *result = outbuf;
	int count = 1;
	p++;
	while (*p != '\0')
	{
		if (*(p - 1) == *p)
		{
			count++;
			if (count == 9)
			{
				*result = '9';
				*result++;
				*result = *p;
				*result++;
				count = 1;
				p++;
			}
		}
		else
		{

			*result = ('0' + count);
			*result++;
			*result = *(p - 1);
			*result++;
			count = 1;
		}
		p++;
	}
	if (count != 1)
	{
		*result = ('0' + count);
		*result++;
		*result = *(p - 1);
		*result++;
	}
	*result = '\0';
	return ret;
}
//count and say            1, 11, 21, 1211, 111221, ...
int getCountAndSay(int n, char *outbuf)
{
	int ret = 0;
	if (outbuf == NULL)
	{
		ret = -1;
		printf("func getCountAndSay err :%d", ret);
		return ret;
	}
	if (n < 1)
	{
		ret = -2;
		printf("func getCountAndSay n = %d :非法 err :%d", n, ret);
		return ret;
	}
	char *start = (char *)malloc(2 * sizeof(char));
	*start = '1';
	*(start + 1) = '\0';
	char *result = outbuf;
	if (n == 1)
	{
		outbuf = start;
		return ret;
	}
	for (int i = 1; i < n; i++)
	{
		char c = start[0];//设置临时变量
		result = outbuf;//记录结果
		int count = 1;//计数
		char *p = start;
		p++;//从第二个开始和第一个比较
		while (*p != '\0')
		{
			if (*p == c)
			{
				count++;
			}
			else
			{
				*result = count + '0';
				result++;
				*result = c;
				result++;
				c = *p;
				count = 1;
			}
			p++;
		}
		*result = count + '0';
		result++;
		*result = c;
		result++;
		*result = '\0';
		if (i != n - 1)
		{//每次申请2*i个内存记录本次计数记录的记过
			/*char *freeStart = start;
			start = (char *)malloc(2 * i*sizeof(char));
			memset(start, 0, 2 * i*sizeof(char));
			char *Stemp = start;
			char *temp = outbuf;
			while ((*Stemp++ = *temp++) != '\0')
			{
			}
			if (freeStart != NULL)
			{
				free(freeStart);
			}*/
			start = (char *)malloc(2 * i*sizeof(char));
			char *Stemp = start;
			char *temp = outbuf;
			while ((*Stemp++ = *temp++) != '\0')
			{
			}
		}
	}
}
void main11()
{
	char *p = "aaaaaaaaaaaabbbbbbbbbccccccd";
	char buf[100];
	getResult(p, buf);
	printf("%s\n", buf);
	char buf2[100];
	getCountAndSay(5, buf2);
	printf("%s\n", buf2);
	system("pause");
}