#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}NodeList;

#pragma region 1.创建一个带头结点的链表
//1.创建一个带头结点的链表
int creatNodeList(NodeList **head)
{
	int ret = 0;
	if (head == NULL)
	{
		ret = -1;
		printf("func creatNodeList err:%d", ret);
		return ret;
	}
	NodeList *pHead = (NodeList *)malloc(sizeof(NodeList));
	if (pHead == NULL)
	{
		ret = -2;
		printf("func creatNodeList pHead内存分配失败 err:%d", ret);
		return ret;
	}
	pHead->data = 0;
	pHead->next = NULL;
	*head = pHead;
	return ret;
}
//NodeList *creatNodeList()
//{
//	int ret =0;
//	NodeList *pHead = (NodeList *)malloc(sizeof(NodeList));
//	if (pHead == NULL)
//	{
//		ret = -1;
//		printf("内存分配失败 err:%d", ret);
//		return ret;
//	}
//	pHead->data = 0;
//	pHead->next = NULL;
//	
//	return pHead;
//}
#pragma endregion

#pragma region 2.统计单链表的长度
//2.统计带头结点单链表的长度
int sizeNodeList(NodeList *pHead, int* count)
{
	int ret = 0;
	if (pHead == NULL || count == NULL)
	{
		ret = -1;
		printf("func sizeNodeList err:%d", ret);
		return ret;
	}
	int num = 0;
	NodeList *p = pHead->next;
	while (p != NULL)
	{
		num++;
		p = p->next;
	}
	*count = num;
	return ret;
}
#pragma endregion

#pragma region 3.判断单链表是否为空
//3.判断单链表是否为空
//如果为空则返回真（1）否则返回假（0）
int emptyNodeList(NodeList *pHead, int *result)
{

	int ret = 0;
	if (pHead == NULL || result == NULL)
	{
		ret = -1;
		printf("func emptyNodeList err:%d", ret);
		return ret;
	}
	if (pHead->next == NULL)
	{
		*result = 1;
	}
	else
	{
		*result = 0;
	}
	return ret;
}
#pragma endregion

#pragma region 4.遍历单链表
//4.单链表的遍历
int traverseNodeList(NodeList *pHead)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func traverseNodeList err:%d", ret);
		return ret;
	}
	NodeList *pCur = pHead->next;
	while (pCur != NULL)
	{
		printf("%d    ", pCur->data);
		pCur = pCur->next;
	}
	return ret;
}
#pragma endregion

#pragma region 5.返回单链表中第pos个结点的值
//5.返回单链表中第pos个结点的值
int getNodeList(NodeList *pHead, int pos, int* result)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func getNodeList err:%d", ret);
		return ret;
	}
	if (pos < 1)
	{
		ret = -2;
		printf("pos值非法 err:%d", ret);
		return ret;
	}
	int count = 0;
	NodeList *pCur = pHead->next;
	while (pCur != NULL)
	{
		count++;
		if (count == pos)
		{
			break;
		}
		else
		{
			pCur = pCur->next;
		}

	}
	if (pCur != NULL)
	{
		*result = pCur->data;
	}
	else
	{
		ret = -2;
		printf("pos值非法 err:%d", ret);
	}
	return ret;
}
#pragma endregion

#pragma region 6.修改单链表中第pos个结点的值
//6.修改单链表中第pos个结点的值
//修改成功返回1修改失败返回0
int updateNodeList(NodeList *pHead, int pos, int x)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func updateNodeList err:%d", ret);
		return ret;
	}
	if (pos < 1)
	{
		ret = -2;
		printf("pos值非法 err:%d", ret);
		return ret;
	}
	int count = 0;
	NodeList *pCur = pHead->next;
	while (pCur != NULL)
	{
		count++;
		if (count == pos)
		{
			break;
		}
		else
		{
			pCur = pCur->next;
		}
	}
	if (pCur != NULL)
	{
		pCur->data = x;

	}
	else
	{
		ret = -2;
		printf("pos值非法 err:%d", ret);
	}
	return ret;
}
#pragma endregion

