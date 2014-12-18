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
	NodeList *pCur = pHead->next;//指向当前的结点
	NodeList *pPre = NULL;//指向前一个结点，即指针翻转后的下一个节点
	while (pCur != NULL)
	{
		NodeList *pNext = pCur->next;//指向当前节点的下一个结点
		pCur->next = pPre;//将当前结点的下一个结点设置为前一个结点 即指针翻转
		pPre = pCur;//指针翻转之后前一个结点前移
		if (pNext == NULL)//判断下一个结点是否为空，如果为空说明当前结点为最后一个结点即逆置后的第一个结点
		{
			pHead->next = pCur;
			return ret;
		}
		pCur = pNext;//指针翻转之后当前结点前移
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
	NodeList *lasthead = pHead;//标记要被反转的子链的第一个结点的前一个结点
	int index = 1;
	while (pCur != NULL)
	{
		NodeList *pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		if (index%k == 0 || pNext == NULL)
		{
			NodeList *pTemp = lasthead->next;//标记要被反转的子链的第一个结点即翻转后的最后一个结点
			lasthead->next = pCur;//设置翻转后的子链的第一个结点
			lasthead = pTemp;//标记要被反转的子链的第一个结点的前一个结点
			lasthead->next = pNext;//将翻转后的子链和原来的链表剩余的结点链接起来
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
		printf("func reverseNodeList m:%d 非法  err:%d", m, ret);
		return ret;
	}
	NodeList *pCur = pHead->next;//指向当前的结点
	NodeList *pPre = NULL;//指向前一个结点，即指针翻转后的下一个节点
	for (int i = 1; i < m; i++)
	{
		pPre = pCur;
		pCur = pCur->next;
	}
	NodeList *pStartPre = pPre;
	NodeList *pEnd = pCur;
	for (int i = 0; i < n - m + 1; i++)
	{
		NodeList *pNext = pCur->next;//指向当前节点的下一个结点
		pCur->next = pPre;//将当前结点的下一个结点设置为前一个结点 即指针翻转
		pPre = pCur;//指针翻转之后前一个结点前移
		pCur = pNext;//指针翻转之后当前结点前移
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
	reverseNodeList(list);
	printf("链表翻转后的结果是：\n");
	traverseNodeList(list);
	printf("\n");
	reverseNodeListInGroup(list, 3);
	printf("链表以3为单位翻转后的结果是：\n");
	traverseNodeList(list);
	printf("\n");
	reverseNodeListBetween(list, 2, 7);
	printf("逆置链表从第%d个结点到第%d个结点后的结果是：\n", 2, 7);
	traverseNodeList(list);
	printf("\n");
	system("pause");
}