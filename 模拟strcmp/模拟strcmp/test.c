#include<stdio.h>
#include<assert.h>
char* my_strcmp(const char *src, const char* dest)
{
	assert(src);
	assert(dest);
	while (*dest&&*src)
	{
		++src;
		++dest;
	}
	return *src - *dest;
		
	
}
int main()
{
	char *a = "abcdef";
	char *b = "abcdefsad";
	int ret = my_strcmp(a, b);
	if (ret > 0)
		printf("1\n");
	else if (ret < 0)
		printf("-1\n");
	else
		printf("0\n");
	return 0;
}
