#include <stdio.h>
#include <stdlib.h>

//strlen字符串字符个数的统计。
//strcat字符串追加。
//strcpy字符串拷贝。
//strstr查找子字符串。
//strtok字符串按照某个字符分割。
#pragma region 1.strlen
//1.strlen
//思路：定义一个临时指针在字符串中查找，找到\0即为结束。
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
#pragma endregion

#pragma region 2.strcpy
//2.strcpy
//思路：定义一个指针指向要拷贝的地址然后依次拷贝要拷贝的字符串直到\0
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
#pragma endregion


#pragma region 3.strcat
//3.strcat
//思路：先获取追加字符串的末尾然后定义一个指针指向其末尾然后依次拷贝要追加的字符串直到\0为止
//与strcpy差不多只是拷贝字符的起点不一样
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
#pragma endregion


#pragma region 4.strstr
//4.strstr
//思路：就是回溯法，在haystack中依次查找needle 如果查到则返回在haystack中的index,如果没有找到则让在haystack中查找的指针回溯到和needle 一起开始查找的位置的下一个字符继续开始和needle一起查找。
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
#pragma endregion



#pragma region 5.strtok
//5.strtok
//思路：1.由于不知道字符串str1会被分割成多少个子字符串，那么先申请两个数组指针，当分割后的字符串超过了分配的数组指针的容量时，就翻倍申请四个数组指针将之前的两个数组指针拷贝过来然后释放掉之前申请的内存空间，按照这个思路依次下去。
//      2.定义两个指针pCur，pTemp指向str1的首地址，让一个指针pCur去查找分割的字符，找到之后分配pCur - pTemp+1个内存，多分配一个是为了存放\0然后将该子字符串拷贝到申请的内存空间中再将该内存空间挂到之前申请的数组指针当中。
//      3.当所有的分隔符都找到之后还剩下的字符串作为一个字符数组单独处理一下
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
#pragma endregion



#pragma region 7.strrev
//7.strrev
//思路：定义两个指针分别指向开始和结尾，依次交换彼此的内容直到两者相遇为止。
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
#pragma endregion




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