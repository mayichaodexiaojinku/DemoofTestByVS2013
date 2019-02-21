#include<stdio.h>
#include<assert.h>
char* my_strchr(const char* src, char dest)
{
	assert(src);
	while (*src)
	{
		if (*src == dest)
			return src;
		src++;
	}
	return 0;
}
int main()
{
	char* a = "hello world";
	printf("%s\n", my_strchr(a, 'z'));
	return 0;
}