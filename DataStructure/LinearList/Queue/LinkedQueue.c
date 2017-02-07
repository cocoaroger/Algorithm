/**
 * 队列的链式存储
 */

#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;
typedef struct _Node Node;
typedef struct _LinkedQueue LinkedQueue;
#define NODE_SIZE sizeof(struct _Node)

struct _Node
{
	ElementType data;
	struct _Node *next;
};

struct _LinkedQueue
{
	Node *head; // 头节点
	Node *tail; // 尾节点
	int size; // 数量
};

void printQueue(LinkedQueue *queue)
{
	Node *temp = queue->head;
	printf("\n----开始打印----\n");
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n----结束打印----\n");
}

LinkedQueue* init()
{
	LinkedQueue *queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	
	// head,tail必须初始化为NULL，否则会出问题,可能是嘢指针导致
	queue->head = NULL;
	queue->tail = NULL;
	
	queue->size = 0;
	return queue;
}

void inQueue(LinkedQueue *queue, ElementType data)
{
	Node *newNode = (Node*)malloc(NODE_SIZE);
	newNode->data = data;
	newNode->next = NULL;
	
	// 在尾节点处加一个
	Node *oldTail = queue->tail;

	queue->tail = newNode;
	if (queue->size == 0) {
		queue->head = newNode;
	} else {
		oldTail->next = newNode;
	}

	queue->size += 1;
}

ElementType outQueue(LinkedQueue *queue)
{
	if (queue->size == 0)
	{
		return 0;
	}

	ElementType outData = queue->head->data;
	queue->head = queue->head->next;

	queue->size -= 1;
	if (queue->size == 0)
	{
		queue->tail = NULL;
	}
	return outData;
}

int main(int argc, char const *argv[])
{
	LinkedQueue *queue = init();
	int count = 10;
	printf("入队列的数据：\n");
	for (int i = 0; i < count; i++)
	{
		ElementType inData = (i+100);
		inQueue(queue, inData);
		printf("%d\t", inData);
	}
	printf("\n-----入队列结束-----\n");
	printQueue(queue);

	for (int i = 0; i < count; i++)
	{
		ElementType outData = outQueue(queue);
		printf("%d\t", outData);
	}
	printf("\n-----出队列结束-----\n");
	return 0;
}