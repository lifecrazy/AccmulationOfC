#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}NodeList;

#pragma region 1.����һ����ͷ��������
//1.����һ����ͷ��������
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
		printf("func creatNodeList pHead�ڴ����ʧ�� err:%d", ret);
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
//		printf("�ڴ����ʧ�� err:%d", ret);
//		return ret;
//	}
//	pHead->data = 0;
//	pHead->next = NULL;
//	
//	return pHead;
//}
#pragma endregion

#pragma region 2.ͳ�Ƶ�����ĳ���
//2.ͳ�ƴ�ͷ��㵥����ĳ���
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

#pragma region 3.�жϵ������Ƿ�Ϊ��
//3.�жϵ������Ƿ�Ϊ��
//���Ϊ���򷵻��棨1�����򷵻ؼ٣�0��
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

#pragma region 4.����������
//4.������ı���
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

#pragma region 5.���ص������е�pos������ֵ
//5.���ص������е�pos������ֵ
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
		printf("posֵ�Ƿ� err:%d", ret);
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
		printf("posֵ�Ƿ� err:%d", ret);
	}
	return ret;
}
#pragma endregion

#pragma region 6.�޸ĵ������е�pos������ֵ
//6.�޸ĵ������е�pos������ֵ
//�޸ĳɹ�����1�޸�ʧ�ܷ���0
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
		printf("posֵ�Ƿ� err:%d", ret);
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
		printf("posֵ�Ƿ� err:%d", ret);
	}
	return ret;
}
#pragma endregion

#pragma region 7.������ı�ͷ����Ԫ�ؼ�ͷ�巨
//7.������ı�ͷ����Ԫ�ؼ�ͷ�巨
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
		printf("�ڴ����ʧ�� err:%d", ret);
		return ret;
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->next = pHead->next;
	pHead->next = newNode;
	return ret;
}
#pragma endregion

#pragma region 8.�������ĩβ����һ��Ԫ�ؼ�β�
//8.�������ĩβ����һ��Ԫ�ؼ�β�
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
		printf("�ڴ����ʧ�� err:%d", ret);
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

#pragma region 9.������ĵ�pos��λ�ò���Ԫ��
//9.������ĵ�pos��λ�ò���Ԫ��
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
		printf("posֵ�Ƿ� err:%d", ret);
		return ret;
	}
	//���ҵ�pos�����
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
		printf("�ڴ����ʧ�� err:%d", ret);
		return ret;
	}
	newNode->data = x;
	//���½����ڱ�ͷ
	if (pPre == NULL)
	{
		newNode->next = pCur;
		pHead->next = newNode;
	}//���½�����pPre �� pCur֮��
	else
	{
		newNode->next = pCur;
		pPre->next = newNode;
	}
	return ret;
}
#pragma endregion

#pragma region 10.�����������в���Ԫ��Ϊx�Ľ�㣬ʹ�ò������Ȼ����
//10.�����������в���Ԫ��Ϊx�Ľ�㣬ʹ�ò������Ȼ����
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
		printf("�ڴ����ʧ�� err:%d", ret);
		return ret;
	}
	newNode->data = x;
	NodeList *pCur = pHead->next;
	NodeList *pPre = NULL;
	//���½������ͷ
	if (pCur == NULL || x < pCur->data)
	{
		newNode->next = pCur;
		pHead->next = newNode;
		return ret;
	}
	//˳���ҵ�xҪ�����λ��
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
	//���½�����pPre �� pCur֮��
	newNode->next = pCur;
	pPre->next = newNode;
	return ret;
}
#pragma endregion

#pragma region 11.ɾ���������е�pos����㲢��������ֵ
//11.ɾ���������е�pos����㲢��������ֵ
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
		printf("posֵ�Ƿ����ߵ�����Ϊ�� err:%d", ret);
		return ret;
	}
	//���ҵ�pos�����
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
		printf("posֵ�Ƿ� err:%d", ret);
		return ret;
	}
	//pPre == NULL ���� pos == 1 ����ɾ����һ�����
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

#pragma region 12.ɾ����������Ԫ��ΪX�ĵ�һ�����
//12.ɾ����������Ԫ��ΪX�ĵ�һ�����
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
		printf("��Ԫ�ز����ڡ�\n");
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

#pragma region 13.��յ�����
//13.��յ�����
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
	printf("�жϴ����ĵ������Ƿ�Ϊ��(1Ϊ��0�ǿ�)��\n");
	int isNULLResult = 0;
	emptyNodeList(list, &isNULLResult);
	printf("�жϵĽ����:%d", isNULLResult);
	printf("\n");
	srand(time(NULL));
	//�������10����
	for (int i = 0; i < num; i++)
	{
		a[i] = rand() & 30;
	}
	printf("�������\n");
	//ͷ�巨��������
	for (int i = 0; i < num; i++)
	{
		printf("%d    ", a[i]);
	}
	printf("\n�����������飺\n");
	for (int i = 0; i < num; i++)
	{
		insertFirstNodeList(list, a[i]);
	}
	//�������
	traverseNodeList(list);
	printf("\n");
	printf("�жϴ����ĵ������Ƿ�Ϊ��(1Ϊ��0�ǿ�)��\n");
	emptyNodeList(list, &isNULLResult);
	printf("�жϵĽ����:%d", isNULLResult);
	printf("\n");
	int count = 0;
	sizeNodeList(list, &count);
	printf("������:%d", count);
	printf("\n");
	int pos = 5;
	int posValue = 0;
	getNodeList(list, pos, &posValue);
	printf("����ĵ�%d��Ԫ��Ϊ��%d\n", pos, posValue);
	posValue = 100;
	updateNodeList(list, pos, posValue);
	printf("�޸�����ĵ�%d��Ԫ��Ϊ��%d\n", pos, posValue);
	printf("�޸ĺ�\n");
	traverseNodeList(list);
	printf("\n");
	for (NodeList *p = list->next; p != NULL; p = p->next)
	{
		while (!deleteValueNodeList(p, p->data))
		{

		}
	}
	printf("\nȥ���ظ���\n");
	traverseNodeList(list);
	printf("\n");
	sizeNodeList(list, &count);
	printf("������:%d", count);
	printf("\n");
	NodeList *newlist;
	creatNodeList(&newlist);
	for (NodeList *p = list->next; p != NULL; p = p->next)
	{
		insertOrderNodeList(newlist, p->data);
	}
	destroyNodeList(list);
	//�������
	traverseNodeList(newlist);
	printf("\n");
	pos = 2;
	posValue = 200;
	printf("������ĵ�%d��Ԫ��Ϊ��%d\n", pos, posValue);
	insertPosNodeList(newlist, pos, posValue);
	traverseNodeList(newlist);
	printf("\n");
	printf("ɾ������ĵ�%d��Ԫ��Ϊ��%d\n", pos, posValue);
	deletePosNodeList(newlist, pos, &posValue);
	traverseNodeList(newlist);
	printf("\n");
	printf("ɾ����Ԫ��Ϊ��%d\n", posValue);
	posValue = 23;
	printf("�����������в���Ԫ�أ�%d\n", posValue);
	insertOrderNodeList(newlist, posValue);
	traverseNodeList(newlist);
	printf("\n");
	printf("ɾ����������ֵΪ��%d��Ԫ��\n", posValue);
	deleteValueNodeList(newlist, posValue);
	traverseNodeList(newlist);
	printf("\n");
	destroyNodeList(newlist);
	system("pause");
}