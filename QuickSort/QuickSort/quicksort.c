#include<stdio.h>
#include<stdlib.h>
void swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
void Quicksort(int *arr, int left, int right)
{
	if (right - left > 1)
	{
		int div = partion2(arr, left, right);
		Quicksort(arr, left, div-1);
		Quicksort(arr, div+1, right);
	}
}
int partion(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int key = arr[right];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin < end)
		{
			swap(&arr[begin], &arr[end]);
		}

	}
	swap(&arr[right], &arr[begin]);
	return begin;
}
int partion2(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int key = arr[right];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		arr[end] = arr[begin];
		while (begin < end && arr[end] >= key)
			end--;
		arr[begin] = arr[end];
	}
	arr[end] = key;
	return begin;
}
int main()
{
	int arr[] = { 7, 2, 5, 6, 3, 1, 8, 9, 0 ,4};
	int sz = sizeof(arr) / sizeof(arr[0]);
	Quicksort(&arr, 0, sz-1);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}