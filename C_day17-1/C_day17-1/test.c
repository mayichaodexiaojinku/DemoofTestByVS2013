#include<stdio.h>
void find(int *a, int sz)
{
	int i;
	int ret = 0;
	int pos = 0;
	int num1 = 0;
	int num2 = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= a[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (((ret >> 1) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		if (((a[i]>>pos)&1) == 1)
		{
			num1 ^= a[i];
		}
	}
	num2 = num1^ret;
	printf("%d   %d\n", num1, num2);
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4 };
	int  sz = sizeof(a) / sizeof(a[0]);
	find(a, sz);
	return 0;
}