#pragma once
#include<Windows.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define WALL "��"
#define FOOD "��"
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
void CreatWall();//����Χǽ
void GameStart();//��Ϸ��ʼ
void WelcomeToGame();//��ӭ����
void SetPos(int x, int y);//ȷ���������
void InitSnake(pSnake ps);//��ʼ����
void CreateFood(pSnake ps);//����ʳ��
void GameRun(pSnake ps);//��Ϸ����
void SnakeMove(pSnake ps);//���ƶ�
int  KILLBYSELF(pSnake ps);//��ɱ
int  KILLBYWALL(pSnake ps);//ײǽ
void EatFood(ps, pNewNode);//��һ��������ʳ��
void NoFood(ps, pNewNode);//��һ�����겻��ʳ��
void GameHelp();//��Ϸ������ʾ
int NextIsFood(pSnakeNode pn, pSnake ps);//�����һ�������Ƿ���FOOD
void Hidecursor();//���ؿ���̨���
void GameEnd(pSnake ps);//��Ϸ�������ͷſռ