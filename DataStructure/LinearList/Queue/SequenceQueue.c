/**
 * 
 * 队列是只允许在一端进行插入操作，在另一端进行删除操作的线性表。
 * 它是一种基于先进先出（First In First Out，简称FIFO）策略的集合类型。
 * 允许插入的一端称为队尾，允许删除的一端称为队头。
 * 这种方法还没有调试通过，原因可能是如队列时last设置有问题
 * 
 */

/**
 * 本处采用循环队列，可以让基本操作的时间复杂度为O(1)
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 获取数组长度
 * @param  array  数组
 * @param  length 得到的长度
 */
#define GET_ARRAY_LENGTH(array) { length = (sizeof(array) / sizeof(array[0]));}

typedef void* ElementType; // 换成int类型会数据错误，用void*是正确的，目前还没理解到为什么
typedef struct _SequenceQueue SequenceQueue;

/**
 * 初始容量
 */
#define QUEUE_INIT_CAPACITY 10

struct _SequenceQueue
{
	ElementType *data;
	int size;
	int capacity;
	int first; // 头元素的索引
	int last; // 为元素后一个的索引
};

void printQueue(SequenceQueue *queue)
{
	printf("-----开始打印-----\n");
	for (int i = 0; i < queue->size; i++)
	{
		printf("%d\t", queue->data[(queue->first+i) % queue->capacity]);
	}
	printf("\n-----结束打印-----\n");
}

void printQueueInfo(SequenceQueue *queue)
{
	printf("\nsize: %d, capacity: %d, first: %d, last: %d\n", queue->size, queue->capacity, queue->first, queue->last);
}

SequenceQueue* init()
{
	SequenceQueue *queue = (SequenceQueue*)malloc(sizeof(SequenceQueue*));
	queue->data = (ElementType*)malloc(QUEUE_INIT_CAPACITY * sizeof(ElementType*));
	queue->size = 0;
	queue->capacity = QUEUE_INIT_CAPACITY;
	queue->first = 0;
	queue->last = 0;
	return queue;
}

/**
 * 改变队列的容量大小
 * @param queue    队列对象
 * @param capacity 新的容量大小
 */
void resize(SequenceQueue *queue, int capacity)
{
	ElementType *newData = (ElementType*)malloc(capacity * sizeof(ElementType*));
	for (int i = 0; i < queue->size; i++)
	{
		newData[i] = queue->data[(queue->first+i) % queue->capacity];
	}
	
	queue->data = newData;
	queue->first = 0; // 数组调整后first，last位置
	queue->last = queue->size;
	queue->capacity = capacity;
}

/**
 * 入队列
 * @param queu [description]
 * @param data  数据
 */
void inQueue(SequenceQueue *queue, ElementType data)
{
	if (queue->size == queue->capacity)
	{
		resize(queue, 2 * queue->size); // 若数组已满将长度加倍
	}
	
	queue->data[queue->last] = data;	
	queue->last = (queue->last + 1) % queue->capacity;
	queue->size += 1;
}

/**
 * 出队列
 * @param  queue [description]
 * @return       出队列的数据
 */
ElementType outQueue(SequenceQueue *queue)
{	
	if (queue->size == 0)
	{
		return 0;
	}

	ElementType outData = queue->data[queue->first];
	queue->first = (queue->first + 1) % queue->capacity;
	queue->size -= 1;
	
	// 小于数组1/4,将数组减半
	if (queue->size > 0 && queue->size == queue->capacity/4 && queue->capacity > QUEUE_INIT_CAPACITY)
	{
		resize(queue, 2 * queue->size);
	}

	return outData;
}

int main(int argc, char const *argv[])
{
	SequenceQueue *queue = init();
	
	int count = 30;
	printf("入队列的数据：\n");
	for (int i = 0; i < count; i++)
	{
		int inData = i;
		if (i == 1)
		{
			inData = 55;
		}
		inQueue(queue, (ElementType)inData);	
		printf("%d\t", inData);
	}
	printf("\n");
	printf("---------入队列结束----------\n");
	printQueue(queue);

	printf("出队列的数据：\n");
	for (int i = 0; i < count; i++)
	{
		ElementType outData = outQueue(queue);
		printf("%d\t", outData);
	}
	printf("\n---------出队列结束----------\n");
	printQueueInfo(queue);

	return 0;
}
