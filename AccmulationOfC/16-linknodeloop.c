#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}NodeList;
//��Ŀ:�ж����������Ƿ��л�
//˼·�����ÿ���ָ�룬������ָ�����׷������ָ��˵���л������û��׷����ָ��ѭ������˵��û�л���
int isLoop(NodeList *pHead, int *result)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func isLoop err:%d", ret);
		return ret;
	}
	NodeList *pFast = pHead->next;
	NodeList *pSlow = pHead->next;
	while (pFast != NULL)
	{
		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast != NULL)
		{
			pFast = pFast->next;
		}
		if (pFast == pSlow)
		{
			*result = 1;
			return ret;
		}
	}
	*result = 0;
	return ret;
}
//��Ŀ���ҵ�������ڵ�
int getLoopNode(NodeList *pHead, NodeList **result)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func isLoop err:%d", ret);
		return ret;
	}
	NodeList *pFast = pHead->next;
	NodeList *pSlow = pHead->next;
	while (pFast != NULL)
	{
		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast != NULL)
		{
			pFast = pFast->next;
		}
		if (pFast == pSlow)
		{
			NodeList *pStart = pHead->next;
			while (pStart !=pSlow)
			{
				pStart = pStart->next;
				pSlow = pSlow->next;
			}
			*result = pStart;
			return ret;
		}
	}
	*result = NULL;
	return ret;
}
void main()
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
	int result = -1;
	isLoop(list, &result);
	printf("%d\n", result);
	NodeList *node ;
	getLoopNode(list, &node);
	if (node !=NULL)
	{
		printf("%d\n", node->data);
	}
	else
	{
		printf("����û�л���\n");
	}
	//�ҵ����һ�������ֻһ����
	NodeList *pEnd = NULL;
	NodeList *pCur = list->next;
	while (pCur!=NULL)
	{
		pEnd = pCur;
		pCur = pCur->next;
	}
	pEnd->next = list->next->next->next;
	isLoop(list, &result);
	printf("%d\n", result);
	getLoopNode(list, &node);
	if (node != NULL)
	{
		printf("���Ľ����ǣ�%d\n", node->data);
	}
	system("pause");
}