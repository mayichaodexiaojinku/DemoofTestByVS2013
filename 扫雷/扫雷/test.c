#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
int menu()
{
	printf("************** welcome to saolei ****************\n");
	printf("****************    1.play   ********************\n");
	printf("****************    0.exit   ********************\n");
	printf("*************************************************\n");
	return 0;
}
int main()
{
	int input = 0;
	char mine[rows][cols] = { 0 };
	char show[rows][cols] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = '0';
			show[i][j] = '*';
		}
	}
	while (1)
	{
		menu();
		printf("��ѡ��-->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game(mine, show);
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������\n");
			break;
		}

	}
	return 0;
}
