#include "Snake.h"
void CreatWall()
{
	int i = 0;
	for (i = 0; i <= 58; i+=2)
	{
		SetPos(i, 0);
		printf(WALL);
	}
	for (i = 0; i <= 58; i += 2)
	{
		SetPos(i, 28);
		printf(WALL);
	}
	for (i = 1; i <= 28; i++)
	{
		SetPos(0, i);
		printf(WALL);
	}
	for (i = 1; i <= 28; i++)
	{
		SetPos(58, i);
		printf(WALL);
	}
	SetPos(80, 20);
}
void GameHelp()
{
	SetPos(65, 12);
	printf("用↑，↓，←，→来控制方向");
	SetPos(65, 13);
	printf("按空格暂停，按F1加速，按F2减速");
	SetPos(65, 14);
	printf("按ESC退出");
}
void GameStart(pSnake ps)
{
	WelcomeToGame();
	CreatWall();
	InitSnake(ps);
	CreateFood(ps);
	GameHelp();
	
	ps->_Addscore = 1;
	ps->_Dir = RIGHT;
	ps->_Sleeptime = 200;
	ps->_Status = OK;
	ps->_Totalscore = 0;
	GameRun(ps);
	GameEnd(ps);
	

	

}

void WelcomeToGame()
{
	system("mode con cols=100 lies=30");
	SetPos(45, 14);
	printf("welcome to Snake\n");
	SetPos(100, 30);
	system("pause");
	system("cls");
	SetPos(45, 14);
	printf("use up,down,left,right to control snake\n");
	SetPos(45, 15);
	printf("different speed diffferent score\n");
	SetPos(100, 30);
	system("pause");
	system("cls");
}
void SetPos(int x, int y)
{
	COORD pos = { 0 };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle,pos);

}
pSnakeNode BuyNode()
{
	pSnakeNode pNewNode = (pSnakeNode)malloc(sizeof(Snake));
	pNewNode->x = 0;
	pNewNode->y = 0;
	pNewNode->next = NULL;
	return pNewNode;
}
void InitSnake(pSnake ps)
{
	pSnakeNode frist = BuyNode();
	pSnakeNode Cur  = NULL;
	int i = 0;
	frist->x = INIT_X;
	frist->y = INIT_Y;
	for (i = 0; i < 4; i++)
	{
		Cur = BuyNode();
		Cur->y = frist->y;
		Cur->x = frist->x + 2;
		Cur->next = frist;
		frist = Cur;
	}
	while (Cur)
	{
		SetPos(Cur->x, Cur->y);
		printf(FOOD);
		Cur = Cur->next;
	}
	ps->_pSnake = frist;
}
void CreateFood(pSnake ps)
{
	pSnakeNode food = BuyNode();
	pSnakeNode Cur = ps->_pSnake;
	srand((unsigned)(time(NULL)));
	food->y = rand() % 26 + 1;
	do
	{
		food->x = rand() % 55 + 2;
	} while (food->x % 2 != 0);
	if (food->x == Cur->x&&food->y == Cur->y)
	{
		CreateFood(ps);
		return;
	}
	ps->_pFood = food;
	SetPos(food->x, food->y);
	printf(FOOD);
	SetPos(100, 20);
	
}
void Pause()
{
	while (1)
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}
}
void GameRun(pSnake ps)
{
	do{
		if (GetAsyncKeyState(VK_UP) && ps->_Dir != DOWN)
		{
			ps->_Dir = UP;
		}
		if (GetAsyncKeyState(VK_DOWN) && ps->_Dir != UP)
		{
			ps->_Dir = DOWN;
		}
		if (GetAsyncKeyState(VK_LEFT) && ps->_Dir != RIGHT)
		{
			ps->_Dir = LEFT;
		}
		if (GetAsyncKeyState(VK_RIGHT) && ps->_Dir != LEFT)
		{
			ps->_Dir = RIGHT;
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			Pause();
		}
		if (GetAsyncKeyState(VK_F1))
		{
			if (ps->_Sleeptime>40)
			{
				ps->_Sleeptime-=20 ;
				ps->_Addscore += 2;
			}
		}
		if (GetAsyncKeyState(VK_F2))
		{
			if (ps->_Sleeptime <= 300)
			{
				ps->_Sleeptime += 20;
				if (ps->_Addscore > 1)
				{
					ps->_Addscore -= 2;
				}
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			ps->_Status = END;
			break;
		}
		SetPos(65, 10);
		printf("当前加分：%d  ", ps->_Addscore);
		Hidecursor();
		Sleep(ps->_Sleeptime);
		SnakeMove(ps);
        KILLBYSELF(ps);
		KILLBYWALL(ps);

	} while (ps->_Status==OK);

}
int NextIsFood(pSnakeNode pn, pSnake ps)
{
	if ((pn->x == ps->_pFood->x) &&( pn->y==ps->_pFood->y))
	{
		return 1;
	 }
	 return 0;
}
void SnakeMove(pSnake ps)
{
	SetPos(65, 8);
	printf("总分：%d ", ps->_Totalscore);
	pSnakeNode pNewNode = BuyNode();
	switch (ps->_Dir)
	{
	case UP:
	{
			   pNewNode->x = ps->_pSnake->x;
			   pNewNode->y = ps->_pSnake->y - 1;
			   if (NextIsFood(pNewNode, ps))
			   {
				   EatFood(ps, pNewNode);
			   }
			   else
			   {
				   NoFood(ps, pNewNode);
			   }
	}
		break;
	case DOWN:
	{
				 pNewNode->x = ps->_pSnake->x;
				 pNewNode->y = ps->_pSnake->y + 1;
				 if (NextIsFood(pNewNode, ps))
				 {
					 EatFood(ps, pNewNode);
				 }
				 else
				 {
					 NoFood(ps, pNewNode);
				 }
	}
		break;
	case 3:
	{
			  pNewNode->x = ps->_pSnake->x - 2;
			  pNewNode->y = ps->_pSnake->y;
			  if (NextIsFood(pNewNode, ps))
			  {
				  EatFood(ps, pNewNode);
			  }
			  else
			  {
				  NoFood(ps, pNewNode);
			  }
	}
		break;
	case 4:
	{
			  pNewNode->x = ps->_pSnake->x + 2;
			  pNewNode->y = ps->_pSnake->y;
			  if (NextIsFood(pNewNode, ps))
			  {
				  EatFood(ps, pNewNode);
			  }
			  else
			  {
				  NoFood(ps, pNewNode);
			  }
	}
		break;
	}
	Sleep(100);
}
void EatFood(pSnake ps, pSnakeNode pn)
{
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	SetPos(ps->_pSnake->x, ps->_pSnake->y);
	printf(FOOD);
	ps->_Totalscore += ps->_Addscore;
	CreateFood(ps);
}
void NoFood(pSnake ps, pSnakeNode pn)
{
	pSnakeNode cur = NULL;
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	cur = ps->_pSnake;
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		printf(FOOD);
		cur = cur->next;
	}
	SetPos(cur->x, cur->y);
	printf(FOOD);
	SetPos(cur->next->x, cur->next->y);
	printf(" ");
	free(cur->next);
	cur->next = NULL;

}
int KILLBYSELF(pSnake ps)
{
	pSnakeNode cur = NULL;
	cur = ps->_pSnake->next;
	while (cur)
	{
		if (cur->x == ps->_pSnake->x&&cur->y == ps->_pSnake->y)
		{
			ps->_Status = KILL_BY_SELF;
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}
int KILLBYWALL(pSnake ps)
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 58 || ps->_pSnake->y == 0 || ps->_pSnake->y == 28)
	{
		ps->_Status = KILL_BY_WALL;	
		return 1;
	}
	return 0;
}
void GameEnd(pSnake ps)
{
	pSnakeNode Cur = ps->_pSnake;
	switch (ps->_Status)
	{
	case END:
		SetPos(25, 14);
		printf("退出游戏");
		SetPos(100,20);
		break;
	case KILL_BY_SELF:
		SetPos(25, 14);
		printf("你自杀了");
		SetPos(100, 20);
		break;
	case KILL_BY_WALL:
		SetPos(25, 14);
		printf("你撞墙了");
		SetPos(100, 20);
		break;
	}
	while (Cur)
	{
		pSnakeNode del = Cur;
		Cur = Cur->next;
		free(del);
	}
}
void Hidecursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = 0;
	SetConsoleCursorInfo(handle, &CursorInfo);
}