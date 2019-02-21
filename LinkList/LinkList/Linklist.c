#include "Linklist.h"
void InitLinkList(pList * pplist)
{
	assert(pplist);
	*pplist = NULL;
}
pNode BuyNode(DataType data)
{
	pNode newNode=(pNode)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		perror("BuyNode::malloc");
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void PopBack(pList* pplist)
{
	assert(pplist);
	pNode Pre = NULL;
	pNode Del = *pplist;
	if (NULL == *pplist)
	{
		return;
	}
	else
	{
		while (Del->next)
		{
			Pre = Del;
			Del = Del->next;
		}
		Pre->next = NULL;
		free(Del);
		
	}
}
void PushFront(pList* pplist, DataType data)
{
	assert(pplist);
	pNode pNewNode = BuyNode(data);
	if (NULL == *pplist)
	{
		*pplist = pNewNode;
		return;
	}
	else
	{
		pNewNode->next = *pplist;
		*pplist = pNewNode;
		return;
	}
}
void PopFront(pList* pplist)
{
	assert(pplist);
	pNode cur = *pplist;
	if (NULL == *pplist)
	{
		return;
	}
	else
	{
		*pplist = (*pplist)->next;
	}
	free(cur);
	cur = NULL;
}
void PushBack(pList* pplist, DataType data)
{
	pNode newNode = BuyNode(data);
	pNode cur = *pplist;
	assert(pplist);
	if (newNode == NULL)
	{
		return;
	}
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
void PrintLinklist(pList plist)
{
	pNode cur = plist;
	while (cur!=NULL)
	{
		printf("%d->", cur -> data);
		cur  = cur -> next;
	}
	printf("over\n");
}
void DestroyLinklist(pList *pplist)
{
	pNode cur = *pplist;
	pNode del = NULL;
	assert(pplist);
	while (cur!=NULL)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;

}
void ReverseLinklist1(pList *pplist)
{
	pNode pre = NULL;
	pNode cur = *pplist;
	pNode curNext = NULL;
	assert(pplist);
	while (cur)
	{
		curNext = cur->next;
		cur->next = pre;
		pre = cur;
		cur = curNext;
	}
	*pplist = pre;
}
void ReverseLinklistOP(pList *pplist)
{
	pNode NewHead = NULL;
	pNode cur = *pplist;
	pNode curNext = NULL;
	assert(pplist);
	while (cur)
	{
		curNext = cur->next;
		cur->next = NewHead;
		NewHead=cur;
		cur = curNext;
	}
	*pplist = NewHead;
}
void MergeLinklist(pList *pplist1, pList *pplist2)
{
	pNode NewHead = NULL;
	pNode pTail = NULL;
	pNode pL1 = *pplist1;
	pNode pL2 = *pplist2;
	if (pL1->data< pL2->data)
	{
		pTail = pL1;
		pL1 = pL1->next;
	}
	if (pL1->data> pL2->data)
	{
		pTail = pL2;
		pL2 = pL2->next;
	}
	while (pL1&&pL2)
	{
		if (pL1->data< pL2->data)
		{
			pTail->next = pL1;
			pL1 = pL1->next;
		}
		if (pL1->data> pL2->data)
		{
			pTail->next = pL2;
			pL2 = pL2->next;
		}
	}
	if (pL1)
	{
		pTail->next = pL1;
	}
	if (pL2)
	{
		pTail->next = pL2;
	}
}
void PrintTailtoHead(pList pList)
{
	if (pList)
		PrintTailtoHead(pList->next);
     	printf("%d ", pList->data);
}
void PrintTailtoHead2(pList plist)
{
	if (plist == NULL)
	{
		printf("Á´±íÎª¿Õ");
	}
	pList pTail = NULL;
	while (pTail != plist)
	{
		pList cur = plist;
		while (cur->next != pTail)
		{
			cur = cur->next;
		}
		printf("%d ->", cur->data);
		pTail = cur;
	}
	printf("NULL");
}
void PrintTailtoHead3(pList plist)
{
	assert(plist);
	int count = 0;
	pList cur = plist;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	cur = plist;
	int *ptr = (int*)malloc(sizeof(int)*count);
	
	for (int i = 0; i < count; i++)
	{
		ptr[i] = cur->data;
		cur = cur->next;
	}
	for (int i=count; i > 0; i--)
	{
		printf("%d ->", ptr[i]);
	}
	printf("NULL");
}
void DeleteNoPNode(pNode pos)
{
	assert(pos);
	pNode pcur = NULL;
	if (pos)
	{
		pcur = pos->next;
		pos->data = pcur->data;
		pos->next = pcur->next;
	}
}