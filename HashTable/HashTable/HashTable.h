#pragma once
#include<stdio.h>
#include<assert.h>
typedef int HDataType;
#define MAX_SIZE 10
typedef enum
{
   EMPTY,
   EXIST,
   DELETE
}State;
typedef struct HTElem
{
	HDataType _data;
	State _state;
}HTElem;
typedef struct HashTable
{
	HTElem _ht[MAX_SIZE];
	int _size;
}HashTable,HT;

void InitHashTable(HT* pHT);
int InsertHashTable(HT* pHT, HDataType data);
int DeleteHashTable(HT* pHT, HDataType data);
int FindHashTable(HT* pHT, HDataType data);
int EmptyHashTable(HT* pHT);
int SizeHashTable(HT* pHT);
int HashFunc(HDataType data);