#define _CRT_SECURE_NO_WARNINGS 1  
#ifndef _GAME_H__  
#define _GAME_H__  
#include<stdio.h>  
#include<stdlib.h>  
#include<time.h>  
#include<string.h>  
#define rows 11  
#define cols 11  
#define Count 10  

void display(char show[rows][cols]);
int Game(char mine[rows][cols], char show[rows][cols]);//游戏  
void set_mine(char mine[rows][cols]);//设置雷的位置  
int Sweep(char mine[rows][cols], char show[rows][cols]);//开始扫雷  
int get_num(char mine[rows][cols], int x, int y);//计算雷的个数  
void move_mine(char mine[rows][cols],int x,int y);//避免第一次踩
#endif  