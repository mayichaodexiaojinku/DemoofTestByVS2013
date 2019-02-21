#include"Sort.h"
void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
void InsertSort(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		int end = i - 1;
		int key = arr[i];
		while (end >= 0 && key < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
 }
void PrintSort(int *arr,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void ShellSort(int* arr, int size)
{
	int i;
	int pos = 3;
	while (pos>0)
	{
		for (i = pos; i < size; i++)
		{
			int end = i - pos;
			int key = arr[i];
			while (end >= 0 && key < arr[end])
			{
				arr[end + pos] = arr[end];
				end-=pos;
			}
			arr[end + pos] = key;
		}
		pos--
			;
	}
}
void BubbleSort(int* arr, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
		}
	}
}
void SelectSort(int* arr, int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int minPos = begin;
		int maxPos = begin;
		int i = begin + 1;
		while (i <= end)
		{
			if (arr[i] > arr[maxPos])
				maxPos = i;
			if (arr[i] < arr[minPos])
				minPos = i;
			i++;
		}
		if (maxPos != end)
			Swap(&arr[end], &arr[maxPos]);
		if (minPos == end)
			minPos = maxPos;
		if (minPos != begin)
	     	Swap(&arr[begin], &arr[minPos]);
		begin++;
		end--;
	}
}
void HeapSort(int* arr, int size)
{
	int end = size - 1;
	int root = ((size - 2) >> 2);
	for (; root >= 0; root--)
		HeapAdjust(arr, size, root);
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		HeapAdjust(arr, end, 0);
		end--;
	}
}
void HeapAdjust(int* arr, int size, int parent)
{
	int child = (parent << 1) + 1;	
	while (child < size)
	{
		if (arr[child] < arr[child + 1])
			child += 1;
		if (arr[parent] < arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = (parent << 1) + 1;
		}
		else
			return;
	}
}
void QuickSort(int* arr, int left, int right)
{
	if (right - left > 1)
	{
		int div = Partion1(arr, left, right);
		QuickSort(arr, left, div-1);
		QuickSort(arr, div, right);
	}
}
int Partion1(int* arr, int left, int right)
{
	int Index = GetMiddleIndex(arr, left, right);
    int begin = left;
	int end = right - 1;
	if (Index != right - 1)
		Swap(&arr[Index], &arr[right - 1]);
	int key = arr[right - 1];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin <  end)
			Swap(&arr[begin], &arr[end]);
	}
	if (begin != right - 1)
		Swap(&arr[begin], &arr[right - 1]);
	return begin;
}
int Partion2(int* arr, int left, int right)
{
	int Index = GetMiddleIndex(arr, left, right);
	int begin = left;
	int end = right - 1;
	if (Index != right - 1)
		Swap(&arr[Index], &arr[right - 1]);
	int key = arr[right - 1];
	while (begin < end )
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		if (begin < end)
		{
			arr[end] = arr[begin];
			end--;
		}
		while (begin < end && arr[end] >= key)
			end--;
		if (begin < end)
		{
			arr[begin] = arr[end];
			begin++;
		}
	}
	arr[begin] = key;
	return begin;
}
int Partion3(int* arr, int left, int right)
{
	int Index = GetMiddleIndex(arr, left, right);
	if (Index != right - 1)
		Swap(&arr[Index], &arr[right - 1]);
	int key = arr[right - 1];
	int cur = left;
	int prev = cur - 1;
	while (cur < right)
	{
		if (arr[cur] <= key && ++prev != cur)
			Swap(&arr[cur], &arr[prev]);
		++cur;
	}
	if (++prev != right - 1 && prev < right)
	     Swap(&arr[prev], &arr[right - 1]);
	return prev;
}
int GetMiddleIndex(int* arr, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (arr[left] < arr[right - 1])
	{
		if (arr[mid] < arr[left])
			return left;
		else if (arr[mid] > arr[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (arr[mid] > arr[left])
			return left;
		else if (arr[mid] < arr[right - 1])
			return right - 1;
		else
			return mid;
	}
}
void QuickSortNor(int* arr, int size)
{
	int left, right;
	Stack s;
	StackInit(&s);
	StackPush(&s, size);
	StackPush(&s, 0);
	while (!StackEmpty(&s))
	{
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);
		if (right -left >1)
		{
			int boundary = Partion1(arr, left, right);
			//排左侧-->将右半部分的区间压栈
			StackPush(&s, right);
			StackPush(&s, boundary + 1);
			//排右侧-->将左半部分的区间压栈
			StackPush(&s, boundary);
			StackPush(&s, left);
		}
	}
}
void MergeSort(int* arr, int size)
{
	int* temp = (int*)malloc(size*sizeof(int));
	if (NULL == temp)
	{
		assert(0);
		return;
	}
	_MergeSort(arr, 0, size, temp);  
	free(temp);
}
void _MergeSort(int* arr, int left, int right, int* temp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, temp);
		_MergeSort(arr, mid,  right, temp);
		MegerData(arr, left, mid, right, temp);
		memcpy(arr+left, temp+left, (right - left)*sizeof(int));
	}
}
void MegerData(int* arr, int  left, int mid, int  right, int* temp)
{
	int begin1 = left; int end1 = mid;
	int begin2 = mid; int end2 = right;
	int Index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (arr[begin1] <= arr[begin2])
			temp[Index++] = arr[begin1++];
		else
			temp[Index++] = arr[begin2++];
	}
	while (begin1 < end1)
	{
		temp[Index++] = arr[begin1++];
	}
	while (begin2 < end2)
	{
		temp[Index++] = arr[begin2++];
	}
}
void MergeSortNor(int* arr, int size)
{
	int* temp = (int*)malloc(size*sizeof(int));
	if (NULL == temp)
	{
		assert(0);
		return;
	}
	int i = 0;
	int gap = 1;
	while (gap < size)
	{
		for (i = 0; i < size; i = 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid > size)
				mid = size;
			if (right > size)
				right = size;
			MegerData(arr, left, mid, right, temp);
		}
		gap << 1;
		memcpy(arr, temp, size*sizeof(int));
	}
}
