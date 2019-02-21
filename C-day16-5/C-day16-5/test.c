#include<stdio.h>
#include<assert.h>
int my_strlen1(const char *a)
{
	assert(a);
	int i;
	for (i = 0; a[i] != '\0'; i++)
		;
	return i;
}
int my_strlen2(const char * a)
{
	assert(a);
	if (*a == '\0')
		return 0;
	else
		return 1 + my_strlen2(a + 1);
}
int main()
{
	char a[] = "abcdef";
	int ret1 = my_strlen1(a);
	printf("%d\n", ret1);
	int ret2 = my_strlen2(a);
	printf("%d\n", ret2);
	return 0;
}