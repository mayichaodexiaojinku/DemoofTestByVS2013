#ifndef _GAME_H__  
#define _GAME_H__  
#define ROWS 3  
#define COLS 3  


void init_board(char board[ROWS][COLS], int rows, int cols);//数组初始化
void print_board(char board[ROWS][COLS], int rows, int cols);//打印棋盘
void play_game(char board[ROWS][COLS]);//玩游戏
char check_win(char board[ROWS][COLS]);//判断输赢
void player_move(char board[ROWS][COLS]);//玩家走
void com_move(char board[ROWS][COLS]);//电脑走

#endif  