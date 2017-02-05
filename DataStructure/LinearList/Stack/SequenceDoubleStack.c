/**
 * 两栈共享空间
 */

#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

typedef struct _Stack
{
	ElementType *data;
	int maxSize;
	int leftSize;
	int rightSize;
} Stack;

/**
 * 标记是哪个栈
 */
typedef enum _StackDirection
{
	StackDirection_Left = 0,
	StackDirection_Right = 1
} StackDirection;

/**
 * 初始化栈
 * @param  maxSize 最大容量
 * @return         栈对象
 */
Stack* init(int maxSize)
{
	Stack *stack = (Stack*)malloc(sizeof(Stack*));
	
	stack->data = (ElementType*)malloc(maxSize * sizeof(ElementType*));
	stack->leftSize = 0;
	stack->rightSize = maxSize - 1;
	stack->maxSize = maxSize;

	return stack;
}

/**
 * 入栈
 * @param stack     [description]
 * @param direction 入栈方向
 * @param data      数据
 */
void push(Stack *stack, StackDirection direction, ElementType data)
{
	if (stack->leftSize-1 == stack->rightSize)
	{
		printf("栈已满\n");
		return;
	}

	if (direction == StackDirection_Left)
	{
		stack->data[stack->leftSize] = data;
		stack->leftSize += 1;
	} else {
		stack->data[stack->rightSize] = data;
		stack->rightSize -= 1;
	}
}

ElementType pop(Stack *stack, StackDirection direction)
{
	if (direction == StackDirection_Left) {
		if (stack->leftSize <= 0) {
			printf("栈为空,无法删除\n");
			return 0;
		}

		ElementType data = stack->data[stack->leftSize-1];
		stack->data[stack->leftSize-1] = 0;
		stack->leftSize -= 1;
		return data;
	} else {
		if (stack->rightSize >= stack->maxSize-1)
		{
			printf("栈为空，无法删除\n");
			return 0;
		}

		ElementType data = stack->data[stack->rightSize+1];
		stack->data[stack->rightSize+1] = 0;
		stack->rightSize += 1;
		return data;
	}
}

int main(int argc, char const *argv[])
{
	Stack *stack = init(100);

	printf("右入栈顺序\n");
	for (int i = 0; i < 10; ++i)
	{
		int data = i+100;
		printf("%d \t", data);
		push(stack, StackDirection_Right, data);
	}
	printf("\n");
	printf("右出栈顺序\n");
	for (int i = 0; i < 10; ++i)
	{
		int data = pop(stack, StackDirection_Right);
		printf("%d \t", data);
	}
	printf("\n");


	printf("左入栈顺序\n");
	for (int i = 0; i < 10; ++i)
	{
		int data = i+100;
		printf("%d \t", data);
		push(stack, StackDirection_Left, data);
	}
	printf("\n");
	printf("左出栈顺序\n");
	for (int i = 0; i < 10; ++i)
	{
		int data = pop(stack, StackDirection_Left);
		printf("%d \t", data);
	}
	
	return 0;
}

