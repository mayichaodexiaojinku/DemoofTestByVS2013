#include "common.h"
unsigned long  GetNextPrime(unsigned long prime)
{
	int i = 0;
	static unsigned long _PrimeList[PRIME_SIZE] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	
	};
	for (i = 0; i < PRIME_SIZE; i++)
	{
		if (_PrimeList[i]>prime)
			return _PrimeList[i];
	}
	return _PrimeList[PRIME_SIZE - 1];
}
unsigned long StrToInt(const char * str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}
unsigned long DataToInt(int data)
{
	return data;
}