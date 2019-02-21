#include<stdio.h>
#include<assert.h>
char* my_strstr(const char *str, const char* substr)
{
    assert(str);
	assert(substr);
	if (*substr == '\0')
	{
		return str;
	}
	while (*str)
	{
		const char *s1 = str;
		const char *s2 = substr;
		while (*s1&&*s2&&*s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return str;
		}
		str++;
	}
	return NULL;
}

int main()
{
	char a[10] = "abcdefg";
	char *b = "cde";
	char *ret = my_strstr(a, b);
	if (ret != NULL)
		printf("%s\n", ret);
	else
		printf("not found\n");
	return 0;
}