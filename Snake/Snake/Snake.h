#pragma once
#include<Windows.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define WALL "■"
#define FOOD "●"
#define INIT_X 20
#define INIT_Y 10
typedef struct SnakeNode
{
	struct SnakeNode* next;
	int x;
	int y;
}SnakeNode, *pSnakeNode;

enum direction
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};
enum Gamestatus
{
	OK=1,
	END,
	KILL_BY_WALL,
	KILL_BY_SELF,
};

typedef struct Snake
{
	pSnakeNode _pSnake;
	pSnakeNode _pFood;
	int _Totalscore;
	int _Addscore;
	int _Sleeptime;
	enum direction _Dir;
	enum Gamestatus _Status;
}Snake,*pSnake;
void CreatWall();//创建围墙
void GameStart();//游戏开始
void WelcomeToGame();//欢迎界面
void SetPos(int x, int y);//确定光标坐标
void InitSnake(pSnake ps);//初始化蛇
void CreateFood(pSnake ps);//创建食物
void GameRun(pSnake ps);//游戏进行
void SnakeMove(pSnake ps);//蛇移动
int  KILLBYSELF(pSnake ps);//自杀
int  KILLBYWALL(pSnake ps);//撞墙
void EatFood(ps, pNewNode);//下一个坐标是食物
void NoFood(ps, pNewNode);//下一个坐标不是食物
void GameHelp();//游戏界面提示
int NextIsFood(pSnakeNode pn, pSnake ps);//检查下一个坐标是否是FOOD
void Hidecursor();//隐藏控制台光标
void GameEnd(pSnake ps);//游戏结束，释放空间