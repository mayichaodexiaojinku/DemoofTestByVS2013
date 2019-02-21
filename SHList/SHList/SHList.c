#include "SHList.h"
Node*  BuySHListNode(Datatype data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;
	return pNewNode;

}
void  SHListInit(Node** pHead)
{
	pHead = BuySHListNode(0);
}
void  SHListPushBack(Node* pHead, Datatype data)
{
	Node* pTailNode = pHead;
	assert(pHead);
	while (pTailNode->next)
		pTailNode = pTailNode->next;
	    pTailNode->next = BuySHListNode(data);

}
void  SHListPopBack(Node* pHead)
{
	Node* pTailNode = pHead;
	Node* pPreTail = NULL;
	assert(pHead);
	if (NULL == pHead->next)
		return;
	while (pTailNode->next)
	{
		pPreTail = pTailNode;
		pTailNode = pTailNode->next;
	}
	free(pTailNode);
	pPreTail->next = NULL;
}
void  SHListPushFront(Node* pHead, Datatype data)
{
	Node* pNewNode = NULL;
	assert(pHead);
	pNewNode->next = pHead->next;
	pHead->next = pNewNode;
}
void  SHListPopFront(Node* pHead)
{
	Node* pDelNode = NULL;
	assert(pHead);
	if (NULL == pHead->next)
		return;
	pDelNode = pHead->next;
	pHead->next = pDelNode->next;
	free(pDelNode);
}
void  SHListDestroy(Node* pHead)
{
	assert(pHead);
	free(pHead);
	pHead = NULL;
}