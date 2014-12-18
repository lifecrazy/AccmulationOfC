#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}NodeList;

int reverseNodeList(NodeList *pHead)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func reverseNodeList err:%d", ret);
		return ret;
	}
	NodeList *pCur = pHead->next;//ָ��ǰ�Ľ��
	NodeList *pPre = NULL;//ָ��ǰһ����㣬��ָ�뷭ת�����һ���ڵ�
	while (pCur != NULL)
	{
		NodeList *pNext = pCur->next;//ָ��ǰ�ڵ����һ�����
		pCur->next = pPre;//����ǰ������һ���������Ϊǰһ����� ��ָ�뷭ת
		pPre = pCur;//ָ�뷭ת֮��ǰһ�����ǰ��
		if (pNext == NULL)//�ж���һ������Ƿ�Ϊ�գ����Ϊ��˵����ǰ���Ϊ���һ����㼴���ú�ĵ�һ�����
		{
			pHead->next = pCur;
			return ret;
		}
		pCur = pNext;//ָ�뷭ת֮��ǰ���ǰ��
	}
	return ret;
}
int reverseNodeListInGroup(NodeList *pHead, int k)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func reverseNodeListInGroup err:%d", ret);
		return ret;
	}
	NodeList *pCur = pHead->next;
	NodeList *pPre = NULL;
	NodeList *lasthead = pHead;//���Ҫ����ת�������ĵ�һ������ǰһ�����
	int index = 1;
	while (pCur != NULL)
	{
		NodeList *pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		if (index%k == 0 || pNext == NULL)
		{
			NodeList *pTemp = lasthead->next;//���Ҫ����ת�������ĵ�һ����㼴��ת������һ�����
			lasthead->next = pCur;//���÷�ת��������ĵ�һ�����
			lasthead = pTemp;//���Ҫ����ת�������ĵ�һ������ǰһ�����
			lasthead->next = pNext;//����ת���������ԭ��������ʣ��Ľ����������
		}
		pCur = pNext;
		index++;
	}
	return ret;
}
int reverseNodeListBetween(NodeList *pHead, int m, int n)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func reverseNodeList err:%d", ret);
		return ret;
	}
	int len = 0;
	sizeNodeList(pHead, &len);
	if (n > len)
	{
		ret = -2;
		printf("func reverseNodeList m:%d �Ƿ�  err:%d", m, ret);
		return ret;
	}
	NodeList *pCur = pHead->next;//ָ��ǰ�Ľ��
	NodeList *pPre = NULL;//ָ��ǰһ����㣬��ָ�뷭ת�����һ���ڵ�
	for (int i = 1; i < m; i++)
	{
		pPre = pCur;
		pCur = pCur->next;
	}
	NodeList *pStartPre = pPre;
	NodeList *pEnd = pCur;
	for (int i = 0; i < n - m + 1; i++)
	{
		NodeList *pNext = pCur->next;//ָ��ǰ�ڵ����һ�����
		pCur->next = pPre;//����ǰ������һ���������Ϊǰһ����� ��ָ�뷭ת
		pPre = pCur;//ָ�뷭ת֮��ǰһ�����ǰ��
		pCur = pNext;//ָ�뷭ת֮��ǰ���ǰ��
	}
	pStartPre->next = pPre;
	pEnd->next = pCur;
	return ret;
}
void main13()
{
	const int num = 10;
	int a[10];
	NodeList *list;
	creatNodeList(&list);

	srand(time(NULL));
	//�������10����
	for (int i = 0; i < num; i++)
	{
		a[i] = rand() & 30;
	}
	for (int i = 0; i < num; i++)
	{
		insertLastNodeList(list, a[i]);
	}
	printf("�����ͷ��βԪ���ǣ�\n");
	traverseNodeList(list);
	printf("\n");
	reverseNodeList(list);
	printf("����ת��Ľ���ǣ�\n");
	traverseNodeList(list);
	printf("\n");
	reverseNodeListInGroup(list, 3);
	printf("������3Ϊ��λ��ת��Ľ���ǣ�\n");
	traverseNodeList(list);
	printf("\n");
	reverseNodeListBetween(list, 2, 7);
	printf("��������ӵ�%d����㵽��%d������Ľ���ǣ�\n", 2, 7);
	traverseNodeList(list);
	printf("\n");
	system("pause");
}