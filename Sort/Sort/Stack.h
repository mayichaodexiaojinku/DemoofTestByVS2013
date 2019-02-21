
#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef int DataType;
#define MAXSIZE 10
typedef struct Stack
{
    DataType arr[MAXSIZE];
	int top;
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps, DataType data);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void MacthBrackets(Stack* ps, int size, const char arr[]);
int IsBrackets(char arr[], int i);