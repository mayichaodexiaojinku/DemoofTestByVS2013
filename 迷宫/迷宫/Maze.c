#include  "Maze.h"

void  InitMaze(Maze* m, int arr[ROW][COL])
{
	assert(m);
	int i = 0;
	int j = 0;
	for ( i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			m->tmp[i][j] = arr[i][j];
		}
	}
}
void PrintMaze(Maze* m)
{
	assert(m);
	int i = 0;
	int j = 0;
	for (i=0; i < ROW; i++)
	{
		for (j=0; j < COL; j++)
		{
			printf("%d ",m->tmp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int IsValidEnter(Maze* m, Position enter)
{
	if (0 == enter.x || 0 == enter.y || ROW - 1 == enter.x || COL - 1 == enter.y)
	{
		if (1==m->tmp[enter.x][enter.y])
		{
			return 1;
		}
	}
	return 0;
}
void PassMaze(Maze* m, Position enter)
{
	Stack path;
	Stack shortPath;
	if (!IsValidEnter(m, enter))
	{
		printf("不是有效入口");
		return;
	}
	StackInit(&path);
	StackInit(&shortPath);
	_GetMazeShortPath(m, enter, enter,&path, &shortPath);
}
void _GetMazeShortPath(Maze* m, Position cur, Position enter, Stack* path, Stack* shortPath)
{
	Position next;
	if (IsExit(cur, enter))
	{
		StackPush(path, cur);
		if (StackSize(path) < StackSize(shortPath) || StackEmpty(shortPath))
		{
			SaveShortPath(path, shortPath);
		}
		StackPop(path);
		return;
	}
	if (StackEmpty(path))
	{
		m->tmp[enter.x][enter.y] = 2;
	}
	StackPush(path,cur);
	next = cur;
	next.x -= 1;
	if (IsNextPass(m, cur, next))
	{
		m->tmp[next.x][next.y] = m->tmp[cur.x][cur.y]+1;
		_GetMazeShortPath(m, next, enter, path, shortPath);
	}
	next = cur;
	next.y-= 1;
	if (IsNextPass(m, cur, next))
	{
		m->tmp[next.x][next.y] = m->tmp[cur.x][cur.y] + 1;
		_GetMazeShortPath(m, next, enter, path, shortPath);
	}
	next = cur;
	next.y += 1;
	if (IsNextPass(m, cur, next))
	{
		m->tmp[next.x][next.y] = m->tmp[cur.x][cur.y] + 1;
		_GetMazeShortPath(m, next, enter, path, shortPath);
	}
	next = cur;
	next.x += 1;
	if (IsNextPass(m, cur, next))
	{
		m->tmp[next.x][next.y] = m->tmp[cur.x][cur.y] + 1;
		_GetMazeShortPath(m, next, enter, path, shortPath);
	}
	StackPop(path);

}
void SaveShortPath(Stack* path, Stack* shortPath)
{
	int i = 0;
	for (i = 0; i < StackSize(path); i++)
	{
		shortPath->arr[i] = path->arr[i];
	}
}

/*
void PassMaze(Maze* m, Position enter)
{
	assert(m);
	Stack s;
	Position cur, next;
	if (!IsValidEnter(m, enter))
	{
		printf("不是有效入口");
			return;
	}
	StackInit(&s);
	StackPush(&s, enter);
	while (!StackEmpty(&s))
	{
		cur = StackTop(&s);
		m->tmp[cur.x][cur.y] = 2;
		if (IsExit(cur, enter))
		{
			return;
		}
		next = cur;
		next.x -= 1;
		if (IsPass(m, next))
		{
			StackPush(&s, next);
			continue;
		}
		next = cur;
		next.y-= 1;
		if (IsPass(m, next))
		{
			StackPush(&s, next);
			continue;
		}
		next = cur;
		next.y+= 1;
		if (IsPass(m, next))
		{
			StackPush(&s, next);
			continue;
		}
		next = cur;
		next.x+= 1;
		if (IsPass(m, next))
		{
			StackPush(&s, next);
			continue;
		}
		m->tmp[cur.x][cur.y] = 3;
		StackPop(&s);
	}
}
*/
int IsExit(Position pos, Position enter)
{
	if (0 == pos.x || 0 == pos.y || ROW - 1 == pos.x || COL - 1 == pos.y)
	{
		if (enter.x != pos.x&&enter.y != pos.y)
		{
			return 1;
		}
	}
	return 0;
}
int	IsPass(Maze * m, Position pos)
{
	if (pos.x > 0 && pos.x<=ROW - 1 && pos.y>0 && pos.y <=COL - 1)
	{
		if (1 == m->tmp[pos.x][pos.y])
		{
			return 1;
		}
	}
	return 0;
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
		printf("满了");
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
		printf("空的");
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
int	IsNextPass(Maze * m, Position cur,Position next)
{
		if (next.x > 0 && next.x <= ROW - 1 && next.y>0 && next.y <= COL - 1)
		{
			if (1 == m->tmp[next.x][next.y] || m->tmp[next.x][next.y]>m->tmp[cur.x][cur.y])
			{
				return 1;
			}
		}
		return 0;
}