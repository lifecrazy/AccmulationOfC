#include <stdio.h>
#include <stdlib.h>

//strlen字符串字符个数的统计。
//strcat字符串追加。
//strcpy字符串拷贝。
//strstr查找子字符串。
//strtok字符串按照某个字符分割。
//1.strlen
int mystrLen(char *str, int *count)
{
	int ret = 0;
	if (str == NULL || count == NULL)
	{
		ret = -1;
		printf("func mystrLen err :%d", ret);
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
//2.strcpy
int mystrcpy(char *strDest, char *strSrc)
{
	int ret = 0;
	if (strDest == NULL || strSrc == NULL)
	{
		ret = -1;
		printf("func mystrcpy err :%d", ret);
		return ret;
	}
	char *p = strDest;
	while ((*p++ = *strSrc++) != '\0')
	{

	}
	return ret;
}
//3.strcat
int mystrcat(char *strDest, char *strSrc)
{
	int ret = 0;
	if (strDest == NULL || strSrc == NULL)
	{
		ret = -1;
		printf("func mystrcat err :%d", ret);
		return ret;
	}
	int len = strlen(strDest);
	char *p = strDest + len;
	while ((*p++ = *strSrc++) != '\0')
	{

	}
	return ret;
}
//4.strstr
int mystrstr(char *haystack, char *needle, int *index)
{
	int ret = 0;
	if (haystack == NULL || needle == NULL || index == NULL)
	{
		ret = -1;
		printf("func mystrstr err :%d", ret);
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

//5.strtok
int mystrtok(char *str1, const char *str2, char ***buf, int *num)
{
	int ret = 0;
	if (str1 == NULL || str2 == NULL || buf == NULL || num == NULL)
	{
		ret = -1;
		printf("func mystrtok err :%d", ret);
		return ret;
	}
	char *pCur = str1;
	char *pTemp = str1;
	int capacity = 2;
	char **result = (char **)malloc(capacity*sizeof(char*));
	int count = 0;
	while (*pCur != '\0')
	{
		pCur = strstr(pCur, str2);
		if (pCur != NULL)
		{
			int tempCount = pCur - pTemp;
			char *pStr = (char*)malloc((tempCount + 1)*sizeof(char));
			memcpy(pStr, pTemp, tempCount);
			pStr[tempCount] = '\0';
			pTemp = pCur = pCur + strlen(str2);
			if (count < capacity)
			{
				result[count] = pStr;
				count++;
			}
			else
			{
				capacity *= 2;
				char **pResult = (char **)malloc(capacity*sizeof(char*));
				for (int i = 0; i < capacity / 2; i++)
				{
					 pResult[i] = result[i];
				}
				free(result);
				result = pResult;
				result[count] = pStr;
				count++;
			}
		}
		else
		{
			break;
		}
	}
	if (pTemp != pCur)
	{
		int tempCount = strlen(pTemp);
		char *pStr = (char*)malloc((tempCount + 1)*sizeof(char));
		memcpy(pStr, pTemp, tempCount);
		pStr[tempCount] = '\0';
		if (count > capacity)
		{
			char **pResult = result;
			capacity *= 2;
			result = (char **)malloc(capacity*sizeof(char*));
			for (int i = 0; i < capacity / 2; i++)
			{
				result[i] = pResult[i];
			}
			result[count] = pStr;
			count++;
			free(pResult);
		}
		else
		{
			result[count] = pStr;
			count++;
		}
	}
	*buf = result;
	*num = count;
	return ret;
}
//6.内存释放
void freeChar(char **Arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (Arr[i] != NULL)
		{
			free(Arr[i]);
		}
	}
	free(Arr);
}

//7.strrev
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
void main()
{
	char *p = "abcdefg";
	int len = 0;
	mystrLen(p, &len);
	printf("字符串p的长度是:%d\n", len);
	char buf[20];
	mystrcpy(buf, p);
	printf("字符串拷贝的结果是:%s\n", buf);
	char buf2[20] = "12345";
	mystrcat(buf2, p);
	printf("字符串追加后的结果是:%s\n", buf2);
	int index = 0;
	mystrstr(buf2, p, &index);
	printf("字符串p在buf2中的位置是:%d\n", index);
	printf("str 字符串按照#分割后的结果是：\n");
	char str[] = "now # is the time for all # good men to come to the # aid of their country";
	char delims[] = "#";
	char **splitResut;
	int num = 0;
	mystrtok(str, delims, &splitResut, &num);
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", splitResut[i]);
	}
	freeChar(splitResut, num);
	reversalStr(buf);
	printf("buf翻转后的结果是:%s\n", buf);
	system("pause");
}