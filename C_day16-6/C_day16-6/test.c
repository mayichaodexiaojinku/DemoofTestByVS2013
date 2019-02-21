#include<stdio.h>
int fact1(int a)
{
	if (a== 1)
		return 1;
	else
		return a * fact1(a - 1);
}
int fact2(int a)
{
	int i;
	int sum = 1;
	for (i = 1; i <= a; i++)
		sum *= i;
	return sum;

}
int main()
{
	int n = 5;
	int ret1 = fact1(n);
	printf("%d\n", ret1);
	int ret2 = fact2(n);
	printf("%d\n", ret2);
	return 0;

}