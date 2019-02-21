#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef char DataType;
#define MAXSIZE 20
typedef struct Stack
{
	DataType arr[MAXSIZE];
	int top;
}Stack;
typedef struct QueueandStack
{
	Stack _data;
	Stack _min;
}QueueandStack;
void QueueandStackInit(QueueandStack* ps);
void QueueandStackPush(QueueandStack* ps,DataType data);
void QueueandStackPop(QueueandStack* ps);
DataType QueueandStackTop(QueueandStack* ps);
int QueueandStackSize(QueueandStack* ps);
int QueueandStackEmpty(QueueandStack* ps);
void StackInit(Stack* ps);
void StackPush(Stack* ps, DataType data);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);