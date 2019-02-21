#include<stdio.h>
#include<assert.h>
char *my_strncat(char * dest, const char * src, int n)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (n--)
	{
		*dest++ = *src++;

	}
	if (*(dest - 1) != '\0')
	{
		*dest = '\0';
	}
	return ret;
}
int main()
{
	char *a = "efgh";
	char b[10] = "abcd";
	printf("%s \n", my_strncat(b, a, 4));
	return 0;
}