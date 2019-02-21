#include<stdio.h>
#include<assert.h>
void* my_mommove(void *src, const void* dest, size_t count)
{
	assert(src);
	assert(dest);
	void *ret = src;
	if (src<dest)
	while (count--)
	{
		*(char *)src = *(char *)dest;
		++(char *)src;
		++(char *)dest;

	}
	else
	{
		while (count--)
		{
			*((char *)src + count) = *((char *)dest + count);

		}
	}
	return ret;


}
int main()
{
	char a[20] = { '1', '2', '3', '4' ,'5','6','7'};
	my_mommove(a+3, a+2, 12);
	printf("%s\n", a);
	return 0;
}
