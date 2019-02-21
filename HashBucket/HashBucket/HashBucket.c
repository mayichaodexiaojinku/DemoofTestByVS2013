#include"HashBucket.h"
void InitHashBucket(HashBucket* pHB, int capacity, PDTInt pDTInt)
{
	int i;
	assert(pHB);
	pHB->_table = (pNode*)malloc(capacity*sizeof(HBNode));
	if (NULL == pHB->_table)
	{
		assert(0);
		return;	
	}
	pHB->pDTInt = pDTInt;
	pHB->_capacity = capacity;
	pHB->_size = 0;

	for (i = 0; i <pHB->_capacity; i++)
		pHB->_table[i] = NULL;

}
int InsertHashBucket(HashBucket* pHB, HBDatatype data)
{
	int bucketNo = 0;
	assert(pHB);
	pNode pCur = NULL;
	bucketNo = HashFuncBucket(pHB, data);
	pCur = pHB->_table[bucketNo];
	while (pCur)
	{
		if (data == pCur->_data)
			return 0;
		pCur = pCur->_next;
	}
	pCur = BuyHashBucketNode(data);
	pCur->_next = pHB->_table[bucketNo];
	pHB->_table[bucketNo] = pCur;
	pHB->_size++;
	return 1;

}
int DeleteHashBucket(HashBucket* pHB, HBDatatype data)
{
	int bucketNo = 0;
	assert(pHB);
	pNode pCur = NULL;
	pNode pParent = NULL;
	bucketNo = HashFuncBucket(pHB, data);
	pCur = pHB->_table[bucketNo];
	while (pCur)
	{
		if (data == pCur->_data)
		{
			if (pCur == pHB->_table[bucketNo])
				pHB->_table[bucketNo] = pCur->_next;
			else
				pParent->_next = pCur->_next;
			    return 1;
		}
		pParent = pCur;
		pCur = pCur->_next;
	}
	return 0;
}
int FindHashBucket(HashBucket* pHB, HBDatatype data)
{
	int bucketNo = 0;
	assert(pHB);
	pNode pCur = NULL;
	bucketNo = HashFuncBucket(pHB, data);
	pCur = pHB->_table[bucketNo];
	while (pCur)
	{
		if (data == pHB->_table[bucketNo]->_data)
			return 1;
		pCur = pCur->_next;
	}
	return 0;
}
int EmptyHashBucket(HashBucket* pHB)
{
	assert(pHB);
	return 0 == pHB->_size;
}
int SizeHashBucket(HashBucket* pHB)
{
	assert(pHB);
	return pHB->_size;
}
int DestroyHashBucket(HashBucket* pHB)
{
	int i;
	assert(pHB);
	pNode pDel = NULL;
	for (i = 0; i < pHB->_capacity; i++)
	{
		pDel = pHB->_table[i];
		while (pDel)
		{
			pHB->_table[i] = pDel->_next;
			free(pDel);
			pDel = pHB->_table[i];
		}
	}
	free(pHB->_table);
	pHB->_table = NULL;
	return 1;
	
}
int HashFuncBucket(HashBucket* pHB, HBDatatype data)
{
	assert(pHB);
	return pHB->pDTInt(data) % pHB->_capacity;
}
pNode BuyHashBucketNode(HBDatatype data)
{
	pNode pNewNode = (pNode*)malloc(sizeof(pNode));
	pNewNode->_data = data;
	pNewNode->_next = NULL;
	return  pNewNode;
}
void PrintHashBucket(HashBucket* pHB)
{
	int i = 0;
	assert(pHB);
	pNode pCur = NULL;
	for (i = 0; i < pHB->_capacity; i++)
	{
		pCur = pHB->_table[i];
		printf("table[%d]", i);
		while (pCur)
		{
			printf("%d--->",pCur->_data);
			pCur = pCur->_next;
		}
		printf("NULL\n");
	}
}