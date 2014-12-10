#include <stdio.h>
#include <stdlib.h>
//��Ŀ���ַ���ѹ��
//���ӣ� "aaaaaaaaaaaabbbbbbbbbccccccd"��9a3a9b6c1d
//˼·��1.���ȶ���һ��ָ��ָ��Ҫ��ѹ�����ַ���Ȼ����һ��ͳ�Ʊ���count
//      2.��������ͳ��һ���ַ���Ȼ�����κ�ǰһ���ַ��Ƚ������ͬͳ�Ʊ���count���������count������9�ͼ�¼����Ȼ����count ���»�1����ͳ�ƣ��������Ⱦͼ�¼ֱ��ĩβ������
//      3.����֮�����count������1��ʾ���һ���ַ�û��ͳ�ƣ�����ϼ��ɡ�
//�������Ϊ"11111112222223333"��������ͳ��"7[1]6[2]4[3]",��������
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
		printf("func getCountAndSay n = %d :�Ƿ� err :%d", n, ret);
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
		char c = start[0];//������ʱ����
		result = outbuf;//��¼���
		int count = 1;//����
		char *p = start;
		p++;//�ӵڶ�����ʼ�͵�һ���Ƚ�
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
		{//ÿ������2*i���ڴ��¼���μ�����¼�ļǹ�
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