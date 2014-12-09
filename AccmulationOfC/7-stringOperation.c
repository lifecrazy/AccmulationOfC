#include <stdio.h>
#include <stdlib.h>

//strlen�ַ����ַ�������ͳ�ơ�
//strcat�ַ���׷�ӡ�
//strcpy�ַ���������
//strstr�������ַ�����
//strtok�ַ�������ĳ���ַ��ָ
#pragma region 1.strlen
//1.strlen
//˼·������һ����ʱָ�����ַ����в��ң��ҵ�\0��Ϊ������
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
//˼·������һ��ָ��ָ��Ҫ�����ĵ�ַȻ�����ο���Ҫ�������ַ���ֱ��\0
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
//˼·���Ȼ�ȡ׷���ַ�����ĩβȻ����һ��ָ��ָ����ĩβȻ�����ο���Ҫ׷�ӵ��ַ���ֱ��\0Ϊֹ
//��strcpy���ֻ�ǿ����ַ�����㲻һ��
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
//˼·�����ǻ��ݷ�����haystack�����β���needle ����鵽�򷵻���haystack�е�index,���û���ҵ�������haystack�в��ҵ�ָ����ݵ���needle һ��ʼ���ҵ�λ�õ���һ���ַ�������ʼ��needleһ����ҡ�
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
//˼·��1.���ڲ�֪���ַ���str1�ᱻ�ָ�ɶ��ٸ����ַ�������ô��������������ָ�룬���ָ����ַ��������˷��������ָ�������ʱ���ͷ��������ĸ�����ָ�뽫֮ǰ����������ָ�뿽������Ȼ���ͷŵ�֮ǰ������ڴ�ռ䣬�������˼·������ȥ��
//      2.��������ָ��pCur��pTempָ��str1���׵�ַ����һ��ָ��pCurȥ���ҷָ���ַ����ҵ�֮�����pCur - pTemp+1���ڴ棬�����һ����Ϊ�˴��\0Ȼ�󽫸����ַ���������������ڴ�ռ����ٽ����ڴ�ռ�ҵ�֮ǰ���������ָ�뵱�С�
//      3.�����еķָ������ҵ�֮��ʣ�µ��ַ�����Ϊһ���ַ����鵥������һ��
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
//6.�ڴ��ͷ�
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
//˼·����������ָ��ֱ�ָ��ʼ�ͽ�β�����ν����˴˵�����ֱ����������Ϊֹ��
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
	printf("�ַ���p�ĳ�����:%d\n", len);
	char buf[20];
	mystrcpy(buf, p);
	printf("�ַ��������Ľ����:%s\n", buf);
	char buf2[20] = "12345";
	mystrcat(buf2, p);
	printf("�ַ���׷�Ӻ�Ľ����:%s\n", buf2);
	int index = 0;
	mystrstr(buf2, p, &index);
	printf("�ַ���p��buf2�е�λ����:%d\n", index);
	printf("str �ַ�������#�ָ��Ľ���ǣ�\n");
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
	printf("buf��ת��Ľ����:%s\n", buf);
	system("pause");
}