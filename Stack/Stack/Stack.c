#include"Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->top =0;
}
void StackPush(Stack *ps, DataType data)
{
	assert(ps);
	if (ps->top == MAXSIZE-1)
	{
		printf("ÂúÁË");
		return ;
	}
	else
	ps->_arr[ps->top++] = data;
	return;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (0 == ps->top)
	{
		printf("¿ÕµÄ");
		return;
	}
	else
	 ps->top--;
	return;
}
DataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_arr[ps->top - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (0 == ps->top)
	{
		return 1;
	}
	return 0;
}
