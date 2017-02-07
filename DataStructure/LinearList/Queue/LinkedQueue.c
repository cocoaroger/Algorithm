/**
 * 队列的链式存储
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../../../Common/Memory.c"

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
	assert(queue != NULL);

	// 指针变量没有被初始化。任何指针变量刚被创建时不会自动成为NULL指针，
	// 它的缺省值是随机的，它会乱指一气。
	// 所以，指针变量在创建的同时应当被初始化，要么将指针设置为NULL，
	// 要么让它指向合法的内存。
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

	Node *oldHead = queue->head;
	ElementType outData = oldHead->data;
	queue->head = oldHead->next;
	free(oldHead);

	queue->size -= 1;
	if (queue->size == 0)
	{
		queue->tail = NULL;
	}
	return outData;
}

int main(int argc, char const *argv[])
{
	LinkedQueue *queue = NULL;
	queue = init();
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

	free(queue);
	queue = NULL;

	return 0;
}