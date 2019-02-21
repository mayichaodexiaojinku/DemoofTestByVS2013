#pragma once 
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>
typedef struct BitMap
{
	int* _pBit;
	int _capacity;
	int size;
}BitMap;
 

void InitBitMap(BitMap* pBmp,int totalBit);
void SetBitMap(BitMap* pBmp, int which);
int  GetBitMap(BitMap* pBmp, int which);
void ClearBitMap(BitMap* pBmp, int which);