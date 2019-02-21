#pragma once
#define ROW 6
#define COL 6
#include<stdio.h>
#include<assert.h>
typedef struct Maze
{
	int tmp[ROW][COL];
}Maze;
typedef struct Position
{
	int x;
	int y;
}Position;
#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef Position DataType;
#define MAXSIZE 20
typedef struct Stack
{
	DataType arr[MAXSIZE];
	int top;
}Stack;

void StackInit(Stack** ps);
void StackPush(Stack* ps, DataType data);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);

void testMaze();
void  InitMaze(Maze* m, int arr[ROW][COL]);
void PrintMaze(Maze* m);
int IsValidEnter(Maze* m, Position enter);
void PassMaze(Maze* m, Position enter);
int IsExit(Position pos, Position erter);
int	IsPass(Maze * m, Position pos);
void _GetMazeShortPath(Maze* m, Position cur, Position enter, Stack* path, Stack* shortPath);
int StackSize(Stack* ps);
void SaveShortPath(Stack* path, Stack* shortPath);
int	IsNextPass(Maze * m, Position cur, Position next);


