#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void bubble_sort(char *a[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz - i-1;j++)
		{
			if (strcmp(a[j] , a[j + 1])>0)
			{
				char* t = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = t;
			}

		}
	}
}
int main()
{
	int i = 0;
	char *a[] = { "aaaa", "cccc", "bbbb" };
	int sz = sizeof(a) / sizeof(*a);
	bubble_sort(a, sz);
	for (i = 0; i < sz; i++)
		printf("%s\n", a[i]);
	return 0;
}
