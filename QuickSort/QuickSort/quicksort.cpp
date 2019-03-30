#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;
int GetMidIndex(int* arr,int left, int right)
{
	int mid = left + (right - left) >> 1;
	if (arr[left] < arr[right])
	{
		if (arr[mid] < arr[left])
			return left;
		if (arr[mid] > arr[right])
			return right;
	}
	else
	{
		if (arr[mid] > arr[left])
			return left;
		if (arr[mid] < arr[right])
			return right;
	}
	
}
void swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
void QuickSortNor(int *arr, int left, int right)
{
	stack<int> s;
	s.push(left);
	s.push(right);
	while (s.empty()){
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();
		int Index = Partion(arr, left, right);
		if (Index - 1 > left)
		{
			s.push(left);
			s.push(Index - 1);
		}
		if (Index + 1 < right)
		{
			s.push(Index + 1);
			s.push(right);
		}

	}
}
void Quicksort(int *arr, int left, int right)
{
	if (right - left > 1)
	{
		int div = Partion(arr, left, right);
		Quicksort(arr, left, div-1);
		Quicksort(arr, div+1, right);
	}
}
int Partion(int* arr, int left, int right)
{
	int mid = GetMidIndex(arr, left, right);
	if (mid != right)
		swap(&arr[mid], &arr[right]);
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
int Partion2(int* arr, int left, int right)
{
	int mid = GetMidIndex(arr, left, right);
	if (mid != right)
		swap(&arr[mid], &arr[right]);
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
int Partion3(int* arr, int left, int right)
{
	int mid = GetMidIndex(arr,left,right);
	if (mid != right)
	   swap(&arr[mid], &arr[right]);
	int key = arr[right];
	int cur = left;
	int pre = cur - 1;
	while (cur < right){
		if(arr[cur] <= key && ++pre != cur){
			swap(&arr[cur], &arr[pre]);
		}
		++cur;
    }
	if (++pre != cur && pre != right)
		swap(&arr[pre], &arr[right]);
	return pre;
}
int main()
{
	int arr[] = { 7, 2, 5, 6, 3, 1, 8, 9, 0 ,4};
	int sz = sizeof(arr) / sizeof(arr[0]);
	//Quicksort(&arr, 0, sz-1);
	QuickSortNor(arr, 0, sz - 1);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}