#include"HashTable.h"
void InitHashTable(HT* pHT)
{
	int i = 0;
	assert(pHT);
	for (i = 0; i < MAX_SIZE; i++)
		pHT->_ht[i]._state = EMPTY;
	pHT->_size = 0;

}
int InsertHashTable(HT* pHT, HDataType data)
{
	int HeadADDer = HashFunc(data);
	assert(pHT);
	while (EMPTY != pHT->_ht[HeadADDer]._state)
	{
		if (EXIST == pHT->_ht[HeadADDer]._state&&
			data == pHT->_ht[HeadADDer]._data)
		{
			return 0;
		}
		HeadADDer++;
		if (HeadADDer == MAX_SIZE)
			HeadADDer = 0;
	}
	pHT->_ht[HeadADDer]._state = EXIST;
	pHT->_ht[HeadADDer]._data = data;
	pHT->_size++;
	return 1;
}
int DeleteHashTable(HT* pHT, HDataType data)
{
	int HashADDr = HashFunc(data);
	if (1 == FindHashTable(pHT, data))
	{
		pHT->_ht[HashADDr]._state = DELETE;
		pHT->_size--;
		return 1;
	}
	return 0;
}
int FindHashTable(HT* pHT, HDataType data)
{
	int HeadADDer = HashFunc(data);
	assert(pHT);
	while (EMPTY != pHT->_ht[HeadADDer]._state)
	{
		if (EXIST == pHT->_ht[HeadADDer]._state&&
			data == pHT->_ht[HeadADDer]._data)
		{
			return 1;
		}
		HeadADDer++;
		if (HeadADDer == MAX_SIZE)
			HeadADDer = 0;
	}
	return 0;
}
int EmptyHashTable(HT* pHT)
{
	assert(pHT);
	return  0==pHT->_size;
}
int SizeHashTable(HT* pHT)
{
	assert(pHT);
	return pHT->_size;
}
int HashFunc(HDataType data)
{
	return data%MAX_SIZE;
}