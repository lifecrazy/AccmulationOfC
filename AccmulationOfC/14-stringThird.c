#include <stdio.h>
#include <stdlib.h>
//��ԭ�ַ������޸ģ�Ȼ��õ�������������������ڴ汻�������޸ģ�
//��ȫ��ʹ��C���Կ⺯��
//˼·���ҵ�Ҫ���滻���ַ���(strSrc)Ȼ��Ƚϱ��滻�ַ���(strSrc)��Ҫ�滻���ַ���(strDes)�ĳ��ȣ�����Ǳ��滻���ַ���(strSrc)�ĳ��ȴ���Ҫ�滻���ַ���(strDes)�����滻�ַ����ٽ���ߵ��ַ���ǰ�ƣ������Ƚ�����ַ�������Ȼ�����滻Ҫ�滻���ַ���
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
		if (count == lenSrc)//���count ��lenSrc(���滻���ַ����ĳ���)���˵���ҵ��˱��滻���ַ���
		{
			char *pTemp = pStrCur;//��¼��ǰ�ҵ����ַ����Ľ�βλ��
			pStrCur = pStrCur - count;//��¼��ǰ�ҵ����ַ����Ŀ�ʼλ��
			pDesCur = strDes;
			if (lenSrc >= lenDes)//�Ƚϱ��滻�ַ���(strSrc)��Ҫ�滻���ַ���(strDes)�ĳ��ȣ�����Ǳ��滻���ַ���(strSrc)�ĳ��ȴ���Ҫ�滻���ַ���(strDes)�����滻�ַ����ٽ���ߵ��ַ���ǰ�ƣ������Ƚ�����ַ�������Ȼ�����滻Ҫ�滻���ַ���
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
//��ԭ�ַ������޸ģ�Ȼ��õ�������������������ڴ汻�������޸ģ�
//ʹ��C���Կ⺯��strstr���в���
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
		if (pTemp != NULL)//����ҵ�
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
//���޸�ԭ�ַ������������ڴ�ռ䷵�ؽ�����������������ڴ�ռ䲢���ؽ����
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
	//ͳ��Ҫ���滻���ַ���(strSrc)��ԭ�ַ���(str)�еĸ���countSrc
	while (*pStrCur != '\0')
	{
		char *pTemp = strstr(pStrCur, strSrc);
		if (pTemp != NULL)//����ҵ�
		{
			pStrCur = pTemp + lenSrc;
			countSrc++;
		}
		else
		{
			break;
		}
	}
	//�����µ��ڴ�
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
	printf("strReplace src�ĳ��ȴ���des�ĳ��ȣ�%s\n", buf);
	printf("strReplace src�ĳ���С��des�ĳ��ȣ�%s\n", buf1);
	printf("strReplacestrstr src�ĳ��ȴ���des�ĳ��ȣ�%s\n", buf2);
	printf("strReplacestrstr src�ĳ���С��des�ĳ��ȣ�%s\n", buf3);
	char *p = "qweabcdefabcdef";
	char *p2 = "qweabcdefabcdef";
	char *result = NULL;
	strReplaceSecond(p, src, des, &result);
	printf("strReplaceSecond src�ĳ��ȴ���des�ĳ��ȣ�%s\n", result);
	strReplaceSecond(p2, src, des1, &result);
	printf("strReplaceSecond src�ĳ���С��des�ĳ��ȣ�%s\n", result);
	system("pause");
}
