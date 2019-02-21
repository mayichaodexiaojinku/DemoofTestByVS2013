#pragma once 
#include<malloc.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef int HPDataType;
typedef int (*Pcompare) (HPDataType left, HPDataType right);
typedef struct Heap
{
	HPDataType* _hp;
	int _capacity;
	int _size;
	Pcompare _compare;
}Heap;

void InitHeap(Heap* hp);
void CreateHeap(Heap* hp, int* array, int size, Pcompare _compare);
void ADJustDown(Heap* hp, int size, int parent);
void Swap(HPDataType* left, HPDataType* right);
void InsertHeap(Heap* hp, HPDataType data);
void RemoveHeap(Heap* hp);
int EmptyHeap(Heap* hp);
HPDataType TopHeap(Heap* hp);
int SizeHeap(Heap* hp);
void ADJustUp(Heap* hp, int child);
void CheckCapacity(Heap* hp);
int Less(HPDataType left, HPDataType right);
int Greater(HPDataType left, HPDataType right);
void TestHeap();

