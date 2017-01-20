
#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE sizeof(struct Node)

typedef int ElementType;

// 链表节点
typedef struct Node
{
	ElementType data;
	struct Node *next;
} Node, *SinglyLinkedList;



// 初始化
SinglyLinkedList init(ElementType data)
{
	Node *head;
	head = (Node *)malloc(LIST_INIT_SIZE);
	head->data = data;
	head->next = NULL;
	return head;
}

// 查询
Node* getElement(SinglyLinkedList list, int index)
{
	Node *searchResult = list->next;

	if (index == 0)
	{
		return list;
	}
	if (index < 1)
	{
		return NULL;
	}

	int j = 1; // 顺序遍历
	while (searchResult && j < index)
	{
		searchResult = searchResult->next;
		j++;
	}
	return searchResult;
}

// 插入
void insert(SinglyLinkedList list, int index, ElementType element) 
{
	Node *preNode = getElement(list, index-1);

	Node *newNode;
	newNode = (Node *)malloc(LIST_INIT_SIZE);
	newNode->data = element;

	newNode->next = preNode->next;
	preNode->next = newNode;
}

// 删除
void deleteAt(SinglyLinkedList list, int index, ElementType *deletedElement)
{
	Node *deletedNode = getElement(list, index);

	Node *preNode = getElement(list, index-1);

	preNode->next = deletedNode->next;
	*deletedElement = deletedNode->data;
	free(deletedNode);
}

void printList(SinglyLinkedList list) 
{
	Node *next = list;

	do
	{
		printf("%d\n", next->data);
		next = next->next;
	} while (next != NULL);
}

SinglyLinkedList reverseList(SinglyLinkedList list)
{
	SinglyLinkedList prev = NULL;
	while (list->next)
	{
		Node *temp = list->next;
		list->next = prev;
		prev = list;
		list = temp;
	}
	return list;
}

int main(int argc, char const *argv[])
{
	SinglyLinkedList list = init(100);
	insert(list, 1, 20);
	insert(list, 2, 30);
	insert(list, 2, 1000);
	printList(list);

	ElementType deletedElement;
	deleteAt(list, 1, &deletedElement);
	printList(list);
	printf("删除的元素：%d\n", deletedElement);

	return 0;
}