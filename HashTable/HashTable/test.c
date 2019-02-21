#include"HashTable.h"
int main()
{
	HT pHT;
	InitHashTable(&pHT);
	InsertHashTable(&pHT, 1);
	InsertHashTable(&pHT, 2);
	InsertHashTable(&pHT, 3);
	InsertHashTable(&pHT, 4);
	InsertHashTable(&pHT, 5);
	InsertHashTable(&pHT, 6);
	InsertHashTable(&pHT, 7);
	InsertHashTable(&pHT, 8);
	InsertHashTable(&pHT, 9);
	InsertHashTable(&pHT, 10);
	DeleteHashTable(&pHT, 10);
	if (1 == FindHashTable(&pHT, 10))
		printf("找到了\n");
	else
		printf("没找到\n");
	printf("%d \n", SizeHashTable(&pHT));
	return 0;
}