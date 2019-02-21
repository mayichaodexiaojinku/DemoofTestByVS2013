#include<stdio.h>
int digui(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return digui(n-2)+digui(n - 1);
}
int diedai(int n)
{
	int f = 1;
	int b = 1;
	int ret;
	while (n > 2)
	{
		n -= 1;
		ret = b;
		b = f;
		f = b + ret;
	}

	return  f;
}
	int main()
	{
	int n =30;
	int ret1=digui(n);
	int ret2=diedai(n);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	return 0;
    }