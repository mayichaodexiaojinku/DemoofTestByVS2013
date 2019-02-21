#include<stdio.h>
#include<assert.h>
char *my_strncpy(char * dest, const char * src, int n)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (n)
	{
		*dest++ = *src++;
		n--;
	}
	if (*(dest - 1) != '\0')
	{
		*dest = '\0';
	}
	return ret;
}
int main()
{
	char *a = "abcd";
	char b[10] = { 0 };
	printf("%s \n", my_strncpy(b, a, 3));
	return 0;
}