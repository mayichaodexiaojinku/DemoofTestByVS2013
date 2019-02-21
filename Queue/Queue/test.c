#include"Queue.h"
int main()
{
	TestQueue();
	return 0;
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("front=%d ", QueueFront(&q));
	printf("size=%d ", QueueSize(&q));
	printf("Rear=%d ", QueueRear(&q));
	
	return;

}