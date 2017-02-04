
#include <stdio.h>
#include <stdlib.h>

/**
 * 初始化单向链表的内存大小
 */
#define LIST_INIT_SIZE sizeof(struct Node)
/**
 * 数据类型
 */
typedef int ElementType;
/**
 * 单向链表定义
 */
typedef struct Node* SinglyLinkedList;

/**
 * 链表节点结构体
 */
typedef struct Node
{
	ElementType data;
	struct Node *next;
} Node;

/**
 * 打印链表
 * @param list 需要打印的链表
 */
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

/**
 * 初始化链表
 * @param data 初始化传入的数据
 * @return 单项链表对象
 */
SinglyLinkedList init(ElementType data)
{
	SinglyLinkedList list;
	list = (SinglyLinkedList)malloc(LIST_INIT_SIZE);
	list->data = data;
	list->next = NULL;
	return list;
}

/**
 * 查询节点
 * @param list 查询的链表
 * @param index 查询索引
 * @return 查到的节点
 */
Node* getElement(SinglyLinkedList list, int index)
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

/**
 * 插入链表
 * @param list 需要插入的链表
 * @param index 插入的位置
 * @param element 插入的数据
 */
void insert(SinglyLinkedList list, int index, ElementType element) 
{
	Node *preNode = getElement(list, index-1);

	Node *newNode;
	newNode = (Node *)malloc(LIST_INIT_SIZE);
	newNode->data = element;

	newNode->next = preNode->next;
	preNode->next = newNode;
}

/**
 * 一般的删除
 * @param list 需要插入的链表
 * @param index 删除的位置
 * @param deletedElement 删除的数据
 */
void deleteAt(SinglyLinkedList list, int index, ElementType *deletedElement)
{
	Node *deletedNode = getElement(list, index);

	Node *preNode = getElement(list, index-1);

	preNode->next = deletedNode->next;
	*deletedElement = deletedNode->data;
	free(deletedNode);
}

/**
 * 以O(1)时间复杂度删除节点
 * @param list 需要删除节点的链表
 * @param deletedNode 需要删除的节点
 */
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

/**
 * 反转链表
 * @param list 需要反转的链表
 * @return 翻转后的链表
 */
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


/**
 * 两个指针p1、p2每次走一步，若两链表长度相同，

若有公共结点，遍历到公共结点时p1 = p2返回；
若无公共结点，遍历到尾部NULL时p1 = p2，返回NULL
若两链表长度不同，指向短链表指针先走完，然后指向长链表，指向长链表指针后走完，然后指向短链表。此时等效为长度相同，如下图

过程同上面「两链表长度相同时」
此算法的时间复杂度同样为 O(m + n)
 */
/**
 * 查询两个链表的第一个公共节点
 * @param firstList 第一个链表
 * @param secondList 第二个链表
 * @return 公共节点
 */
Node* findCommonNode(SinglyLinkedList head1, SinglyLinkedList head2)
{
	Node* p1 = head1;
	Node* p2 = head2;

	while(p1 != p2) {
		p1 = (p1 == NULL ? head1 : p1->next);
		p2 = (p2 == NULL ? head2 : p2->next);
	}
	return p1;
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