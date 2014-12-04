#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//strlen
int getStrLen(char *str, int *count)
{
	int ret = 0;
	if (str == NULL || count == NULL)
	{
		ret = -1;
		printf("func myStrLen err :%d", ret);
		return ret;
	}
	char *p = str;
	int result = 0;
	while (*p != '\0')
	{
		result++;
		p++;
	}
	*count = result;
	return ret;
}
int trimSpace(char *str, char *outbuf)
{
	int ret = 0;
	if (str == NULL || outbuf == NULL)
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
	memcpy(outbuf, start, end - start + 1);
	outbuf[end - start + 1] = '\0';
}
//strrev
int reversalStr(char *str)
{
	int ret = 0;
	if (str == NULL)
	{
		ret = -1;
		printf("func reversalStr err :%d", ret);
		return ret;
	}
	char *start = str;
	char *end = str + strlen(str) - 1;
	char c;
	while (start < end)
	{
		c = *start;
		*start = *end;
		*end = c;
		start++;
		end--;
	}
	return ret;
}
//strstr
int strStr(char *haystack, char *needle, int *index)
{
	int ret = 0;
	if (haystack == NULL)
	{
		ret = -1;
		printf("func strStr err :%d", ret);
		return ret;
	}
	char *start = haystack;
	char *temp = needle;
	int tempcount = 0;
	while (*start != '\0')
	{
		tempcount = 0;
		while (*temp != '\0')
		{
			if (*start != *temp)
			{
				break;
			}
			start++;
			temp++;
			tempcount++;
		}
		start = start - tempcount + 1;
		if (*temp == '\0')
		{
			*index = start - haystack;
			return ret;
		}
		temp = needle;
	}
	*index = -1;
	return ret;
}
void main07()
{
	//char *str = "abcde";
	//int result = 0;
	//getStrLen(str, &result);
	//printf("result :%d\n", result);
	//char *str2 = "              abcdefghi       ";
	//char buf[30];
	//trimSpace(str2, buf);
	//printf("buf:%s\n", buf);
	char buf3[] = "abcdefghijklmnopqrst";
	//reversalStr(buf3);
	//printf("buf3:%s\n", buf3);
	char *p = "eff";
	int index = 0;
	strStr(buf3, p, &index);
	printf("index :%d\n", index);
	system("pause");
}