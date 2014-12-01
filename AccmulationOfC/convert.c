/*
ʱ�䣺2014 - 11 - 27
���ߣ�
*/
#include <stdio.h>
#include <stdlib.h>

int ConvertTo2(int num, char* result)
{
	int ret = 0;
	if (result == NULL)//�жϴ���ĵ�ַ�Ƿ����
	{
		printf("ת��ʧ�ܣ�����");
		ret = -1;
		return ret;
	}
	char* p = result;
	//ÿ��ȥ���Ի������Ķ���������
	while (num != 0)
	{
		*p = num % 2 + '0';
		num = num / 2;
		p++;
	}
	*p = '\0';
	p--;
	char *q = result;
	while (p > q)//���������Ķ��������з�תΪ��ȷ�Ľ��
	{
		char temp = *q;
		*q = *p;
		*p = temp;
		p--;
		q++;
	}
	return ret;
}
int ConvertTo8(int num, char* result)
{
	int ret = 0;
	if (result == NULL)
	{
		printf("ת��ʧ�ܣ�����");
		ret = -1;
		return ret;
	}
	char* p = result;
	while (num != 0)
	{
		*p = num % 8 + '0';
		num = num / 8;
		p++;
	}
	*p = '\0';
	p--;
	char *q = result;
	while (p > q)
	{
		char temp = *q;
		*q = *p;
		*p = temp;
		p--;
		q++;
	}
	return ret;
}
int ConvertTo16(int num, char* result)
{
	int ret = 0;
	if (result == NULL)
	{
		printf("ת��ʧ�ܣ�����");
		ret = -1;
		return ret;
	}
	char* p = result;
	while (num != 0)
	{

		int temp = num % 16;
		if (temp >= 0 && temp < 10)
		{
			*p = temp + '0';
		}
		else if (temp == 10)
		{
			*p = 'A';
		}
		else if (temp == 11)
		{
			*p = 'B';
		}
		else if (temp == 12)
		{
			*p = 'C';
		}
		else if (temp == 13)
		{
			*p = 'D';
		}
		else if (temp == 14)
		{
			*p = 'E';
		}
		else
		{
			*p = 'F';
		}
		num = num / 16;
		p++;
	}
	*p = '\0';
	p--;
	char *q = result;
	while (p > q)
	{
		char temp = *q;
		*q = *p;
		*p = temp;
		p--;
		q++;
	}
	return ret;
}
int convertFrom2(char *num, int* result)
{
	int ret = 0;
	if (num == NULL || result == NULL)
	{
		ret = -1;
		printf("ת��ʧ�ܣ�");
		return ret;
	}
	char *p = num + strlen(num) - 1;
	int temp = 0;
	int base = 1;
	while (p >= num)
	{
		temp += (*p - '0')*base;
		base *= 2;
		p--;
	}
	*result = temp;
	return ret;
}
int convertFrom8(char *num, int* result)
{
	int ret = 0;
	if (num == NULL || result == NULL)
	{
		ret = -1;
		printf("ת��ʧ�ܣ�");
		return ret;
	}
	char *p = num + strlen(num) - 1;
	int temp = 0;
	int base = 1;
	while (p >= num)
	{
		temp += (*p - '0')*base;
		base *= 8;
		p--;
	}
	*result = temp;
	return ret;
}
int convertFrom16(char *num, int* result)
{
	int ret = 0;
	if (num == NULL || result == NULL)
	{
		ret = -1;
		printf("ת��ʧ�ܣ�");
		return ret;
	}
	char *p = num + strlen(num) - 1;
	int temp = 0;
	int base = 1;
	while (p >= num)
	{
		if (*p >= '0'&&*p <= '9')
		{
			temp += (*p - '0')*base;
		}
		else if (*p == 'A' || *p == 'a')
		{
			temp += 10 * base;
		}
		else if (*p == 'B' || *p == 'b')
		{
			temp += 11 * base;
		}
		else if (*p == 'C' || *p == 'c')
		{
			temp += 12 * base;
		}
		else if (*p == 'D' || *p == 'd')
		{
			temp += 13 * base;
		}
		else if (*p == 'E' || *p == 'e')
		{
			temp += 14 * base;
		}
		else
		{
			temp += 15 * base;
		}
		base *= 16;
		p--;
	}
	*result = temp;
	return ret;
}
void main()
{
	int num = 34;
	char buf2[20];
	char buf8[20];
	char buf16[20];
	ConvertTo2(num, buf2);
	ConvertTo8(num, buf8);
	ConvertTo16(num, buf16);
	printf("תת��Ķ�����:%s\n", buf2);
	printf("ת����İ˽���:%s\n", buf8);
	printf("ת�����ʮ������:%s\n", buf16);
	int result2 = 0;
	int result8 = 0;
	int result16 = 0;
	convertFrom2(buf2, &result2);
	convertFrom8(buf8, &result8);
	convertFrom16(buf16, &result16);
	printf("������ת��Ϊʮ����:%d\n", result2);
	printf("�˽���ת��Ϊʮ����:%d\n", result8);
	printf("ʮ������ת��Ϊʮ����:%d\n", result16);
	system("pause");
}