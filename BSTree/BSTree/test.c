#include"BSTree.h"
int main()
{
	int i = 0;
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BSTreeNode pRoot;
	InitBSTreeNode(&pRoot);
	for (i = 0; i < sz; i++)
	{
		InsertBSTreeNode(&pRoot, arr[i]);
	}
	return 0;
}