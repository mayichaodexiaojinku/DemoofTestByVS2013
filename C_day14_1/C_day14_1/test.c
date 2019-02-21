#include<stdio.h>
#include<string.h>
#include<assert.h>
int  length(const char str[])
{
	int count=0;
	assert(str != NULL);
	while (*str++ != '\0')
	{
		count++;
	}
	return count;
}
void reverse(char *p, char *q)
{
	while ( p < q )
	{
		char t = *p;
		*p = *q;
		*q = t;
		q--;
		p++;
	}
}
void turnleft(char str[], int n)
{
	reverse(str, str + n - 1);
	reverse(str + n, str + length(str) -1);
	reverse(str, str + length(str) - 1);
}
int main()
{
	char str[]= "abcdefg";
	turnleft(str, 2);
    printf("%s\n", str);
	return 0;
}