#include <stdio.h>
#include <stdlib.h>
//ɾ���ַ�����ͷ�ͽ������ַ�
//˼·����������ָ��ֱ�ָ���ַ����Ŀ�ͷ�ͽ�β��Ȼ��ֱ�ӿ�ͷ�ͽ�β��ʼ����ֱ��������һ���ǿո���ַ�λ��
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
//ɾ���ַ����ж���Ŀո�����ԭʼ�ַ�����     I     love             china            �����������ַ�����I love china����
//˼·��1.��������ָ��ֱ�ָ���ַ����Ŀ�ͷһ��pPre��������һ��pCur�����ַ���
//      2.��pCur���ǿո��ʱ��Ϳ�����pPre��Ȼ���������
//      3.�������ո��ʱ���ɾ�����еĿո�Ȼ���ж��ǲ����ַ����Ŀ�ʼ��flag ==0�����߽�β(*pCur == '\0'),������������һ���ո������޸ı��
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
	printf("ɾ���ַ���ǰ��Ŀո��:\n%s\n", result);
	char buf[] = "     I     love             you            ";
	deleteSpace(buf);
	printf("ɾ���ַ����ж���Ŀո��:\n%s\n", buf);
	system("pause");
}