#include<stdio.h>
#include<assert.h>
char* my_strcpy(char *dest, const char* src)
{
	char *ret = dest;
	assert(dest);
	assert(src);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char a[] = {0};
	char *b = "abcdef";
	my_strcpy(a, b);
	printf("%s\n", a);
	return 0;

}