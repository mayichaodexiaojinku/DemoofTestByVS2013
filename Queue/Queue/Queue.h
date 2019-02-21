#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
typedef int DataType;
typedef struct QListNode
{
	struct QListNode* pNext;
	DataType data;
}QListNode;
typedef struct Queue
{
	QListNode* pFront;
	QListNode* pRear;
}Queue;
QListNode* BuyNode(DataType data);
void QueueInit(Queue* q);
void QueuePush(Queue* q, DataType data);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueRear(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void TestQueue();
