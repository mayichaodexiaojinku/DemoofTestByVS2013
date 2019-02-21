#include<stdio.h>
#include<string.h>

void reverse_all(char *star, char *end) 
{
	while (star<end)
	{
		*star = *star^*end;
		*end = *star^*end;
		*star = *star^*end;
		star++;
		end--;
	}
}
int main()
{
	char a[] = "student a am i";
	char *p = a;
	char *q = p;
	reverse_all(a, a + strlen(a) - 1);
	while (*q != '\0'&&*p != '\0')
	{
		if (*q == ' ')
		{
			reverse_all(p, q - 1);
			q++;
			p = q;

		}
		q++;
	}

	reverse_all(p, q - 1);
	printf("%s", a);
	return 0;


}