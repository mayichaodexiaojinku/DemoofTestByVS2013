#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *arr = NULL;
	int i;
	arr = (int *)malloc(10 * sizeof(int));
	if (arr != NULL)
	{
		for (i = 0; i < 10; i++)
		{
			arr[i] = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(arr+i));
		}
	}
	else
	{
		printf("%s\n", strerror(errno));
	}
	free(arr);
	arr = NULL;
	return 0;
}
int main()
{
	int *arr = NULL;
	int i;
	arr = (int *)calloc(10 , sizeof(int));
	if (arr != NULL)
	{

		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(arr + i));
		}
	}
	else
	{
		printf("%s\n", strerror(errno));
	}
	free(arr);
	arr = NULL;
	return 0;
}
int main()
{
	int *arr = NULL;
	int i;
	int *tmp = NULL;
	arr = (int *)calloc(10 , sizeof(int));
       for (i = 0; i < 10; i++)
		{
			printf("%d ", *(arr + i)=i);
		}
	   tmp = (int *)realloc(arr, 20 * sizeof(int));
	   if (tmp != NULL)
	   {
		   arr = tmp;
	   }
	free(arr);
	arr = NULL;
	return 0;
}