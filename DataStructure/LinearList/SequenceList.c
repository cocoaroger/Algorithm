#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 2

typedef int ElementType;

// 顺序表
typedef struct SequenceList
{
	ElementType *data; // 指示动态分配数组的指针
	int size; // 当前元素个数
	int capacity; // 动态增长的表长
} SequenceList;

// 打印顺序链表
void printList(SequenceList *list)
{
	if (list->size == 0)
	{
		printf("%s\n", "当前顺序表为空!");
		return;
	}
	printf("%s\n", "遍历顺序表：");
	printf("顺序表 size:%d, capacity:%d \n", list->size, list->capacity);

	for (int i = 0; i < list->size; ++i)
	{
		printf("%d \t", list->data[i]);
	}
	printf("\n");
}

// 初始化
SequenceList * init() 
{
	SequenceList *list = (SequenceList *)malloc(sizeof(SequenceList));

	list->data = (ElementType *)malloc(LIST_INIT_SIZE * sizeof(ElementType));
	list->capacity = LIST_INIT_SIZE;
	list->size = 0;
	return list;
}

/*
	插入
	- index 插入的位置
	- element 插入的元素
*/
void insert(SequenceList *list, int index, ElementType element)
{
	ElementType *newData;
	if (list->capacity == list->size) // 扩容
	{
		newData = (ElementType *)realloc(list->data, (list->size + LIST_INCREMENT) * sizeof(ElementType));
		list->data = newData;
		list->capacity += LIST_INCREMENT;
	}

	int i = list->capacity;
	while ( i > index)
	{
		list->data[i] = list->data[i-1];
		i -= 1;
	}
	list->data[index] = element;
	list->size += 1;
}

/*
	删除元素
	- index 删除的位置
	- element 返回删除的元素
*/
void deleteElement(SequenceList *list, int index, ElementType *deletedElement)
{
	*deletedElement = list->data[index];

	for (int i = index; i < list->capacity-1; ++i)
	{
		list->data[i] = list->data[i+1];
	}
	list->capacity -= 1;
	list->size -= 1;
}

int main(int argc, char const *argv[])
{
	SequenceList *list = init();
	// 初始化
	printList(list);

	// 插入
	for (int i = 0; i < 11; ++i)
	{
		insert(list, i, i);
	}
	printf("插入后顺序表\n");
	printList(list);
	

	ElementType deletedElement;
	deleteElement(list, 8, &deletedElement);
	printf("删除的元素：%d\n", deletedElement);	
	printf("删除后顺序表\n");
	printList(list);

	return 0;
}

