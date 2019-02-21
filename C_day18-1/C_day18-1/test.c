#include<stdio.h>
#include<stdlib.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x*y;
}
int Div(int x, int y)
{
	return x / y;
}
int main(int argc, char *argv[], char *envp[])
{
	int x = 0;
	int y = 0;
	int ret = 0;
	if (argc != 4)
	{
		printf("²ÎÊıÓĞÎó\n");
		return 0;
	}
	x = atoi(argv[2]);
	y = atoi(argv[3]);
	switch (*(argv[1] + 1))
	{
	case 'a':
		ret = Add(x, y);
		break;
	case 's':
		ret = Sub(x, y);
		break;
	case 'm':
		ret = Mul(x, y);
		break;
	case 'd':
		ret = Div(x, y);
		break;
	}
	printf("%d\n", ret);
	return 0;
}