#include "DList.h"
DListNode* BuyDListNode(DataType data)
{
	DListNode* pNewNode;
	pNewNode = (DListNode*)malloc(sizeof(DListNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->next = NULL;
	pNewNode->pre = NULL;
	pNewNode->data = data;
	return pNewNode;
}
void  DListInit(DListNode** pHead)
{
	assert(pHead);
	*pHead = BuyDListNode(0);
	(*pHead)->next = *pHead;
	(*pHead)->pre = *pHead;
}
void  DListPushBack(DListNode* pHead, DataType data)
{
	DListNode* pNewNode;
	assert(pHead);
	pNewNode = BuyDListNode(data);
	pNewNode->pre = pHead->pre;
	pNewNode->next = pHead;
	pNewNode ->pre->next= pNewNode;
	pHead->pre = pNewNode;

}
void  DListPopBack(DListNode* pHead)
{
	DListNode* pDelNode;
	assert(pHead);
	pDelNode = pHead->pre;
	if ( pDelNode != pHead)
	{
		pDelNode->pre->next = pDelNode->next;
	    pDelNode->next->pre = pDelNode->pre;
		free(pDelNode);
		
	}
	pDelNode->pre->next = pHead;
	pHead->pre = pDelNode->pre;
	free(pDelNode);
}
void  DListInsert(DListNode* pos, DataType data)
{
	DListNode* pNewNode;
	if (NULL == pos)
		return;
	pNewNode = BuyDListNode(data);
	pNewNode->next = pos;
	pos->pre->next = pNewNode;
	pNewNode->pre = pos->pre;
	pos->pre = pNewNode;
	
}
void  DListErase(DListNode* pos)
{
	if (NULL == pos);
	return;
	pos->pre->next = pos->next;
	pos->next->pre = pos->pre;
	free(pos);
}
void  DListFind(DListNode* pHead,DataType data)
{
	DListNode* pCur;
	assert(pHead);
	pCur = pHead->next;
	while (pCur!=pHead)
	{
		if (data == pCur->data)
			return pCur;
		pCur = pCur->next;
	}
	return NULL;
}