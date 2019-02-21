#include "Queue.h"
QListNode* BuyNode(DataType data)
{
	QListNode* pNewNode = (QListNode*)malloc(sizeof(QListNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->pNext = NULL;
	return pNewNode;
}
void QueueInit(Queue* q)
{
	assert(q);
	q->pFront=q->pRear=BuyNode(0);
}
void QueuePush(Queue* q, DataType data)
{
	assert(q);
	q->pRear->pNext = BuyNode(data);
	q->pRear = q->pRear->pNext;
}
void QueuePop(Queue* q)
{
	assert(q);
	if (q->pFront != q->pRear)
	{
		QListNode* del = q->pFront->pNext;
		q->pFront->pNext = del->pNext;
		free(del);
	}
}
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->pFront->pNext->data;
}
DataType QueueRear(Queue* q)
{
	assert(q);
	return q->pRear->data;
}
int QueueSize(Queue* q)
{
	int count = 0;
	QListNode* cur = q->pFront->pNext;
	while (cur)
	{
		count++;
		cur = cur->pNext;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	if (0 == QueueSize(q))
	{
		return 0;
	}
	return 1;
}
