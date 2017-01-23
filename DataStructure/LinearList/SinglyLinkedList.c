
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

// 打印链表
void printList(SinglyLinkedList list) 
{
	Node *node = list;
	printf("%s\n", "打印单链表：");
	while (node != NULL) {
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("\n");
}

// 初始化
SinglyLinkedList init(ElementType data)
{
	SinglyLinkedList list;
	list = (SinglyLinkedList)malloc(LIST_INIT_SIZE);
	list->data = data;
	list->next = NULL;
	return list;
}

// 查询
Node * getElement(SinglyLinkedList list, int index)
{
	if (index < 0)
	{
		return NULL;
	}
	if (index == 0)
	{
		return list;
	}

	Node *searchResult = list->next;
	int j = 1; // 顺序遍历
	while (searchResult != NULL && j < index)
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

// 一般的删除
void deleteAt(SinglyLinkedList list, int index, ElementType *deletedElement)
{
	Node *deletedNode = getElement(list, index);

	Node *preNode = getElement(list, index-1);

	preNode->next = deletedNode->next;
	*deletedElement = deletedNode->data;
	free(deletedNode);
}

// 以O(1)时间复杂度删除节点
void deleteO1At(SinglyLinkedList list, Node *deletedNode)
{
	if (list == NULL || deletedNode == NULL)
	{
		return;
	}

	if (deletedNode->next != NULL) // 不是尾节点
	{
		Node *temp = deletedNode->next; // 缓存，最后删除

		deletedNode->data = deletedNode->next->data;
		deletedNode->next = deletedNode->next->next;
		free(temp);
	} else if (list == deletedNode) { // 只有一个节点
		free(list);
		free(deletedNode);
	} else { // 是尾节点
		Node *preNode = list;
		while (preNode->next != deletedNode) {
			preNode = preNode->next;
		}
		preNode->next = NULL;
		free(deletedNode);
	}
}

// 翻转链表
SinglyLinkedList reverseList(SinglyLinkedList list)
{
	SinglyLinkedList prev = NULL;
	while (list != NULL)
	{
		Node *temp = list->next;
		list->next = prev;
		prev = list;
		list = temp;
	}
	return prev;
}





int main(int argc, char const *argv[])
{
	SinglyLinkedList list = init(100);
	insert(list, 1, 20);
	insert(list, 2, 30);
	insert(list, 3, 1000);
	printList(list);

	ElementType deletedElement;
	deleteAt(list, 1, &deletedElement);
	printList(list);
	printf("删除的元素：%d\n", deletedElement);

	printf("%s\n", "反序前链表：");
	printList(list);

	SinglyLinkedList reversedList = reverseList(list);
	printf("%s\n", "反序后链表：");
	printList(reversedList);
	
	Node *willDeleteNode = getElement(reversedList, 1);
	printf("要删除的元素：%d\n", willDeleteNode->data);

	deleteO1At(reversedList, willDeleteNode);
	printf("删除后列表\n");
	printList(reversedList);

	return 0;
}