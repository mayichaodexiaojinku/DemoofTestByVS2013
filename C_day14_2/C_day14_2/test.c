#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
int  length(const char str[])
{
	if (*str == '\0')
		return 0;
	return 1 + length(str + 1);
}
void reverse(char *p, char *q)
{
	while (p < q)
	{
		char t = *p;
		*p = *q;
		*q = t;
		q--;
		p++;
	}
}
int is_turn(char * str, char * buf)
{
	char *p = malloc(length(str) + length(str) + 1);
	strcpy(p, str);
	strcat(p, str);
	if (strstr(p, buf) == NULL)
		return 0;
	else
		return 1;
}

int main()
{
	int i;
	char str[] = "abcdefg";
	char buf[] = "adefgab";
	i=is_turn(str, buf);
	if (i == 1)
	{
		printf("ÊÇ\n");
	}
	else
	{
		printf("²»ÊÇ\n");
	}
	return 0;
}