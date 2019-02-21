#include<stdio.h>
int jumpfloor1(int n)//递归  但是时间复杂度高 
{
	if (n == 1 || n == 2)
		return n;
	else
		return jumpfloor1(n - 1) + jumpfloor1(n - 2);
}
int jumpfloor2(int n)//迭代 建议使用该方法
{
	int f = 1;
	int s = 2;
	int ret = 0;
	int i;
	if (n == 1 || n == 2)
	{
		return n;
	}
	else
	{
		for (i = 3; i <= n; i++)
		{
			ret = f + s;
			f = s;
			s = ret;
		}
		return ret;
	}
}
int jumpfloor3(int n)//递归 青蛙可以跳1，2，3....,n个台阶
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return 2 *jumpfloor3(n - 1);
	}
}
int jumpfloor4(int n)//迭代
{
	int ret = 0;
	int i;
	int f = 1;
	if (n == 1)
	{
		return 1;
	}
	else
	{
		for (i = 2; i <= n; i++)
			ret = 2 * f;
		    f = ret;
	}
	return ret;
}
long long jumpfloor5(long long  first,long long second,int N)
{
	if (3 > N)
		return 1;
	if (3 == N)
		return first + second;
	return jumpfloor5(second, first + second, N - 1);
}
int main()
{
	printf("%d\n", jumpfloor5(1,1,49));
}