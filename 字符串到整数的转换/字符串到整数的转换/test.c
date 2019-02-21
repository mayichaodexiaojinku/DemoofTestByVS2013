#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<limits.h>
enum State
{
	INVALID,
	VALID
};
enum State S = INVALID;
int my_atoi(const char *p)
{
	int flag = 1;
	long long ret = 0;
	assert(p);
	if (*p == '\0')
	{
		return 0;
	}
	while (isspace(*p))
	{
		p++;
	}
	if (*p == '+')
	{
		p++;
	}
	if (*p == '-')
	{
		p++;
		flag = -1;
	}
	while (*p != '\0')
	{
		if (isdigit(*p))
		{
			ret = ret * 10 + flag*(*p - '0');
			if ((ret > INT_MAX) || (ret < INT_MIN))
			{
				return 0;
			}
		}
		else
		{
			return (int)ret;
		}
		p++;
	}
	S = VALID;
	return (int)ret;
}
int main()
{
	char a[] = "12345";
	int  ret;
	ret = my_atoi(a);
	printf("%d\n", a);
	return 0;
}