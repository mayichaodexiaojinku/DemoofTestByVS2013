#include<stdio.h>
#include<string.h>
#include<assert.h>
void Remove(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char a = *left;
		*left = *right;
		*right = a;
		left++;
		right--;
	}
}
void RightLoopMove(char *p, unsigned short s)
{
	assert(p);
	int  len = strlen(p);
	Remove(p, p+len-1);
	Remove(p, p + s-1);
	Remove(p+s, p + len - 1);

}
void LeftLoopMove(char *p, unsigned short s)
{
	assert(p);
	int  len = strlen(p);
	Remove(p, p + len - 1);
	Remove(p, p +len-s-1);
	Remove(p + len - s , p + len - 1);

}
int main()
{
	char a[] = "abcdefghi";
	char b[] = "abcdefghi";
	RightLoopMove(a, 2);
	printf("%s\n", a);
	LeftLoopMove(b, 2);
	printf("%s\n", b);
	return 0;
}