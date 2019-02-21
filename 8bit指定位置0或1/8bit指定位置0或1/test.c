#include<stdio.h>
void bit_set(unsigned char* p, unsigned char pos, int flag)
{
	if (flag == 1)
	{
		*p |= (1 << (pos- 1));

	}
	else if (flag == 0)
	{
		*p &= (~(1 << (pos - 1)));
	}
	else
	{
		return;
	}
}

int main()
{
	unsigned char a = 15;
	bit_set(&a, 5, 1);
	printf("%x\n", a);
	bit_set(&a, 5, 0);
	printf("%x\n", a);
	return 0;

}