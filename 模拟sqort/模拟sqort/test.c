#include<stdio.h>
int int_cmp(const void * e1,const void * e2)
{
	return *(int*)e1-*(int *)e2;
}
void _swap( void * e1,  void * e2 ,int size)
{
	for (int i = 0; i < size; i++)
	{
		char tmp = *((char *)e1 + i);
		*((char *)e1 + i) = *((char *)e2 + i);
		*((char *)e2 + i) = tmp;
	}
}
void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
{
	for (int i = 0; i < count; i++)
	{
		for (int  j = 0; j < count - 1 - i; j++)
		{
			if (int_cmp((char*)base + j*size, (char*)base + (j + 1)*size)>0)
			{
				_swap((char*)base + j*size, (char*)base + (j + 1)*size, size);
			}
		}
	}
}
int main()
{
	int a[] = { 1,4,7,2,5,8,9,6,3,0};
	int sz = sizeof(a) / sizeof(a[0]);
	bubble(a, sz, sizeof(int), int_cmp);
	for (int i = 0; i < sz ; i++)
	{

		printf("%d ", a[i]);
	}
}