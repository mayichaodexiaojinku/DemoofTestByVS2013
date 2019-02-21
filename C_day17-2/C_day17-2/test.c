#include<stdio.h>
int drink(int n)
{
	static int  i ;
	i = n;
	while (n > 1)
	{
		i += n / 2;
		n = n / 2 + n % 2;

	}
	return i;
}
int main()
{
	int n = 20;
	int ret = drink(n);
	printf("%d\n", ret);
	return 0;
}