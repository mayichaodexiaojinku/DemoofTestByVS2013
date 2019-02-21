
#define _CRT_SECURE_NO_WARNINGS 1  
#include "game.h"  
#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  



void menu()
{
	printf("*************************\n");
	printf("*****    1.play    ******\n");
	printf("*****    0.exit    ******\n");
	printf("*************************\n");

}
void game()
{
	int input = 1;
	char board[ROWS][COLS] = { 0 };
	while (input)
	{
		menu();
		printf("«Î—°‘Ò:");
		scanf("%d", &input);
		if (input == 1)
		{
			init_board(board, ROWS, COLS);
			print_board(board, ROWS, COLS);
			play_game(board);
		}
		else if (input == 0)
		{
			printf("ÕÀ≥ˆ”Œœ∑\n");
			break;
		}
	}
}

int main()
{
	game();
	return 0;
}