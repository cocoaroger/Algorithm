#include "SequenceList.h"

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
	return 0;
}