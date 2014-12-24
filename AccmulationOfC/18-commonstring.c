#include "stdio.h"
#include "stdlib.h"

int getLongestCommon(char *str1, char *str2, char**result)
{
	int ret = 0;
	if (str1 == NULL || str2 == NULL || result == NULL)
	{
		ret = -1;
		printf("func getLongestCommon err %d", ret);
		return ret;
	}
	int lenStr1 = strlen(str1);
	int lenStr2 = strlen(str2);
	int maxLen = 0;
	int start = 0;
	int **flag = (int **)malloc(sizeof(int*) * lenStr1);
	for (int i = 0; i < lenStr1; i++)
	{
		flag[i] = (int *)malloc(sizeof(int) * lenStr2);
	}
	for (int i = 0; i < lenStr1; i++)
	{
		for (int j = 0; j < lenStr2; j++)
		{
			if (str1[i] == str2[j])
			{
				if (i == 0 || j == 0)
				{
					flag[i][j] = 1;
				}
				else
				{
					flag[i][j] = flag[i - 1][j - 1] + 1;
				}
			}
			else
			{
				flag[i][j] = 0;
			}
			if (flag[i][j] > maxLen)
			{
				maxLen = flag[i][j];
				start = j - maxLen + 1;
			}
		}
	}
	for (int i = 0; i < lenStr1; i++)
	{
		if (flag[i] != NULL)
		{
			free(flag[i]);
		}
	}
	free(flag);
	char *pTemp = (char*)malloc(sizeof(char)*(maxLen + 1));
	memcpy(pTemp, &str2[start], maxLen);
	*(pTemp + maxLen) = '\0';
	*result = pTemp;
	return ret;
}
int getLongestSubSequence(char *str1, char *str2, char**result)
{
	int ret = 0;
	if (str1 == NULL || str2 == NULL || result == NULL)
	{
		ret = -1;
		printf("func getLongestSubSequence err %d", ret);
		return ret;
	}
	int lenStr1 = strlen(str1);
	int lenStr2 = strlen(str2);
	int **flag = (int **)malloc(sizeof(int *) * (lenStr1 + 1));
	for (int i = 0; i < lenStr1 + 1; i++)
	{
		flag[i] = (int *)malloc(sizeof(int) *(lenStr2 + 1));
		memset(flag[i], 0, sizeof(int) *(lenStr2 + 1));
	}
	for (int i = 0; i <= lenStr1; i++)
	{
		for (int j = 0; j <= lenStr2; j++)
		{
			if (i == 0 || j == 0)
			{
				flag[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1])
			{

				flag[i][j] = flag[i - 1][j - 1] + 1;

			}
			else
			{
				flag[i][j] = flag[i - 1][j] > flag[i][j - 1] ? flag[i - 1][j] : flag[i][j - 1];
			}

		}
	}
	char *pTemp = (char*)malloc(sizeof(char)*(flag[lenStr1][lenStr2] + 1));
	char *pCur = pTemp;
	int n = lenStr1;
	int m = lenStr2;
	while (n > 0 && m > 0)
	{
		if (str1[n - 1] == str2[m - 1])
		{
			*pCur++ = str1[n - 1];
			n--;
			m--;
		}
		else
		{
			if (flag[n][m - 1] > flag[n - 1][m])
			{
				m--;
			}
			else
			{
				n--;
			}
		}
	}
	*pCur = '\0';
	char *p = pTemp;
	pCur--;
	while (p<pCur)
	{
		char c = *p;
		*p = *pCur;
		*pCur = c;
		p++;
		pCur--;
	}
	for (int i = 0; i < lenStr1; i++)
	{
		if (flag[i] != NULL)
		{
			free(flag[i]);
		}
	}
	free(flag);
	*result = pTemp;
	return ret;
}
void main()
{
	char *str1 = "abcdefghi";
	char *str2 = "afdadfdsfdsefghiafdadsfa";
	char *result = NULL;
	getLongestCommon(str1, str2, &result);
	printf("最长公共子串: %s\n", result);
	free(result);
	/*char *str3 = "abcdefghi";
	char *str4 = "mnaghbegyzk";*/
	char *str3 = "abcba";
	char *str4 = "bdca";
	getLongestSubSequence(str3, str4, &result);
	printf("最长公共子序列: %s\n", result);
	system("pause");
}