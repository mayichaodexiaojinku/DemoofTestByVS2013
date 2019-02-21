#include<stdio.h>
int main()
{
	int a[] = { 5, 2, 2, 3, 3, 4, 4, 1, 5, 6, 6, 7, 7 };
	int i ;
	int len = sizeof(a) / sizeof(a[0]);
	for (i = 1; i < len; i++)
	{
		a[0] = a[0] ^ a[i];

	}
	printf("%d\n", a[0]);
	return 0;

}