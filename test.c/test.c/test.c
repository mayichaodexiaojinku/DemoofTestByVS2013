#include<stdio.h>
#include<assert.h>
void* my_momcpy(void *src, const void* dest,size_t count)
{
	assert(src);
	assert(dest);
	void *ret = src;
	while (count--)
	{
		*(char *)src = *(char *)dest;
		++(char *)src;
		++(char *)dest;

	}
	return ret;


}
int main()
{
	char a[10] = { 0 };
	char b[10] = { '1', '2', '3', '4' };
	my_momcpy(a, b, 12);
	printf("%s\n", a);
	return 0;
}
