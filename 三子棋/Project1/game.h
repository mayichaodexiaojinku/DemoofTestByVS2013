#ifndef _GAME_H__  
#define _GAME_H__  
#define ROWS 3  
#define COLS 3  


void init_board(char board[ROWS][COLS], int rows, int cols);//�����ʼ��
void print_board(char board[ROWS][COLS], int rows, int cols);//��ӡ����
void play_game(char board[ROWS][COLS]);//����Ϸ
char check_win(char board[ROWS][COLS]);//�ж���Ӯ
void player_move(char board[ROWS][COLS]);//�����
void com_move(char board[ROWS][COLS]);//������

#endif  