#include<stdio.h>
#define MAX(a,b) ((a>b)?(a):(b))
int main()
{
	int a = 10;
	int b = 20;
	int ret;
	ret = MAX(a, b);
	printf("%d\n", ret);
	return 0;

}
