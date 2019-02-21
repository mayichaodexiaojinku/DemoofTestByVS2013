#include<stdio.h>
int sort(int *a, int sz)
{
	int i,t;
	int j = sz - 1;
	for (i = 0; i != j; i++)
	if (a[i] % 2 != 0)
		continue;
	else
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		if (a[j] % 2 == 0)
			j--; 
		    i--;
		
	}
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(a) / sizeof(a[0]);
	int i;
	sort(a, sz);
	for (i = 0; i < sz; i++)
		printf("%d ", a[i]);
	return 0;
}