#include "SequenceList.h"
#include <ctype.h>
#include <float.h>
#include <limits.h>

// 测试引用单链表头文件
void testSequnceList() {
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
}

int main(int argc, char const *argv[])
{
	testSequnceList();
	printf("%.10e\n", FLT_MAX);
	return 0;
}