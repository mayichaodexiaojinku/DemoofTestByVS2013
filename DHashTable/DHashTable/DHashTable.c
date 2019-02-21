#include"DHashTable.h"
void InitHashTable(HT* pHT,PDTInt pDTInt)
{
	int i = 0;
	int HashSize=10;
	assert(pHT);
	HashSize = GetNextPrime(HashSize);
	pHT->_capacity = HashSize;
	pHT->_ht = (HTElem*)malloc(HashSize*sizeof(HTElem));
	if (NULL == pHT->_ht)
	{
		assert(0);
		return;
	}
	for (i = 0; i < HashSize; i++)
		pHT->_ht[i]._state = EMPTY;
	pHT->_size = 0;
	pHT->_total = 0;
	pHT->_PDTInt = pDTInt;
	return;
}
int InsertHashTable(HT* pHT, HDataType data)
{
	int hashAddr = HashFunc(pHT,data);
	assert(pHT);
	if (pHT->_total * 10 / pHT->_capacity>7)
	{
		_Checkcapacity(pHT);
	}
	while (EMPTY != pHT->_ht[hashAddr]._state)
	{
		if (EXIST == pHT->_ht[hashAddr]._state&&
			data == pHT->_ht[hashAddr]._data)
		{
			return 0;
		}
		hashAddr++;
		if (hashAddr == pHT->_capacity)
			hashAddr = 0;
	}
	pHT->_ht[hashAddr]._state = EXIST;
	pHT->_ht[hashAddr]._data = data;
	pHT->_size++;
	pHT->_total++;
	return 1;
}
int DeleteHashTable(HT* pHT, HDataType data)
{
	int HashADDr = HashFunc(pHT,data);
	if (1 ==FindHashTable(pHT,data))
	{
		pHT->_ht[HashADDr]._state = DELETE;
		pHT->_size--;
		return 1;
	}
	return 0;
}
int FindHashTable(HT* pHT, HDataType data)
{
	int HeadADDer = HashFunc(pHT,data);
	assert(pHT);
	while (EMPTY != pHT->_ht[HeadADDer]._state)
	{
		if (EXIST == pHT->_ht[HeadADDer]._state&&
			data == pHT->_ht[HeadADDer]._data)
		{
			return 1;
		}
		HeadADDer++;
	}
	return 0;
}

int HashFunc(HT* pHT,HDataType data)
{
	return pHT->_PDTInt(data)%pHT->_capacity;
}
void _Checkcapacity(HT* pHT)
{
	assert(pHT);
	HT* pNew = NULL;
	int i = 0;
	int hashAddr;
	int oldcapacity = pHT->_capacity;
	int newcapacity = pHT->_capacity * 2;
	pNew= (HT*)malloc(newcapacity*sizeof(HT));
	if (NULL == pNew)
	{
		assert(0);
		return;
	}
	for (i = 0; i < pNew->_capacity; i++)
		pNew->_ht[i]._state = EMPTY;
	pHT->_capacity = newcapacity;
	for (i = 0; i < oldcapacity; i++)
	{
		if (EXIST != pHT->_ht[i]._state)
			continue;
		hashAddr = HashFunc(pHT, pHT->_ht[i]._data);
		while (EMPTY != pNew->_ht[hashAddr]._state)
		{
			if (EXIST == pHT->_ht[hashAddr]._state)
			{
				return;
			}
			hashAddr++;
			if (hashAddr == newcapacity)
				hashAddr = 0;
		}
		pNew->_ht[hashAddr]._state = EXIST;
		pNew->_ht[hashAddr]._data = pHT->_ht[i]._data;
	}
	free(pHT->_ht);
	pHT = pNew;
	pHT->_total= pHT->_size;
}