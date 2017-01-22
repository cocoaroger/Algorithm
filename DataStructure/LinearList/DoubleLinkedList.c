#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE sizeof(struct Node)

typedef int ElementType;

typedef struct Node
{
	ElementType data;
	struct Node *prior, *next;
} Node, *DoubleLinkedList;

// 顺序打印链表
void printList(DoubleLinkedList list)
{
	Node *node = list->next;
	printf("%s\n", "打印双向链表：");
	while (node != list)
	{
		printf("%d\t", node->data);
		node = node->next;
	};
	printf("\n");
}

// 初始化，双链表可以很方便地找到其前驱结点，因此，插入、删除结点算法的时间复杂度仅为O(1)。
DoubleLinkedList init()
{
	DoubleLinkedList list = (DoubleLinkedList)malloc(LIST_INIT_SIZE);
	list->next = list->prior = list;
	return list;
}

// 获取节点
Node* getNode(DoubleLinkedList list, int index)
{
	if (index == 0)
	{
		return list;
	}
	if (index < 1)
	{
		return NULL;
	}

	// 顺序遍历
 	DoubleLinkedList searchResult = list;
	for (int i = 1; i <= index; i++)
	{
		searchResult = searchResult->next;
	}
	return searchResult;
}

// 插入节点
void insert(DoubleLinkedList list, int index, ElementType data) 
{
	DoubleLinkedList preNode = getNode(list, index-1);

	DoubleLinkedList newNode = (DoubleLinkedList)malloc(LIST_INIT_SIZE); // 新节点
	newNode->data = data;

	newNode->prior = preNode;
	newNode->next = preNode->next;
	preNode->next->prior = newNode;
	preNode->next = newNode;
}

// 删除节点
void deleteAt(DoubleLinkedList list, int index, ElementType *deletedElement)
{
	DoubleLinkedList deletedNode = getNode(list, index);
	*deletedElement = deletedNode->data;

	deletedNode->prior->next = deletedNode->next;
	deletedNode->next->prior = deletedNode->prior;

	free(deletedNode);
}

int main(int argc, char const *argv[])
{
	DoubleLinkedList list = init();
	for (int i = 1; i <= 5; i++)
	{
		insert(list, i, i);
	}
	printList(list);

	ElementType deletedElement;
	deleteAt(list, 3, &deletedElement);
	printf("删除的元素：%d\n", deletedElement);
	printList(list);

	return 0;
}