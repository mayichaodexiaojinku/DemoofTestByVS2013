#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define  N  10
int main()
{
	int a[N][N] = { 0 };
	int i, j;
    for (i = 0; i<N; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j==0||j==i)
				a[i][j] = 1;
		    else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i<N; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%*d", 32 - i , a[i][0]);
			printf("%d", a[i][j]);
			printf("\n");
		
	}
}