#include <stdio.h>
#include <stdlib.h>
//删除字符串开头和结束的字符
//思路：定义两个指针分别指向字符串的开头和结尾，然后分别从开头和结尾开始查找直到遇到第一个非空格的字符位置
int trimSpace(char *str,char *outbuf)
{
	int ret = 0;
	if (str == NULL ||outbuf == NULL)
	{
		ret = -1;
		printf("func trimSpace err :%d", ret);
		return ret;
	}
	char *start = str;
	char *end = str + strlen(str) - 1;
	while (start < end&&*start == ' ')
	{
		start++;
	}
	while (start < end&&*end == ' ')
	{
		end--;
	}
	memcpy( outbuf,start, end - start + 1);
	outbuf[end - start + 1] = '\0';
	
}
//删除字符串中多余的空格。例子原始字符串“     I     love             china            ”，处理后的字符串“I love china”。
//思路：1.定义两个指针分别指向字符串的开头一个pPre保存结果，一个pCur查找字符串
//      2.当pCur不是空格的时候就拷贝到pPre处然后各自自增
//      3.当遇到空格的时候就删除所有的空格，然后判断是不是字符串的开始（flag ==0）或者结尾(*pCur == '\0'),如果不是则添加一个空格否则就修改标记
int deleteSpace(char *str)
{
	int ret = 0;
	if (str == NULL)
	{
		ret = -1;
		printf("func deleteSpace err :%d", ret);
		return ret;
	}
	char *pCur = str;
	char *pPre = str;
	int flag = 0;
	while (*pCur != '\0')
	{
		if (*pCur != ' ')
		{
			*pPre++ = *pCur++;
		}
		else
		{
			while (*pCur == ' ')
			{
				pCur++;
			}
			if (flag == 0 || *pCur == '\0')
			{
				flag = 1;
			}
			else
			{
				*pPre = ' ';
				pPre++;
			}
		}
	}
	*pPre = '\0';
}
void main()
{
	char *p = "              aaaaaaa      aaaaaa                 ";
	char result[100];
	trimSpace(p, result);
	printf("删除字符串前后的空格后:\n%s\n", result);
	char buf[] = "     I     love             you            ";
	deleteSpace(buf);
	printf("删除字符串中多余的空格后:\n%s\n", buf);
	system("pause");
}