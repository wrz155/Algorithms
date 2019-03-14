#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include "linkqueue.h"

void main(void)
{
	int i, a[10];
	LinkQueue* queue = NULL;

	queue = LinkQueue_Create();

	//向队列中添加元素
	for (i = 0; i<10; i++)
	{
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}

	//
	printf("the length of queue: %d \n", LinkQueue_Length(queue));
	printf("the header of queue: %d \n", *((int *)LinkQueue_Header(queue)));

	while (LinkQueue_Length(queue) > 0)
	{
		printf("%d \n", *((int *)LinkQueue_Retrieve(queue)));
	}

	LinkQueue_Destroy(queue);

	system("pause");
}