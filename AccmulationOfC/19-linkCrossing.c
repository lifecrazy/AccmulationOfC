#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}NodeList;

//Ѱ�ҵ�����K�����
//˼·����������ָ�� ����һ��ָ������k����㣬Ȼ������ָ��һ���ߣ��������K������ָ���ߵ��������ô��һ��ָ��ָ��Ľ�㼴Ϊ������K����㡣�����k�ĳ��ȳ���������ĳ�������k������ĳ���ȡ������
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
//�ж����������Ƿ��ཻ������ཻ��result 1 ����result 0��
//˼·1���ж�������������һ������Ƿ���ͬ�������ͬ�����������ཻ
//       �����������ĳ���len1,len2���ó��Ƚϳ�������ӵڣ�|len1-len2|������㿪ʼ��ͬ����������ͬ�Ľ���ί��һ���ཻ�Ľ��
//˼·2��������һ����������һ������nextָ��ָ����һ�������ͷ�������µ����������µ���������л���˵���ཻ�������뽻�����㼴Ϊ������ڵ�
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
	if (p1 == NULL)//�������1Ϊ����϶�û�н��㷵�ؽ��ͬʱ���ཻ�������Ϊ��
	{
		*result = 0;
		*crossingNode = NULL;
		return ret;
	}
	if (p2 == NULL)//�������2Ϊ����϶�û�н��㷵�ؽ��ͬʱ���ཻ�������Ϊ��
	{
		*result = 0;
		*crossingNode = NULL;
		return ret;
	}
	//��������1��2�ֱ��ҵ����һ�����
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
	if (p1 != p2)//������һ����㲻��ͬ���뽻
	{
		*result = 0;
		*crossingNode = NULL;
		return ret;
	}
	//�����������Ĳ�ֵ ������p1��p2;���ú�p1�����Ƚϳ����Ǹ�����p2������Խ϶̵�����
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
	//Ѱ����ͬ�Ľ��
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
	//�������10����
	for (int i = 0; i < num; i++)
	{
		a[i] = rand() & 30;
	}
	for (int i = 0; i < num; i++)
	{
		insertLastNodeList(list, a[i]);
	}
	printf("����1��ͷ��βԪ���ǣ�\n");
	traverseNodeList(list);
	NodeList *node;
	int k = 3;
	getKthNodeBack(list, k, &node);
	printf("\n����1������%d������ǣ�%d   ��\n",k,node->data);
	//�����ڶ�������
	const int num1 = 15;
	int a1[15];
	NodeList *list1;
	creatNodeList(&list1);

	srand(time(NULL));
	//�������10����
	for (int i = 0; i < num1; i++)
	{
		a1[i] = rand() & 30;
	}
	for (int i = 0; i < num1; i++)
	{
		insertLastNodeList(list1, a1[i]);
	}
	printf("����2��ͷ��βԪ���ǣ�\n");
	traverseNodeList(list1);
	int result = -1;
	NodeList *crossingNode;
	getCrossingNode(list, list1, &result, &crossingNode);
	printf("\n����1������2�Ƿ��ཻ��%d.\n",result);
	if (crossingNode != NULL)
	{
		printf("\n����1������2�����ǣ�%d.\n", crossingNode->data);
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
	//����һ������
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
	printf("\n�������ཻ֮������1������2�Ƿ��ཻ��%d.\n", result);
	if (crossingNode!=NULL)
	{
		printf("\n����1������2�����ǣ�%d.\n", crossingNode->data);
	}
	system("pause");
}