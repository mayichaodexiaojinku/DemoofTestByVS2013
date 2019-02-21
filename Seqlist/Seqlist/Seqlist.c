#include "Seqlist.h"
void InitSeqlist(pSeqlist pSeq)
{
	assert(pSeq);
	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}
void PrintSeqlist(pSeqlist pSeq)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}
void PushBack(pSeqlist pSeq, DataType d)
{
	assert(pSeq);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满，不能插入");
			return;
	}
	pSeq->data[pSeq->sz] = d;
	pSeq->sz++;
}
void PopBack(pSeqlist pSeq)
{
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，不能删除");
		return;
	}
	pSeq->sz--;
}
void PushFront(pSeqlist pSeq, DataType data)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满，无法插入");
			return;
	}
	for (i =pSeq->sz - 1; i >= 0; i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[0] = data;
	pSeq->sz++;
}
void PopFront(pSeqlist pSeq)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法删除");
		return;
	}
	for (i = 0; i<pSeq->sz-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}
void Insert(pSeqlist pSeq, int pos, DataType d)
{    
	int i = 0 ;
	assert(pSeq&&pos>0 && pos<MAX);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满，不能插入");
			return;
	}
	for (i = pSeq->sz - 1; i > pos; i--)
	{
		pSeq->data[i] = pSeq->data[i-1];
	}
	pSeq->data[pos] = d;
	pSeq->sz++;
}
void Erase(pSeqlist pSeq, int pos)
{
	int i = 0;
	assert(pSeq&&pos>0&&pos<MAX);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，不能删除");
		return;
	}
	for (i = pos; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i+1];
	}
	pSeq->sz--;
}
void Remove(pSeqlist pSeq, DataType data)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，不能删除");
		return;
	}
	for (i = 0; i < pSeq->sz - 1 ; i++)
	{
		if (pSeq->data[i] == data)
		{
			for (j=i; j < pSeq->sz - 1; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->sz--;
			return;
		}
	}
}
void RemoveAll(pSeqlist pSeq, DataType data)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，不能删除");
		return;
	}
	for (i = 0; i < pSeq->sz ; i++)
	{
		if (pSeq->data[i] == data)
		{
			for (j = i; j < pSeq->sz - 1; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->sz--;
		}
	}
}
int Find(pSeqlist pSeq, DataType data)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == data)
		{
			return i;
		}
	}
}
int Size(pSeqlist pSeq)
{
	assert(pSeq);
	return pSeq->sz;
}
int  Empty(pSeqlist pSeq)
{
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		return 0;
	}
	else
		return 1;
}
void BubbleSort(pSeqlist pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz-1; i++)
	{
		for (j = i + 1; j < pSeq->sz - 1;j++)
		if (pSeq->data[j]>pSeq->data[j + 1])
		{
			DataType a = pSeq->data[j];
			pSeq->data[j] = pSeq->data[j + 1];
			pSeq->data[j + 1] = a;
		}
	}
}
void SelectSort(pSeqlist pSeq)
{
	int i = 0;
	int j = 0;
	int min=0;
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		min = i;
		for (j = i + 1; j < pSeq->sz; j++)
		{
			if (pSeq->data[j]<pSeq->data[min])
			{
				DataType a = pSeq->data[j];
				pSeq->data[j] = pSeq->data[min];
				pSeq->data[min] = a;
			}
		}
	}
	
}
int BinarySearch(pSeqlist pSeq, DataType data)
{
	assert(pSeq);
	int left = 0;
	int right = pSeq->sz-1;
	int mid;
	while (left <= right)
	{
	   mid = (left + right) / 2;
		if (pSeq->data[mid] > data)
		{
			right = mid - 1;

		}
		else if (pSeq->data[mid] < data)
		{
			left = mid + 1;  
		}
		else if (pSeq->data[mid] == data)
		{
			return mid;
		}
		else
		{
			printf("找不到");
		}
	}
}
int BinarySearch_R(pSeqlist pSeq, int left, int right, DataType data)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (pSeq->data[mid] > data)
		{
			return BinarySearch_R(pSeq, left, mid - 1, data);

		}
		else if (pSeq->data[mid] < data)
		{
			return BinarySearch_R(pSeq, mid+1,right, data);
		}
		else if (pSeq->data[mid] == data)
		{
			return mid;
		}

	}
}
void SelectSortOP(pSeqlist pSeq)
{
	int i, min, max, left, right, tmp;
	assert(pSeq);
	for (left = 0, right = pSeq->sz - 1; left < right; left++, right--)
	{
		min = left;
		max = right;
		for (i = left; i <= right; i++)
		{
			if (pSeq->data[i]<pSeq->data[min])
			{
				min = i;
			}
			else if (pSeq->data[i]>pSeq->data[max])
			{
				max = i;
			}
		}

		if (min != left)
		{
			tmp = pSeq->data[left];
			pSeq->data[left] = pSeq->data[min];
			pSeq->data[min] = tmp;
			if (max == left)
			{
				max = min;
			}
		}
		if (max != right)
		{

			tmp = pSeq->data[right];
			pSeq->data[right] = pSeq->data[max];
			pSeq->data[max] = tmp;

		}
	}
}