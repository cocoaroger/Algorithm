#include <stdio.h>
#include <stdlib.h>

/**
 * 初始化节点的内存大小
 */
#define LIST_INIT_SIZE sizeof(struct Node)

/**
 * 节点的数据类型
 */
typedef int ElementType;

/**
 * 双向链表定义
 */
typedef struct Node* DoubleLinkedList;

/**
 * 节点结构体
 */
typedef struct Node
{
	ElementType data;
	struct Node *prior, *next;
} Node;

/**
 * 顺序打印链表
 * @param list 需要打印的链表
 */
void printList(DoubleLinkedList list)
{
	printf("打印双向链表：\n");
	printf("%d\t", list->data);

	Node *node = list->next;
	while (node != list)
	{
		printf("%d\t", node->data);
		node = node->next;
	};
	printf("\n");
}

/**
 * 初始化，双链表可以很方便地找到其前驱结点，因此，插入、删除结点算法的时间复杂度仅为O(1)。
 * @return 双向链表实例对象
 */
DoubleLinkedList init()
{
	DoubleLinkedList list = (DoubleLinkedList)malloc(LIST_INIT_SIZE);
	list->next = list;
	list->prior = list;
	return list;
}

/**
 * 获取节点
 * @param list 从该list获取
 * @param index 需要获取的节点索引
 * @return 节点指针
 */
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

/**
 * 插入节点
 * @param list 插入到的链表
 * @param index 插入到的索引地址
 * @param data 插入的内容
 */
void insert(DoubleLinkedList list, int index, ElementType data) 
{
	if (index == 0)
	{
		list->data = data;
		return;
	}
	Node *preNode = getNode(list, index-1);
	if (preNode == NULL)
	{
		return;
	}

	Node *newNode = (Node*)malloc(LIST_INIT_SIZE); // 新节点
	newNode->data = data;

	newNode->prior = preNode;
	newNode->next = preNode->next;

	preNode->next->prior = newNode;
	preNode->next = newNode;
}

/**
 * 删除节点
 * @param list 从该链表删除
 * @param index 删除的索引
 * @param deletedElement 返回 删除的节点数据
 */
void deleteAt(DoubleLinkedList list, int index, ElementType *deletedElement)
{
	DoubleLinkedList deletedNode = getNode(list, index);
	*deletedElement = deletedNode->data;

	deletedNode->prior->next = deletedNode->next;
	deletedNode->next->prior = deletedNode->prior;

	free(deletedNode);
}

/**
 * 获取链表环的相遇节点
 */
Node* getMeetNode(DoubleLinkedList list) 
{
	Node *first = list;
	Node *second = list;
	while(second != NULL && second->next != NULL) 
	{
		first = first->next;
		second = second->next->next;
		if (first == second) 
		{
			return first;
		}
	}
	return NULL;
}

/**
 * 获取环长度
 */
int getLoopLength(DoubleLinkedList list)
{
	Node *meetNode = getMeetNode(list);
	if (meetNode == NULL) // 没有环
	{
		return 0;
	}

	Node *first = meetNode->next;
	int result = 1;
	while(first != meetNode) {
		result += 1;
		first = first->next;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	DoubleLinkedList list = init();
	for (int i = 0; i <= 5; i++)
	{
		insert(list, i, i+100);
	}
	printList(list);

	ElementType deletedElement;
	deleteAt(list, 3, &deletedElement);
	printf("删除的元素：%d\n", deletedElement);
	printList(list);

	Node *meetNode = getMeetNode(list);
	printf("链表相遇的节点 : %d\n", meetNode->data);
	printf("环的长度： %d\n", getLoopLength(list));

	return 0;
}