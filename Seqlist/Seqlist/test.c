#include "Seqlist.h"
void test()
{
	Seqlist seq;
	InitSeqlist(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 5);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 2);
	PushBack(&seq, 6);
	PushBack(&seq, 9);
	PushBack(&seq, 7);
	PrintSeqlist(&seq);
	SelectSortOP(&seq);
	PrintSeqlist(&seq);
}
int main()
{
	test();
	return 0;
}