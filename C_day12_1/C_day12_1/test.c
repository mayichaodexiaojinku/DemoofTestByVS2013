#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 31;
	int m = 0;
	int sum = 0;
	while (value)
	{
		m = value & 1;
		value = value >> 1;
		sum += m*pow(2, i);
		i--;
	}
	return sum;
}
int main()
{
	unsigned long  int a;
	a = reverse_bit(25);
	printf("%u\n", a);
	return 0;
}