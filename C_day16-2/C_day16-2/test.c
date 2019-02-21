#include<stdio.h>
int fact(int a,int b)
{
	if (b == 0)
		return 1;
	else if (b == 1)
		return a;
	else
		return a*fact(a, b - 1);
	
}
int main()
{
	int n = 2;
	int k = 5;
	int ret = fact(n, k);
	printf("%d\n", ret);
	return 0;
}