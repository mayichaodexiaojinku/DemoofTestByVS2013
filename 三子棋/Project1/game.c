#define _CRT_SECURE_NO_WARNINGS 1  
#include "game.h"  
#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  
void init_board(char board[ROWS][COLS], int rows, int cols)
{
	int i,j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
			board[i][j] = ' ';
	}
}
void print_board(char board[ROWS][COLS], int rows, int cols)
{
	int i;
	for (i = 0; i < ROWS; i++)
	{
		printf(" %C | %C | %C \n", board[i][0], board[i][1], board[i][2]);
		printf("---|---|---\n");
	}
	printf("\n");
}
void play_game(char board[ROWS][COLS])
{
	int ret;
	int count = 0;
	while (1)
	{
		if (count >= 9)
		{
			printf("平局了\n");
			break;
		}
		player_move(board);
		count++;
		print_board(board, ROWS, COLS);
		if ((ret = check_win(board) == 'p'))
		{
			printf("你赢了\n");
			break;
		}
		if (count >= 9)
		{
			printf("平局了\n");
			break;
		}
		com_move(board);
		count++;
		print_board(board, ROWS, COLS);
		if ((ret = check_win(board) == 'p'))
		{
			printf("你挂了\n");
			break;
		}


	}
}
void player_move(char board[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	while (1)
	{

		printf("请输入坐标：\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROWS&&y >= 1 && y <= COLS)
		{

			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
				printf("这个位置已占用，请重试\n");
		}
		else
			printf("输入有误\n");
	}
}
void com_move(char board[ROWS][COLS])
{
	int x ;
	int y;
	int i;
	int j;
	while (1)
	{ 
		srand((unsigned int)time(NULL));
		x = rand() % ROWS;
		y = rand() % COLS;
		if (board[1][1] == ' ')
		{
			board[1][1] = '0';
			break;
		}
		for (i = 0; i < ROWS;i++)
		if (board[i][1] == '0'&&board[i][2]=='0')
		{
			board[i][0] = '0';
			break;
		}
		if (board[i][1] == '0'&&board[i][0] == '0')
		{
			board[i][2] = '0';
			break;
		}
		if (board[1][1] == '0'&&board[0][0]=='0')
		{
			board[2][2] = '0';
			break;
		}
		if (board[1][1] == '0'&&board[0][2]=='0')
		{
			board[2][0] = '0';
			break;
		}
		if (board[1][1] == '0'&&board[2][0] == '0')
		{
			board[0][2] = '0';
			break;
		}
		for (j = 0; j < COLS;j++)
		if (board[1][j] == '0'&&board[0][j] == '0')
		{
			board[2][j] = '0';
			break;
		}
		if (board[1][j] == '0'&&board[2][j] == '0')
		{
			board[0][j] = '0';
			break;
		}
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}
char check_win(char board[ROWS][COLS])
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) &&( board[i][1] == board[i][2] )&& (board[i][0] != ' '))
		{
		return 'p';
	    }
	}
	for (i = 0; i < 3; i++)
	{
		if((board[0][i] == board[1][i] )&& (board[1][i] == board[2][i] )&& (board[0][i] != ' '))
		{
		return 'p';
	}
	}
	if ((board[0][0] == board[1][1] )&& (board[1][1] == board[2][2] )&&( board[0][0] != ' '))
	{
		return 'p';
	}
	if  ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0] )&& (board[0][2] != ' '))
	{
		return 'p';
	}
}
