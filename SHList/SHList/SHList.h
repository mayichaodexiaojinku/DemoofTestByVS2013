#pragma once 
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
typedef int  Datatype;
typedef struct SHListNode
{
	struct SHListNode* next;
	Datatype data;

}Node;

Node*  BuySHListNode(Datatype data);
void  SHListInit(Node** pHead);
void  SHListPushBack(Node* pHead, Datatype data);
void  SHListPopBack(Node* pHead);
void  SHListPushFront(Node* pHead, Datatype data);
void  SHListPopFront(Node* pHead);
void  SHListDestroy(Node* pHead);