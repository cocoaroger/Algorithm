#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 2
#define SUCCESS 1
#define ERROR 0

typedef int ElementType;
typedef int Status;

// 根据状态打印文字
void print(Status status, char message[])
{
	if (status == SUCCESS)
	{
		printf("%s成功\n", message);
	} else {
		printf("%s失败\n", message);
	}
}

// 顺序表
typedef struct SequenceList
{
	ElementType *element; // 数据元素基址
	int size; // 元素个数
	int length; // 表长
} SequenceList, *SequenceListPt;

Status init(SequenceListPt list) 
{
	list->element = (ElementType *)malloc(LIST_INIT_SIZE*sizeof(ElementType));
	if (!list->element)
	{
		return ERROR;
	}
	list->length = LIST_INIT_SIZE;
	list->size = 0;
	return SUCCESS;
}

Status clear(SequenceListPt list) 
{
	if (!list->element)
	{
		return ERROR;
	}
	list->length = 0;
	return SUCCESS;
}

Status destory(SequenceListPt list)
{
	if (list->element)
	{
		free(list->element);
		list = NULL;
		return SUCCESS;
	}
	return ERROR;
}

Status checkIndex(SequenceListPt list, int index) 
{
	if (index >= 0 && index <= list->length)
	{
		return SUCCESS;
	} else {
		printf("%s\n", "下标不合法，插入失败");
		return ERROR;
	}
}

/*
	插入
	- index 插入的位置
	- element 插入的元素
*/
Status insert(SequenceListPt list, int index, ElementType element)
{
	if (checkIndex(list, index) == ERROR)
	{
		return ERROR;
	}
	ElementType *base;
	if (list->length == list->size) // 扩容
	{
		base = (ElementType *)realloc(list->element, (list->size + LIST_INCREMENT)*sizeof(ElementType));
		list->element = base;
		list->length += LIST_INCREMENT;
	}

	int i = list->length;
	while ( i > index)
	{
		list->element[i] = list->element[i-1];
		i -= 1;
	}
	list->element[index] = element;
	list->size += 1;
	return SUCCESS;
}

/*
	删除元素
	- index 删除的位置
	- element 返回删除的元素
*/
Status delete(SequenceListPt list, int index, ElementType *element)
{
	if (checkIndex(list, index) == ERROR)
	{
		return ERROR;
	}
	*element = list->element[index];
	for (int i = index; i < list->length-1; ++i)
	{
		list->element[i] = list->element[i+1];
	}
	list->length -= 1;
	list->size -= 1;
	return SUCCESS;
}


int main(int argc, char const *argv[])
{
	SequenceList list;
	// 初始化
	print(init(&list), "初始化");
	
	// 插入
	printf("初始化顺序表 size:%d, length:%d\n", list.size, list.length);
	for (int i = 0; i < 11; ++i)
	{
		print(insert(&list, i, i), "插入");	
	}
	printf("插入后顺序表 size:%d, length:%d\n", list.size, list.length);

	ElementType deletedElement;
	print(delete(&list, 8, &deletedElement), "删除");
	printf("删除的元素：%d\n", deletedElement);	
	printf("删除后顺序表 size:%d, length:%d\n", list.size, list.length);

	return 0;
}

