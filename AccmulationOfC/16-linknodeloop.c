#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}NodeList;
//题目:判断两个链表是否有环
//思路：设置快慢指针，如果快的指针可以追上慢的指针说明有环，如果没有追上慢指针循环结束说明没有环。
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
//题目：找到环的入口点
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
	//随机产生10个数
	for (int i = 0; i < num; i++)
	{
		a[i] = rand() & 30;
	}

	for (int i = 0; i < num; i++)
	{
		insertLastNodeList(list, a[i]);
	}
	printf("链表从头到尾元素是：\n");
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
		printf("链表没有环：\n");
	}
	//找到最后一个结点这只一个环
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
		printf("环的交点是：%d\n", node->data);
	}
	system("pause");
}