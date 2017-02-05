#include <stdio.h>
#include <stdlib.h>
/**
 * 顺序存储结构栈
 */

/**
 * 初始容量
 */
#define STACK_INIT_CAPACITY 10

typedef int ElementType;

/**
 * 栈的顺序存储结构
 */
typedef struct _Stack
{
	ElementType *data;
	int size;
	int capacity;
} Stack;

void printStack(Stack *stack)
{
	printf("遍历栈对象：\n");
	printf("大小：%d \t 容量：%d \n", stack->size, stack->capacity);
	for (int i = 0; i < stack->size; ++i)
	{
		printf("%d \t", stack->data[i]);
	}
	printf("\n");
}

/**
 * 初始化
 * @return 栈对象
 */
Stack* init()
{
	Stack *stack = (Stack*)malloc(sizeof(Stack*));

	stack->data = (ElementType*)malloc(STACK_INIT_CAPACITY * sizeof(ElementType*));
	stack->capacity = STACK_INIT_CAPACITY;
	stack->size = 0;
	return stack;
}

/**
 * 改变栈的容量大小
 * @param stack    栈对象
 * @param capacity 新的容量大小
 */
void resizeStack(Stack *stack, int capacity)
{
	ElementType *newData = (ElementType *)realloc(stack->data, capacity * sizeof(ElementType*));
	stack->data = newData;
	stack->capacity = capacity;
}

/**
 * 入栈
 * @param stack [description]
 * @param data  数据
 */
void push(Stack *stack, ElementType data)
{
	if (stack->size == stack->capacity)
	{
		resizeStack(stack, 2 * stack->size); // 若数组已满将长度加倍
	}
	stack->data[stack->size] = data;
	stack->size += 1;
}

/**
 * 出栈
 * @param  stack [description]
 * @return       出栈的数据
 */
ElementType pop(Stack *stack)
{
	if (stack->size == 0)
	{
		return 0;
	}

	ElementType popData = stack->data[stack->size-1];
	stack->data[stack->size-1] = 0;
	stack->size -= 1;
	
	if (stack->size > 0 && stack->size == stack->capacity/4) // 小于数组1/4,将数组减半
	{
		resizeStack(stack, stack->capacity/2);
	}

	return popData;
}

int main(int argc, char const *argv[])
{
	Stack *stack = init();
	
	for (int i = 0; i < 11; ++i)
	{
		push(stack, i + 100);	
	}
	printStack(stack);

	ElementType popData = pop(stack);
	printf("弹出的数据：%d\n", popData);

	for (int i = 0; i < 9; ++i)
	{
		pop(stack);
	}
	printStack(stack);
	return 0;
}