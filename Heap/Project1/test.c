#include"Heap.h"
int main()
{
	TestHeap();
	return 0;
}
void TestHeap()
{
	int arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;
	CreateHeap(&hp, arr, sizeof(arr) / sizeof(arr[0]),Less);
	InsertHeap(&hp, 5);
}