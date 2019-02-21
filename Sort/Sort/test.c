#include"Sort.h"
int main()
{
	int arr[] = { 9, 5, 7, 2, 8, 4, 3, 6, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(&arr, sz);
	//InsertSort(&arr, sz);
    //	ShellSort(&arr, sz);
	//BubbleSort(&arr, sz);
    //	SelectSort(&arr, sz);
	//HeapSort(&arr, sz);
	//QuickSortNor(&arr, sz);
	//MergeSort(&arr, sz);
	QuickSort(&arr, 0, 10);
 	PrintSort(&arr, sz);
	return 0;
}
