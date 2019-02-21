#pragma once
#include"common.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
//typedef int HDataType;
typedef int HDataType;
typedef int (*PDTInt)(HDataType data);
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
	HTElem* _ht;
	int _size;
	int _capacity;
	int _total;
	PDTInt _PDTInt;
}HashTable,HT;

void InitHashTable(HT* pHT, PDTInt pDTInt);
int InsertHashTable(HT* pHT, HDataType data);

int DeleteHashTable(HT* pHT, HDataType data);
int FindHashTable(HT* pHT, HDataType data);
int EmptyHashTable(HT* pHT);
int SizeHashTable(HT* pHT);
int HashFunc(HT* pHT, HDataType data);
void _Checkcapacity(HT* pHT);