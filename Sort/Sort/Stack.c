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
		printf("manle");
		return ;
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
		printf("kongde");
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
//int IsBrackets(char arr[], int i)
//{
//	if ((arr[i] == '(') || (arr[i] == ')') || (arr[i] == '[')
//		|| (arr[i]== ']') || (arr[i] == '{') || (arr[i] == '}'))
//		return 1;
//	else
//		return 0;
//}
//void MacthBrackets(Stack* ps, int size,const char arr[])
//{
//
//	int i = 0;
//	while (i < size)
//	{
//		if (IsBrackets(arr, i))
//		{
//			if ((arr[i] == '(') || (arr[i] == '[') || (arr[i] == '{'))
//			{
//				StackPush(ps, arr[i]);
//				i++;
//				continue;
//			}
//			if ((arr[i] == ')') || (arr[i] == ']') || (arr[i] == '}'))
//			{
//				if (StackEmpty(ps))
//				{
//					printf("ÓÒÀ¨ºÅ±È×óÀ¨ºÅ¶à\n");
//					return;
//				}
//				else if (((StackTop(ps) == '(') && (arr[i] == ')')) ||
//					((StackTop(ps) == '[' ) &&  (arr[i] == ']'))||
//					((StackTop(ps) == '{') && (arr[i] == '}')))
//				{
//					StackPop(ps);
//					i++;
//					continue;
//				}
//				else
//				{
//					printf("À¨ºÅ´ÎĞò²»Æ¥Åä\n");
//					return;
//				}
//			}
//		}
//		else
//		{
//			i++;
//		}
//	}
//	if (!StackEmpty(ps))
//	{
//		printf("×óÀ¨ºÅ±ÈÓÒÀ¨ºÅ¶à\n");
//		return;
//	}
//	else
//	{
//		printf("Æ¥Åä³É¹¦\n");
//		return;
//	}
//}