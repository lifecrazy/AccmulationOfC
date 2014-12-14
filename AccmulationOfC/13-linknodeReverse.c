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
	NodeList *pCur = pHead->next;
	NodeList *pPre = NULL;
	while (pCur != NULL)
	{
		NodeList *pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		if (pNext == NULL)
		{
			pHead->next = pCur;
			return ret;
		}
		pCur = pNext;
	}
	return ret;
}
int reverseNodeListInGroup(NodeList *pHead, int k)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func reverseNodeList err:%d", ret);
		return ret;
	}
	NodeList *pCur = pHead->next;
	NodeList *pPre = NULL;
	NodeList *lasthead = pHead;
	int index = 1;
	while (pCur != NULL)
	{
		NodeList *pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		if (index%k == 0||pNext == NULL)
		{
			NodeList *pTemp = lasthead->next;
			lasthead->next = pCur;
			lasthead = pTemp;
			lasthead->next = pNext;
		}
		pCur = pNext;
		index++;
	}
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
	printf("链表从头到尾元素是：\n");
	for (int i = 0; i < num; i++)
	{
		insertLastNodeList(list, a[i]);
	}
	traverseNodeList(list);
	printf("\n");
	reverseNodeList(list);
	printf("\n");
	traverseNodeList(list);
	printf("\n");
	reverseNodeListInGroup(list,3);
	printf("\n");
	traverseNodeList(list);
	system("pause");
}