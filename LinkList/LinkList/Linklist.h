#ifndef __SLINKLIST_H__
#define __SLINKLIST_H__
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node,List,*pList,*pNode;
void InitLinkList(pList* pplist);
void PushBack(pList* pplist,DataType data);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType data);
void PopFront(pList* pplist);
void PrintLinklist(pList plist);
void DestroyLinklist(pList *pplist);//
void ReverseLinklist(pList *pplist);//链表的逆置
void ReverseLinklistOP(pList *pplist);//头插思想链表逆置
void MergeLinklist(pList *pplist1, pList *pplist2);
void PrintTailtoHead(pList pList);
void PrintTailtoHead2(pList plist);
void DeleteNoPNode(pList* pplist, int data);
void DeleteNoPNode(pNode pos);
#endif  //__SLINKLIST_H__