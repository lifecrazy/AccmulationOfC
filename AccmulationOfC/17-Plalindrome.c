#include <stdio.h>
#include <stdlib.h>
//判断是否为回味字符串(如果是则result 返回1否则返回0)
//例子："abccba"     "a b    cc       b     a"
//      "abcdcba"    "abc           dc ba    "
int isPlalindrome(char *str, int *result)
{
	int ret = 0;
	if (str == NULL || result == NULL)
	{
		ret = -1;
		printf("func isPlalindrome err %d", ret);
		return ret;
	}
	char *pStart = str;
	char *pEnd = str + strlen(str);
	while (pStart <= pEnd)
	{
		if (!((*pStart >= 'a'&&*pStart <= 'z') || (*pStart >= 'A'&&*pStart <= 'Z') || (*pStart >= '0'&&*pStart <= '9')))
		{
			pStart++;
		}
		else if (!((*pEnd >= 'a'&&*pEnd <= 'z') || (*pEnd >= 'A'&&*pEnd <= 'Z') || (*pEnd >= '0'&&*pEnd <= '9')))
		{
			pEnd--;
		}
		//else if (*pEnd == *pStart || ((*pStart >= 'a'&&*pStart <= 'z') && (*pStart - 32) == *pEnd) || ((*pStart >= 'A'&&*pStart <= 'Z') && (*pStart + 32) == *pEnd))
		else if (*pEnd == *pStart || ((*pStart - 32) == *pEnd) || ((*pStart + 32) == *pEnd))
		{
			pStart++;
			pEnd--;
		}
		else
		{
			*result = 0;
			return ret;
		}
	}
	*result = 1;
	return ret;
}
//寻找字符串中最长回文子序列
//指针写法
int getLongestPlalindromeFirst(char *str, char **result)
{
	int ret = 0;
	if (str == NULL || result == NULL)
	{
		ret = -1;
		printf("func getLongestPlalindrome err %d", ret);
		return ret;
	}
	char *pCur = str;
	char *pLeft = pCur;
	char *pRight = pCur;
	int curLen = 0;
	int maxLen = 1;
	char *pStartIndex = NULL;
	while (*pCur != '\0')
	{
		//寻找aba
		pLeft = pCur;
		pRight = pCur;
		while (pLeft != str && *pRight != '\0')
		{
			if (*pLeft == *pRight)
			{
				curLen++;
				pLeft--;
				pRight++;
			}
			else
			{
				break;
			}
		}
		if (maxLen < curLen)
		{
			pStartIndex = pLeft + 1;
			maxLen = pRight - (pLeft + 1);
		}
		curLen = 0;
		//寻找aba
		pLeft = pCur;
		pRight = pCur + 1;
		while (pLeft != str && *pRight != '\0')
		{
			if (*pRight != '\0'&&*pLeft == *pRight)
			{
				curLen++;
				pLeft--;
				pRight++;
			}
			else
			{
				break;
			}
		}
		if (maxLen < curLen)
		{
			pStartIndex = pLeft + 1;
			maxLen = pRight - (pLeft + 1);
		}
		curLen = 0;
		pCur++;
	}
	char *pTemp = (char*)malloc(sizeof(char)*(maxLen + 1));
	memcpy(pTemp, pStartIndex, maxLen);
	*(pTemp + maxLen) = '\0';
	*result = pTemp;
	return ret;
}
int getExpandCenter(char *str, char **left, char**right)
{
	int ret = 0;
	if (str == NULL || left == NULL || right == NULL)
	{
		ret = -1;
		printf("func getExpandCenter err %d", ret);
		return ret;
	}
	char *pLeft = *left;
	char *pRight = *right;
	while (pLeft != str && *pRight != '\0')
	{
		if (*pLeft == *pRight)
		{
			pLeft--;
			pRight++;
		}
		else
		{
			break;
		}
	}
	*left = pLeft;
	*right = pRight;
	return ret;
}
int getLongestPlalindrome(char *str, char **result)
{
	int ret = 0;
	if (str == NULL || result == NULL)
	{
		ret = -1;
		printf("func getLongestPlalindrome err %d", ret);
		return ret;
	}
	char *pCur = str;
	char *pLeft = pCur;
	char *pRight = pCur;
	int curLen = 0;
	int maxLen = 1;
	char *pStartIndex = NULL;
	while (*pCur != '\0')
	{
		//寻找aba
		pLeft = pCur;
		pRight = pCur;
		getExpandCenter(str, &pLeft, &pRight);
		curLen = pRight - pLeft;
		if (maxLen < curLen)
		{
			pStartIndex = pLeft + 1;
			maxLen = pRight - (pLeft + 1);
		}
		curLen = 0;
		//寻找aba
		pLeft = pCur;
		pRight = pCur + 1;
		getExpandCenter(str, &pLeft, &pRight);
		curLen = pRight - pLeft;
		if (maxLen < curLen)
		{
			pStartIndex = pLeft + 1;
			maxLen = pRight - (pLeft + 1);
		}
		curLen = 0;
		pCur++;
	}
	char *pTemp = (char*)malloc(sizeof(char)*(maxLen + 1));
	memcpy(pTemp, pStartIndex, maxLen);
	*(pTemp + maxLen) = '\0';
	*result = pTemp;
	return ret;
}
int getExpandCentersec(char *str, int *left, int *right)
{
	int ret = 0;
	if (str == NULL || left == NULL || right == NULL)
	{
		ret = -1;
		printf("func getExpandCentersec err %d", ret);
		return ret;
	}
	int iLeft = *left;
	int iRight = *right;
	while (iLeft >= 0 && iRight < strlen(str))
	{
		if (str[iLeft] == str[iRight])
		{
			iLeft--;
			iRight++;
		}
		else
		{
			break;
		}
	}
	*left = iLeft;
	*right = iRight;
	return ret;
}
int getLongestPlalindromesecsec(char *str, char **result)
{
	int ret = 0;
	if (str == NULL || result == NULL)
	{
		ret = -1;
		printf("func getLongestPlalindromesecsec err %d", ret);
		return ret;
	}
	int strLen = strlen(str);
	int maxLen = 0;
	int curLen = 0;
	int startIndex = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i < strLen; i++)
	{
		//寻找aba
		left = i;
		right = i;
		getExpandCentersec(str, &left, &right);
		curLen = right - left;
		if (maxLen < curLen)
		{
			startIndex = left + 1;
			maxLen = right - (left + 1);
		}
		curLen = 0;
		//寻找abba
		left = i;
		right = i + 1;
		getExpandCentersec(str, &left, &right);
		curLen = right - left;
		if (maxLen < curLen)
		{
			startIndex = left + 1;
			maxLen = right - (left + 1);
		}
		curLen = 0;
	}
	char *pTemp = (char*)malloc(sizeof(char)*(maxLen + 1));
	memcpy(pTemp, &str[startIndex], maxLen);
	*(pTemp + maxLen) = '\0';
	*result = pTemp;
	return ret;
}
//方法一：下标写法
int getLongestPlalindromeSec(const char *str, char **result)
{
	int ret = 0;
	if (str == NULL || result == NULL)
	{
		ret = -1;
		printf("func getLongestPlalindrome err %d", ret);
		return ret;
	}
	int strLen = strlen(str);
	int maxLen = 0;
	int curLen = 0;
	int startIndex = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i < strLen; i++)
	{
		//寻找aba
		left = i;
		right = i;
		while (left >= 0 && right < strLen)
		{
			if (str[left] == str[right])
			{
				curLen++;
				left--;
				right++;
			}
			else
			{
				break;
			}
		}
		if (maxLen < curLen)
		{
			startIndex = left + 1;
			maxLen = right - (left + 1);
		}
		curLen = 0;
		//寻找abba
		left = i;
		right = i + 1;
		while (left >= 0 && right < strLen)
		{
			if (right < strLen&&str[left] == str[right])
			{
				curLen++;
				left--;
				right++;
			}
			else
			{
				break;
			}
		}
		if (maxLen < curLen)
		{
			startIndex = left + 1;
			maxLen = right - (left + 1);
		}
		curLen = 0;
	}
	char *pTemp = (char*)malloc(sizeof(char)*(maxLen + 1));
	memcpy(pTemp, &str[startIndex], maxLen);
	*(pTemp + maxLen) = '\0';
	*result = pTemp;
	return ret;
}
void main17()
{
	char *str = "ab2     Bc      dcb 2bA    ";
	char *str1 = "a b    c       b     a";
	int result = -1;
	isPlalindrome(str, &result);
	printf("str的结果是：result :%d\n", result);
	isPlalindrome(str1, &result);
	printf("str1的结果是：result :%d\n", result);
	char *str2 = "qfeabcbaddd";
	char *str3 = "123456cabbacafsdfadf";
	char *p;
	getLongestPlalindromeFirst(str2, &p);
	printf("指针写法str2的结果是：p = :%s\n", p);
	free(p);
	getLongestPlalindromeSec(str3, &p);
	printf("下标写法str3的结果是：p = :%s\n", p);
	free(p);
	system("pause");
}