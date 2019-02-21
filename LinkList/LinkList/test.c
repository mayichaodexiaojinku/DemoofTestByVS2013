#include "Linklist.h"
void test()
{
	List* plist1;
	InitLinkList(&plist1);
	PushFront(&plist1, 1);
	PushFront(&plist1, 3);
	PushFront(&plist1, 5);
	PushFront(&plist1, 7);
	PushFront(&plist1, 9);
	PrintLinklist(plist1);
	
	
}
int main()
{
	test();
	return 0;
}