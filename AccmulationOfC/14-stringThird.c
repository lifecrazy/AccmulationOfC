#include <stdio.h>
#include <stdlib.h>
//在原字符串上修改，然后得到结果（主调函数分配内存被调函数修改）
//完全不使用C语言库函数
//思路：找到要被替换的字符串(strSrc)然后比较被替换字符串(strSrc)和要替换的字符串(strDes)的长度，如果是被替换的字符串(strSrc)的长度大于要替换的字符串(strDes)则先替换字符串再将后边的字符串前移，否则先将后的字符串后移然后再替换要替换的字符串
int strReplace(char *str, const char *strSrc, const char *strDes)
{
	int ret = 0;
	if (str == NULL || strSrc == NULL || strDes == NULL)
	{
		ret = -1;
		printf("func strReplace err:%d", ret);
		return ret;
	}
	int lenSrc = strlen(strSrc);
	int lenDes = strlen(strDes);
	int lenStr = strlen(str);
	char *pStrCur = NULL;
	char *pSrcCur = NULL;
	char *pDesCur = NULL;
	pStrCur = str;
	while (*pStrCur != '\0')
	{
		int count = 0;
		pSrcCur = strSrc;
		while (*pSrcCur != '\0')
		{
			if (*pStrCur != *pSrcCur)
			{
				break;
			}
			else
			{
				count++;
				pStrCur++;
				pSrcCur++;
			}
		}
		if (count == lenSrc)//如果count 和lenSrc(被替换的字符串的长度)相等说明找到了被替换的字符串
		{
			char *pTemp = pStrCur;//记录当前找到的字符串的结尾位置
			pStrCur = pStrCur - count;//记录当前找到的字符串的开始位置
			pDesCur = strDes;
			if (lenSrc >= lenDes)//比较被替换字符串(strSrc)和要替换的字符串(strDes)的长度，如果是被替换的字符串(strSrc)的长度大于要替换的字符串(strDes)则先替换字符串再将后边的字符串前移，否则先将后的字符串后移然后再替换要替换的字符串
			{
				while (*pDesCur != '\0')
				{
					*pStrCur++ = *pDesCur++;
				}
				if (pTemp != pStrCur)//
				{
					char *p = pStrCur;
					while ((*p++ = *pTemp++) != '\0')
					{
					}
				}
			}
			else
			{
				char *p = pTemp + strlen(pTemp);
				char *pNext = pTemp + strlen(pTemp) + (lenDes - lenSrc);
				while (p != (pTemp - 1))
				{
					*pNext-- = *p--;
				}
				while (*pDesCur != '\0')
				{
					*pStrCur++ = *pDesCur++;
				}
			}
		}
		else
		{
			pStrCur++;
		}
	}
	return ret;
}
//在原字符串上修改，然后得到结果（主调函数分配内存被调函数修改）
//使用C语言库函数strstr进行查找
int strReplacestrstr(char *str, const char *strSrc, const char *strDes)
{
	int ret = 0;
	if (str == NULL || strSrc == NULL || strDes == NULL)
	{
		ret = -1;
		printf("func strReplacestrstr err:%d", ret);
		return ret;
	}
	int lenSrc = strlen(strSrc);
	int lenDes = strlen(strDes);
	int lenStr = strlen(str);
	char *pStrCur = NULL;
	char *pSrcCur = NULL;
	char *pDesCur = NULL;
	pStrCur = str;
	while (*pStrCur != '\0')
	{
		char *pTemp = strstr(pStrCur, strSrc);
		if (pTemp != NULL)//如果找到
		{
			pDesCur = strDes;
			pStrCur = pTemp;
			pTemp = pTemp + lenSrc;
			if (lenSrc >= lenDes)//
			{
				while (*pDesCur != '\0')
				{
					*pStrCur++ = *pDesCur++;
				}
				if (pTemp != pStrCur)//
				{
					char *p = pStrCur;
					while ((*p++ = *pTemp++) != '\0')
					{
					}
				}
			}
			else
			{
				char *p = pTemp + strlen(pTemp);
				char *pNext = pTemp + strlen(pTemp) + (lenDes - lenSrc);
				while (p != (pTemp - 1))
				{
					*pNext-- = *p--;
				}
				while (*pDesCur != '\0')
				{
					*pStrCur++ = *pDesCur++;
				}
			}
		}
		else
		{
			break;
		}
	}
	return ret;
}
//不修改原字符串，再申请内存空间返回结果（被调函数分配内存空间并返回结果）
int strReplaceSecond(const char *str, const char *strSrc, const char *strDes, char **result)
{
	int ret = 0;
	if (str == NULL || strSrc == NULL || strDes == NULL)
	{
		ret = -1;
		printf("func strReplaceSecond err:%d", ret);
		return ret;
	}
	int lenSrc = strlen(strSrc);
	int lenDes = strlen(strDes);
	int lenStr = strlen(str);
	int countSrc = 0;
	char *pStrCur = str;
	char *pSrcCur = NULL;
	char *pDesCur = NULL;
	//统计要被替换的字符串(strSrc)在原字符串(str)中的个数countSrc
	while (*pStrCur != '\0')
	{
		char *pTemp = strstr(pStrCur, strSrc);
		if (pTemp != NULL)//如果找到
		{
			pStrCur = pTemp + lenSrc;
			countSrc++;
		}
		else
		{
			break;
		}
	}
	//开辟新的内存
	char *pNewStr = (char *)malloc((lenSrc + (lenSrc > lenDes ? lenSrc - lenDes : lenDes - lenSrc)*countSrc + 1)*sizeof(char));
	pStrCur = str;
	char *pNewStrCur = pNewStr;
	while (*pStrCur != '\0')
	{
		char *pTemp = strstr(pStrCur, strSrc);
		if (pTemp != NULL)
		{
			int tempNum = pTemp - pStrCur;
			memcpy(pNewStrCur, pStrCur, tempNum);
			pNewStrCur += tempNum;
			pStrCur += tempNum;
			pStrCur += lenSrc;
			memcpy(pNewStrCur, strDes, lenDes);
			pNewStrCur += lenDes;
		}
		else
		{
			int tempNum = strlen(pStrCur);
			memcpy(pNewStrCur, pStrCur, tempNum);
			pNewStrCur += tempNum;
			break;
		}
	}
	*pNewStrCur = '\0';
	*result = pNewStr;
	return ret;
}
void main14()
{
	char buf[100] = "qweabcdefabcdef";
	char buf1[100] = "qweabcdefabcdef";
	char buf2[100] = "qweabcdefabcdef";
	char buf3[100] = "qweabcdefabcdef";
	char *src = "abc";
	char *des = "12";
	char *des1 = "1234";
	strReplace(buf, src, des);
	strReplace(buf1, src, des1);
	strReplacestrstr(buf2, src, des);
	strReplacestrstr(buf3, src, des1);
	printf("strReplace src的长度大于des的长度：%s\n", buf);
	printf("strReplace src的长度小于des的长度：%s\n", buf1);
	printf("strReplacestrstr src的长度大于des的长度：%s\n", buf2);
	printf("strReplacestrstr src的长度小于des的长度：%s\n", buf3);
	char *p = "qweabcdefabcdef";
	char *p2 = "qweabcdefabcdef";
	char *result = NULL;
	strReplaceSecond(p, src, des, &result);
	printf("strReplaceSecond src的长度大于des的长度：%s\n", result);
	strReplaceSecond(p2, src, des1, &result);
	printf("strReplaceSecond src的长度小于des的长度：%s\n", result);
	system("pause");
}
