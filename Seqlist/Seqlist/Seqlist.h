#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<assert.h>
#include<stdio.h>
#include<string.h>
#define MAX 10
typedef int DataType;
typedef struct Seqlist
{
	DataType data[MAX];
	int sz;
}Seqlist, *pSeqlist;

void InitSeqlist(pSeqlist pSeq);
void PrintSeqlist(pSeqlist pSeq);
void PushBack(pSeqlist pSeq,DataType d);
void PopBack(pSeqlist pSeq);
void PushFront(pSeqlist pSeq, DataType data);
void PopFront(pSeqlist pSeq);
void Insert(pSeqlist pSeq,int pos,DataType d);
void Erase(pSeqlist pSeq, int pos);
void Remove(pSeqlist pSeq, DataType data);
void RemoveAll(pSeqlist pSeq, DataType data);
int  Find(pSeqlist pSeq, DataType data);
int  Empty(pSeqlist pSeq);
void BubbleSort(pSeqlist pSeq);
void SelectSort(pSeqlist pSeq);
void SelectSortOP(pSeqlist pSeq);
int BinarySearch(pSeqlist pSeq, DataType data);
int BinarySearch_R(pSeqlist pSeq, int left, int right, DataType d);


#endif // __SEQLIST_H__