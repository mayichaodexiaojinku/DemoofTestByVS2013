#include<stdio.h>
void reverse_string(char * str)
{ 
	if (*str == '\0')
		printf("%c", *str);
	else
	{
		reverse_string(++str);
		printf("%c", *(--str));
	}
}
int main()
{
	char a[] = "abcdef";
    reverse_string(a);
    return 0;
}