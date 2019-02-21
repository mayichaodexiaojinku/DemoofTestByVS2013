#include<stdio.h>
#include<assert.h>
char* my_strcat(char*dest, const char *src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	while(*dest != '\0')
	{
		dest++;
	}
	while(*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char a[20] = "hello ";
	char *b = "wrlod";
	my_strcat(a, b);
	printf("%s\n", a);
	return 0;

}