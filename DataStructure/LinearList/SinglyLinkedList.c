
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

// 以O(1)时间复杂度删除节点
void deleteO1At(SinglyLinkedList list, Node *deletedNode)
{
	if (list == NULL || deletedNode == NULL)
	{
		return;
	}

	if (deletedNode->next != NULL) // 不是尾节点
	{
		deletedNode->data = deletedNode->next->data;
		deletedNode->next = deletedNode->next->next;
		free(deletedNode);	
	} else if (list == deletedNode) { // 只有一个节点
		free(list);
		free(deletedNode);
	} else { // 是尾节点
		Node *node = list;
		while (node->next != deletedNode) {
			node = node->next;
		}
		node->next = NULL;
	}
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
	insert(list, 2, 1000);
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