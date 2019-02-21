#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>  
#include"game.h"
void display(char show[rows][cols])
{
	int i = 0;
	int j = 0;
	printf("   ");
	for (i = 1; i < cols-1; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i < rows-1; i++)
	{
		printf(" %d ", i);
		for (j = 1; j < cols-1; j++)
		{
			printf(" %c ", show[i][j]);
		}
		printf("\n");
	}
}
void set_mine(char mine[rows][cols])//�����׵�λ��
{
	int count = Count;
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
	 

}



int  Sweep(char mine[rows][cols], char show[rows][cols])//��ʼɨ�� 
{

	int count = 0;
	int x = 0;
	int y = 0;
	int clear = 0;
	while (count != (rows - 2)*(cols - 2) - Count)
	{


		printf("���������꣺");
		scanf("%d %d", &x, &y);

		if (mine[x][y] == '1')
		{
			if (clear == 0)
			{

				move_mine(mine, x, y);
				show[x][y] = '0';
				display(show);
				clear++;
			}
			else
			{
				printf("�����\n");
				display(mine);
				break;
			}

		}
		else
		{
			int ret = get_num(mine, x, y);
			show[x][y] = ret + '0';

			if (ret == 0)
			{
				show[x][y] = '0';
				show[x][y - 1] = '0';
				show[x][y + 1] = '0';
				show[x - 1][y - 1] = '0';
				show[x - 1][y] = '0';
				show[x - 1][y + 1] = '0';
				show[x + 1][y - 1] = '0';
				show[x + 1][y] = '0';
				show[x + 1][y + 1] = '0';

			}
		}
			display(show);
			count++;
		}
	if (count == (rows - 2)*(cols - 2) - Count)
	{

		printf("��Ӯ��\n");
		display(mine);
	}
		return 0;
		
	
	
}
int get_num(char mine[rows][cols], int x, int y)//�����׵ĸ���  
{
	int count=0;

	if (mine[x - 1][y - 1] == '1')
	{
		count++;
	}
	if (mine[  x  ][y - 1] == '1')
	{
		count++;
	}
	if (mine[x - 1][  y  ] == '1')
	{
		count++;
	}
    if (mine[x + 1 ][y + 1] == '1')
		{
			count++;
		}
	if (mine[   x   ][y + 1] == '1')
	{
		count++;
	}
	if (mine[ x + 1 ][  y  ] == '1')
	{
		count++;
	}
	if (mine[ x + 1 ][y - 1] == '1')
	{
		count++;
	}
	if (mine[x - 1][ y + 1] == '1')
	{
		count++;
	}
	return count;
}
int Game(char mine[rows][cols], char show[rows][cols])//��Ϸ  
{
	set_mine(mine);
	display(show);
	display(mine);
	Sweep(mine, show);
	return 0;
}
void move_mine(char mine[rows][cols],int x,int y)
{
	int tmp;
	int i = 0;
	int j = 0;
	srand((unsigned)time(NULL));
	i = rand() % 9 + 1;
	j = rand() % 9 + 1;
	if (mine[i][j] = '0')
	{
		tmp = mine[i][j];
		mine[i][j] = mine[x][y];
		mine[x][y] = tmp;
	}

}