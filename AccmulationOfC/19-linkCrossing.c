#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}NodeList;

//寻找倒数第K个结点
//思路：定义两个指针 ，让一个指针先走k个结点，然后两个指针一起走，如果先走K个结点的指针走到了最后那么另一个指针指向的结点即为倒数第K个结点。（如果k的长度超过了链表的长度则让k和链表的长度取余数）
int getKthNodeBack(NodeList *head, int k, NodeList **result)
{
	int ret = 0;
	if (head == NULL)
	{
		ret = -1;
		printf("func getKthNodeBack err:%d", ret);
		return ret;
	}
	int len = 0;
	NodeList *p = head->next;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	if (k < 0)
	{
		ret = -2;
		printf("func getKthNodeBack k:%d err:%d", k, ret);
		return ret;
	}
	if (k > len)
	{
		k = k%len;
	}
	p = head->next;
	NodeList *pResult = head->next;
	for (int i = 0; i < k; i++)
	{
		p = p->next;
	}
	while (p!=NULL)
	{
		p = p->next;
		pResult = pResult->next;
	}
	*result = pResult;
	return ret;
}
//判断两个链表是否相交（如果相交则result 1 否则result 0）
//思路1：判断两个链表的最后一个结点是否相同，如果相同则两个链表相交
//       获得两个链表的长度len1,len2，让长度较长的链表从第（|len1-len2|）个结点开始共同遍历遇到相同的结点纪委第一个相交的结点
//思路2：就是让一个链表的最后一个结点的next指针指向另一个链表的头结点组成新的链表，遍历新的链表，如果有环则说明相交，否则不想交，交点即为环的入口点
int getCrossingNode(NodeList *head1, NodeList *head2, int *result, NodeList **crossingNode)
{
	int ret = 0;
	if (head1 == NULL || head2 == NULL || result == NULL || crossingNode == NULL)
	{
		ret = -1;
		printf("func getCrossingNode err :%d", ret);
		return ret;
	}
	NodeList *p1 = head1->next;
	NodeList *p2 = head2->next;
	int len1 = 0;
	int len2 = 0;
	if (p1 == NULL)//如果链表1为空则肯定没有交点返回结果同时将相交结点设置为空
	{
		*result = 0;
		*crossingNode = NULL;
		return ret;
	}
	if (p2 == NULL)//如果链表2为空则肯定没有交点返回结果同时将相交结点设置为空
	{
		*result = 0;
		*crossingNode = NULL;
		return ret;
	}
	//遍历链表1和2分别找到最后一个结点
	while (p1->next != NULL)
	{
		p1 = p1->next;
		len1++;
	}
	while (p2->next != NULL)
	{
		p2 = p2->next;
		len2++;
	}
	if (p1 != p2)//如果最后一个结点不相同则不想交
	{
		*result = 0;
		*crossingNode = NULL;
		return ret;
	}
	//获得连个链表的差值 并重置p1和p2;重置后p1遍历比较长的那个链表p2遍历相对较短的链表
	int temp = len1 > len2 ? len1 - len2 : len2 - len1;
	if (len1 > len2)
	{
		p1 = head1->next;
		p2 = head2->next;
	}
	else
	{
		p1 = head2->next;
		p2 = head1->next;
	}
	//寻找相同的结点
	for (int i = 0; i < temp; i++)
	{
		p1 = p1->next;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	*result = 1;
	*crossingNode = p1;
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
	printf("链表1从头到尾元素是：\n");
	traverseNodeList(list);
	NodeList *node;
	int k = 3;
	getKthNodeBack(list, k, &node);
	printf("\n链表1倒数第%d个结点是：%d   。\n",k,node->data);
	//创建第二个链表
	const int num1 = 15;
	int a1[15];
	NodeList *list1;
	creatNodeList(&list1);

	srand(time(NULL));
	//随机产生10个数
	for (int i = 0; i < num1; i++)
	{
		a1[i] = rand() & 30;
	}
	for (int i = 0; i < num1; i++)
	{
		insertLastNodeList(list1, a1[i]);
	}
	printf("链表2从头到尾元素是：\n");
	traverseNodeList(list1);
	int result = -1;
	NodeList *crossingNode;
	getCrossingNode(list, list1, &result, &crossingNode);
	printf("\n链表1与链表2是否相交：%d.\n",result);
	if (crossingNode != NULL)
	{
		printf("\n链表1与链表2交点是：%d.\n", crossingNode->data);
	}
	NodeList node1 ;
	NodeList node2;
	NodeList node3;
	NodeList node4;
	NodeList node5;
	node1.data = 1000;
	node1.next = &node2;
	node2.data = 2000;
	node2.next = &node3;
	node3.data = 3000;
	node3.next = &node4;
	node4.data = 4000;
	node4.next = &node5;
	node5.data = 5000;
	node5.next = NULL;
	//设置一个交点
	NodeList *p1 = list;
	NodeList *p2 = list1;
	while (p1->next!=NULL)
	{
		p1 = p1->next;
	}
	while (p2->next != NULL)
	{
		p2 = p2->next;
	}
	p1->next = &node1;
	p2->next = &node3;
	getCrossingNode(list, list1, &result, &crossingNode);
	printf("\n设置完相交之后链表1与链表2是否相交：%d.\n", result);
	if (crossingNode!=NULL)
	{
		printf("\n链表1与链表2交点是：%d.\n", crossingNode->data);
	}
	system("pause");
}