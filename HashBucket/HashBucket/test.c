#include"HashBucket.h"
int main()
{
	HashBucket pHB;
	InitHashBucket(&pHB,10,DataToInt);
	InsertHashBucket(&pHB, 1);
	InsertHashBucket(&pHB, 2);
	InsertHashBucket(&pHB, 3);
	InsertHashBucket(&pHB, 4);
	InsertHashBucket(&pHB, 5);
	InsertHashBucket(&pHB, 6);
	InsertHashBucket(&pHB, 7);
	InsertHashBucket(&pHB, 8);
	InsertHashBucket(&pHB, 19);
	InsertHashBucket(&pHB, 9);
	PrintHashBucket(&pHB);
	DestroyHashBucket(&pHB);
	PrintHashBucket(&pHB);
	return 0;
}