#pragma region 7.向单链表的表头插入元素即头插法
//7.向单链表的表头插入元素即头插法
int insertFirstNodeList(NodeList *pHead, int x)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func insertFirstNodeList err:%d", ret);
		return ret;
	}
	NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
	if (newNode == NULL)
	{
		ret = -2;
		printf("内存分配失败 err:%d", ret);
		return ret;
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->next = pHead->next;
	pHead->next = newNode;
	return ret;
}
#pragma endregion

#pragma region 8.向单链表的末尾插入一个元素即尾差法
//8.向单链表的末尾插入一个元素即尾差法
int insertLastNodeList(NodeList *pHead, int x)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func insertLastNodeList err:%d", ret);
		return ret;
	}
	NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
	if (newNode == NULL)
	{
		ret = -2;
		printf("内存分配失败 err:%d", ret);
		return ret;
	}
	newNode->data = x;
	newNode->next = NULL;
	NodeList* p = pHead;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = newNode;
	return ret;
}
#pragma endregion

#pragma region 9.向单链表的第pos个位置插入元素
//9.向单链表的第pos个位置插入元素
int insertPosNodeList(NodeList *pHead, int pos, int x)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func insertPosNodeList err:%d", ret);
		return ret;
	}
	if (pos < 1)
	{
		ret = -2;
		printf("pos值非法 err:%d", ret);
		return ret;
	}
	//查找第pos个结点
	int count = 0;
	NodeList *pCur = pHead->next;
	NodeList *pPre = NULL;
	while (pCur != NULL)
	{
		count++;
		if (count == pos)
		{
			break;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
	if (newNode == NULL)
	{
		ret = -3;
		printf("内存分配失败 err:%d", ret);
		return ret;
	}
	newNode->data = x;
	//把新结点插在表头
	if (pPre == NULL)
	{
		newNode->next = pCur;
		pHead->next = newNode;
	}//把新结点插在pPre 和 pCur之间
	else
	{
		newNode->next = pCur;
		pPre->next = newNode;
	}
	return ret;
}
#pragma endregion

#pragma region 10.向有序单链表中插入元素为x的结点，使得插入后仍然有序
//10.向有序单链表中插入元素为x的结点，使得插入后仍然有序
int insertOrderNodeList(NodeList *pHead, int x)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func insertOrderNodeList err:%d", ret);
		return ret;
	}
	NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
	if (newNode == NULL)
	{
		ret = -2;
		printf("内存分配失败 err:%d", ret);
		return ret;
	}
	newNode->data = x;
	NodeList *pCur = pHead->next;
	NodeList *pPre = NULL;
	//把新结点插入表头
	if (pCur == NULL || x < pCur->data)
	{
		newNode->next = pCur;
		pHead->next = newNode;
		return ret;
	}
	//顺序找到x要插入的位置
	while (pCur != NULL)
	{
		if (x < pCur->data)
		{
			break;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	//把新结点插在pPre 和 pCur之间
	newNode->next = pCur;
	pPre->next = newNode;
	return ret;
}
#pragma endregion

#pragma region 11.删除单链表中第pos个结点并返回它的值
//11.删除单链表中第pos个结点并返回它的值
int deletePosNodeList(NodeList *pHead, int pos, int* result)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func deletePosNodeList err:%d", ret);
		return ret;
	}
	if (pos < 1 || pHead->next == NULL)
	{
		ret = -2;
		printf("pos值非法或者单链表为空 err:%d", ret);
		return ret;
	}
	//查找第pos个结点
	int count = 0;
	NodeList *pCur = pHead->next;
	NodeList *pPre = NULL;
	while (pCur != NULL)
	{
		count++;
		if (count == pos)
		{
			break;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	if (pCur == NULL)
	{
		ret = -3;
		printf("pos值非法 err:%d", ret);
		return ret;
	}
	//pPre == NULL 或者 pos == 1 都是删除第一个结点
	if (pPre == NULL)
	{
		pHead->next = pCur->next;
	}
	else
	{
		pPre->next = pCur->next;
	}
	*result = pCur->data;
	free(pCur);
	return ret;
}
#pragma endregion

#pragma region 12.删除单链表中元素为X的第一个结点
//12.删除单链表中元素为X的第一个结点
int deleteValueNodeList(NodeList *pHead, int x)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func deleteValueNodeList err:%d", ret);
		return ret;
	}
	NodeList *pCur = pHead->next;
	NodeList *pPre = NULL;
	while (pCur != NULL)
	{
		if (pCur->data == x)
		{
			break;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	if (pCur == NULL)
	{
		ret = -2;
		printf("该元素不存在。\n");
		return ret;
	}
	if (pPre == NULL)
	{
		pHead->next = pCur->next;
	}
	else
	{
		pPre->next = pCur->next;
	}
	free(pCur);
	return ret;
}
#pragma endregion

#pragma region 13.清空单链表
//13.清空单链表
int destroyNodeList(NodeList *pHead)
{
	int ret = 0;
	if (pHead == NULL)
	{
		ret = -1;
		return ret;
	}
	NodeList *pCur = pHead->next;
	while (pCur != NULL)
	{
		NodeList *pTemp = pCur->next;
		free(pCur);
		pCur = pTemp;
	}
	return ret;
}
#pragma endregion

void main()
{
	const int num = 10;
	int a[10];
	NodeList *list;
	creatNodeList(&list);
	printf("判断创建的单链表是否为空(1为空0非空)：\n");
	int isNULLResult = 0;
	emptyNodeList(list, &isNULLResult);
	printf("判断的结果是:%d", isNULLResult);
	printf("\n");
	srand(time(NULL));
	//随机产生10个数
	for (int i = 0; i < num; i++)
	{
		a[i] = rand() & 30;
	}
	printf("随机数：\n");
	//头插法插入链表
	for (int i = 0; i < num; i++)
	{
		printf("%d    ", a[i]);
	}
	printf("\n逆序整个数组：\n");
	for (int i = 0; i < num; i++)
	{
		insertFirstNodeList(list, a[i]);
	}
	//链表遍历
	traverseNodeList(list);
	printf("\n");
	printf("判断创建的单链表是否为空(1为空0非空)：\n");
	emptyNodeList(list, &isNULLResult);
	printf("判断的结果是:%d", isNULLResult);
	printf("\n");
	int count = 0;
	sizeNodeList(list, &count);
	printf("链表长度:%d", count);
	printf("\n");
	int pos = 5;
	int posValue = 0;
	getNodeList(list, pos, &posValue);
	printf("链表的第%d个元素为：%d\n", pos, posValue);
	posValue = 100;
	updateNodeList(list, pos, posValue);
	printf("修改链表的第%d个元素为：%d\n", pos, posValue);
	printf("修改后：\n");
	traverseNodeList(list);
	printf("\n");
	for (NodeList *p = list->next; p != NULL; p = p->next)
	{
		while (!deleteValueNodeList(p, p->data))
		{

		}
	}
	printf("\n去除重复后：\n");
	traverseNodeList(list);
	printf("\n");
	sizeNodeList(list, &count);
	printf("链表长度:%d", count);
	printf("\n");
	NodeList *newlist;
	creatNodeList(&newlist);
	for (NodeList *p = list->next; p != NULL; p = p->next)
	{
		insertOrderNodeList(newlist, p->data);
	}
	destroyNodeList(list);
	//链表遍历
	traverseNodeList(newlist);
	printf("\n");
	pos = 2;
	posValue = 200;
	printf("向链表的第%d个元素为：%d\n", pos, posValue);
	insertPosNodeList(newlist, pos, posValue);
	traverseNodeList(newlist);
	printf("\n");
	printf("删除链表的第%d个元素为：%d\n", pos, posValue);
	deletePosNodeList(newlist, pos, &posValue);
	traverseNodeList(newlist);
	printf("\n");
	printf("删除的元素为：%d\n", posValue);
	posValue = 23;
	printf("向有序链表中插入元素：%d\n", posValue);
	insertOrderNodeList(newlist, posValue);
	traverseNodeList(newlist);
	printf("\n");
	printf("删除单链表中值为：%d的元素\n", posValue);
	deleteValueNodeList(newlist, posValue);
	traverseNodeList(newlist);
	printf("\n");
	destroyNodeList(newlist);
	system("pause");
}