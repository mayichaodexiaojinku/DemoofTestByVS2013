#include"Stack.h"

//#if 0
//int main()
//{
//	Stack s;
//	char a[] = "(())abc{[(])}";//�������Ŵ���ƥ�䲻��ȷ
//	char b[] = "(()))abc{[]}";//�����Ŷ���������
//	char c[] = "(()()abc{[]}";//�����Ŷ���������
//	char d[] = "(())abc{[]()}";//��������ƥ����ȷ
//	int sz = strlen(d);
//	StackInit(&s);
//	MacthBrackets(&s, sz, d);
//
//	return 0;
//}
//#endif
typedef enum Calc
{
	ADD,
	SUB,
	MUL,
	DIV,
	DATA
}OPERATOR;
typedef struct Cell
{
	OPERATOR _op;
	int data;
}Cell;

int main()
{
	Cell RPN[] = { { DATA, 12 }, { DATA, 3 }, { DATA, 4 }, { ADD, 0 }, { MUL, 0 }, { DATA, 6 }, { SUB, 0 },{ DATA, 8 },{ DATA,2 },
	{ DIV, 0 }, { ADD, 0 } };
	int sz = (sizeof(RPN) / sizeof(RPN[0]));
	printf("%d  ", CalcRPN(RPN,sz));
}
int CalcRPN(Cell RPN[], int sz)
{
	int i = 0;
	Stack s;
	StackInit(&s);
	for (; i < sz; i++)
	{
		if (DATA == RPN[i].data)
			StackPush(&s, RPN[i].data);
		else
		{
			int left; int right;
			right = StackTop(&s);
			StackPop(&s);
			left = StackTop(&s);
			StackPop(&s);
			switch (RPN[i]._op)
			{
			case ADD:
				StackPush(&s, left + right);
				break;
			case SUB:
				StackPush(&s, left - right);
				break;
			case MUL:
				StackPush(&s, left * right);
				break;
			case DIV:
				if (0 == right)
				{
					printf("perror");
				}
				StackPush(&s, left / right);
				break;
			}
		}

	}
	return StackTop(&s);
}