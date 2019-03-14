#include "stdio.h"
#include "string.h"
#include "stdio.h"
#include "seqqueue.h"

void main()
{
	int i, a[10];
	SeqQueue *queue = NULL;

	queue = SeqQueue_Create(10);

	//向队列中放元素
	for (i = 0; i<10; i++)
	{
		a[i] = i + 1;
		SeqQueue_Append(queue, &a[i]);
	}

	printf("the header of queue: %d \n", *((int *)SeqQueue_Header(queue)));
	printf("the length of queue: %d \n", SeqQueue_Length(queue));
	printf("the capacity of queue: %d \n", SeqQueue_Capacity(queue));

	//删除队列
	while (SeqQueue_Length(queue) > 0)
	{
		printf("%d \n", *((int *)SeqQueue_Retrieve(queue)));
	}

	//
	SeqQueue_Destroy(queue);

	getchar();
}