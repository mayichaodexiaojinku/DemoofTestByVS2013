#include"BitMap.h"
void InitBitMap(BitMap* pBmp, int totalBit)
{
	assert(pBmp);
	int N = (totalBit >> 5) + 1;
	pBmp->_pBit = (int*)malloc(N*sizeof(int));
	if (NULL == pBmp->_pBit)
	{
		return;
	}
	memset(pBmp->_pBit, 0, sizeof(int)*N);
	pBmp->_capacity = totalBit;
	pBmp->size = 0;
}
void SetBitMap(BitMap* pBmp, int which)
{
	assert(pBmp);
	int index = 0;
	int pos = 0;
	index = (which >> 5);
	pos = which % 32;
	pBmp->_pBit[index] |= (1 << pos);
	pBmp->size++;
}
int  GetBitMap(BitMap* pBmp, int which)
{
	assert(pBmp);
	int index = 0;
	int pos = 0;
	index = (which >> 5);
	pos = which % 32;
	return pBmp->_pBit[index] &= (1 << pos);
}
void ClearBitMap(BitMap* pBmp, int which)
{
	assert(pBmp);
	int index = 0;
	int pos = 0;
	index = (which >> 5);
	pos = which % 32;
	return pBmp->_pBit[index] &= ~(1 << pos);
}