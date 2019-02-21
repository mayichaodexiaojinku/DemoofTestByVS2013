#include"QandS.h"
void QueueandStackInit(QueueandStack* p)
{
	assert(p);
	StackInit(&(p->_data));
	StackInit(&(p->_min));

}
void QueueandStackPush(QueueandStack* p,DataType data)
{
	assert(p);
	if (StackEmpty(&(p->_data))||data<StackTop(&(p->_min)))
	{
		StackPush(&(p->_data), data);
		StackPush(&(p->_min), data);
	}
	else
	{
		StackPush(&(p->_data), data);
	}
}
void QueueandStackPop(QueueandStack* p)
{
	assert(p);
	if (NULL == p )
		return;
	StackPop(&(p->_data));
	StackPop(&(p->_min));
}
DataType QueueandStackTop(QueueandStack* p)
{
	assert(p);
	if (NULL == p)
		return 0;
	else
	return	StackTop(&(p->_data));
}
int QueueandStackSize(QueueandStack* p)
{
	assert(p);
	return StackSize(&(p->_data));
}
int QueueandStackEmpty(QueueandStack* p)
{
	assert(p);
	return StackEmpty(&(p->_data));
}
void StackInit(Stack* ps)
{
	assert(ps);
	ps->top = 0;
}
void StackPush(Stack *ps, DataType data)
{
	assert(ps);
	if (ps->top == MAXSIZE - 1)
	{
		printf("ÂúÁË");
		return;
	}
	else
		ps->arr[ps->top++] = data;
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
	return ps->arr[ps->top - 1];
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