#pragma once 
#include"common.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>
typedef int HBDatatype;
typedef int(*PDTInt)(HBDatatype data);
typedef struct HashBucketNode
{
	struct HashBucketNode* _next;
	HBDatatype _data;
}HBNode,*pNode;

typedef struct HashBucket
{
	pNode* _table;
	int _capacity;
	int _size;
	PDTInt pDTInt;
}HashBucket;
 
void InitHashBucket(HashBucket* pHB, int capacity, PDTInt pDTInt);
int InsertHashBucket(HashBucket* pHB, HBDatatype data);
int DeleteHashBucket(HashBucket* pHB, HBDatatype data);
int FindHashBucket(HashBucket* pHB, HBDatatype data);
int EmptyHashBucket(HashBucket* pHB);
int SizeHashBucket(HashBucket* pHB);
int DestroyHashBucket(HashBucket* pHB);
int HashFuncBucket(HashBucket* pHB, HBDatatype data);
pNode BuyHashBucketNode(HBDatatype data);
void PrintHashBucket(HashBucket* pHB);