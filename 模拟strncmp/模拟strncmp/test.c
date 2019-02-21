#include<stdio.h>
#include<assert.h>
int my_strncmp(const char*dest, const char* src, int n)
{
	assert(dest);
	assert(src);
	while (n--)
	{
		if (*dest == *src)
		{
			dest++;
			src++;
		}
		else
		{
			if ((*dest - *src) > 0)
				return 1;
			else if ((*dest - *src) < 0)
				return -1;
			else
				return 0;
		}
	}
}
int main()
{
	char*a = "abcdsd";
	char*b = "abcd";
    printf("%d \n", my_strncmp(a, b, 6));
	return 0;
}