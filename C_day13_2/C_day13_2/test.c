#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 5
int yangshi(int a[N][N], int *row, int *col, int num)
{
	*row = 0;
	*col = N - 1;
	while (*row<N&&*col>=0)
	{
		if (a[*row][*col]>num)
			(*col)--;
		else if (a[*row][*col] < num)
			(*row)++;
		else
			return 1;
	}
	return 0;
}
int main()
{
	int a[N][N] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 },
	{ 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25 } };
	int i, num;
	int row;
	int col;
	printf("请输入你要找的数：");
	scanf("%d", &num);
	   i=yangshi(a, &row, &col, num);
	if (i == 0)
		printf("not found\n");
	else if (i == 1)
		printf("row=%d,col=%d\n", row+1, col+1);
	return 0;
}