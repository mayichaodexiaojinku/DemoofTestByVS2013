#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SWAP(n) (((n&(0x55555555)) << 1)|((n >> 1)&(0x55555555))) 
int main()
{
	int a=20;
	int ret;
		ret=SWAP(a);
		printf("%d\n", ret);
    return 0;

}