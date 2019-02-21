#define _CRT_SECURE_NO_WARNINGS

#include "CommentCovert.h"
void test()
{
	FILE* pfIn= NULL;
	FILE* pfOut = NULL;
	pfIn = fopen("input.c", "r");
	if (pfIn == NULL)
	{
		printf("open file for read");
		exit(EXIT_FAILURE);
	}
	pfOut = fopen("output.c", "w");
	if (pfOut == NULL)
	{
		fclose(pfIn);
        printf("open file for write");
		exit(EXIT_FAILURE);
	}
	DoCommentCovert(pfIn, pfOut);
	fclose(pfIn);
	pfIn = NULL;
	fclose(pfOut);
	pfOut = NULL;
	printf("³É¹¦\n");
}
int main()
{
	test();
	return 0;
}