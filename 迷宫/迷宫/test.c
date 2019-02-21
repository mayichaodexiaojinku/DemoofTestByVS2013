#include"Maze.h"
int main()
{
	testMaze();
	return 0;
}
void testMaze()
{
	int arr[ROW][COL] = { { 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 }
	};
	Maze m;
	Position enter;
	InitMaze(&m, arr);
	PrintMaze(&m);
	enter.x = 5;
	enter.y = 2;
	PassMaze(&m, enter);
	PrintMaze(&m);
}