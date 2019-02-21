#include"PriorityQueue.h"
void InitPriorityQueue(PriorityQueue* q)
{
	assert(q);
	InitHeap(&q->hp);
}
void PushPriorityQueue(PriorityQueue* q, HPDataType data)
{
	assert(q);
	InsertHeap(&q->hp, data);
}
void PopPriorityQueue(PriorityQueue* q)
{
	assert(q);
	RemoveHeap(&q->hp);
}
HPDataType TopPriorityQueue(PriorityQueue* q)
{
	assert(q);
	return TopHeap(&q->hp);
}
int SizePriorityQueue(PriorityQueue* q)
{
	assert(q);
	return SizeHeap(&q->hp);
}
int EmptyPriorityQueue(PriorityQueue* q)
{
	assert(q);
	return EmptyHeap(&q->hp);
}