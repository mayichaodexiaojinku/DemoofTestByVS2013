#pragma once
#include <assert.h>
#include<stdio.h>
#include<malloc.h>
typedef int DataType;
typedef  struct DListNode
{
	struct DListNode* next;
	struct DListNode* pre;
	DataType data;
}DListNode;
void  DListInit(DListNode** pHead);
void  DListPushBack(DListNode* pHead,DataType data);
void  DListPopBack(DListNode* pHead);
void  DListInsert(DListNode* pos, DataType data);
void  DListErase(DListNode* pos);
  
DListNode* BuyDListNode(DataType data);