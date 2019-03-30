#include "Linklist.hpp"
void test()
{
	List* plist1;
	InitLinkList(&plist1);
	PushFront(&plist1, 1);
	PushFront(&plist1, 2);
	PushFront(&plist1, 3);
	PushFront(&plist1, 4);
	PushFront(&plist1, 5);
	PushFront(&plist1, 6);
	PrintLinklist(SwapPairs(&plist1));
	
	
}
int main()
{
	test();
	return 0;
}