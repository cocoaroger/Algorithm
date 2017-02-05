/**
 * 
 * 队列是只允许在一端进行插入操作，在另一端进行删除操作的线性表。
 * 它是一种基于先进先出（First In First Out，简称FIFO）策略的集合类型。
 * 允许插入的一端称为队尾，允许删除的一端称为队头。
 * 这种方法还没有调试通过，原因可能是如队列时last设置有问题
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
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

SequenceQueue* init()
{
	SequenceQueue *queue = (SequenceQueue*)malloc(sizeof(SequenceQueue*));

	queue->data = (ElementType*)malloc(QUEUE_INIT_CAPACITY * sizeof(ElementType*));
	queue->size = 0;
	queue->capacity = QUEUE_INIT_CAPACITY;

	return queue;
}

/**
 * 改变队列的容量大小
 * @param queue    队列对象
 * @param capacity 新的容量大小
 */
void resize(SequenceQueue *queue, int capacity)
{
	ElementType *newData = (ElementType *)realloc(queue->data, capacity * sizeof(ElementType*));
	queue->data = newData;
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
	
	if (queue->size > 0 && queue->size == queue->capacity/4) // 小于数组1/4,将数组减半
	{
		resize(queue, queue->capacity/2);
	}

	return outData;
}

int main(int argc, char const *argv[])
{
	SequenceQueue *queue = init();
	
	for (int i = 0; i < 11; ++i)
	{
		inQueue(queue, i + 100);	
	}
	
	// for (int i = 0; i < 9; ++i)
	// {
	// 	ElementType outData = outQueue(queue);
	// 	printf("出队列的数据：%d\n", outData);
	// }
	return 0;
}
