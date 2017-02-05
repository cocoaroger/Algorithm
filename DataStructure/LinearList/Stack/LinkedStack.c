#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct _Node Node;
typedef struct _Stack Stack;

struct _Node
{
	ElementType data;
	struct _Node *next;
};

struct _Stack
{
	Node *head;
	int size;	
};

/**
 * 链式栈
 */

Stack* init()
{
	Stack *stack = (Stack*)malloc(sizeof(Stack*));
	stack->head = (Node*)malloc(sizeof(Node*));
	stack->size = 0;
	return stack;
}

/**
 * 入栈
 * @param stack [description]
 * @param data  [description]
 */
void push(Stack *stack, ElementType data) 
{
	Node *newNode = (Node*)malloc(sizeof(Node*));
	newNode->data = data;

	newNode->next = stack->head->next;
	stack->head->next = newNode;

	stack->size += 1;
}

/**
 * 出栈
 * @param  stack [description]
 * @return       [description]
 */
ElementType pop(Stack *stack)
{
	if (stack->size == 0)
	{
		printf("栈为空，无法删除\n");
		return 0;
	}
	Node *temp = stack->head->next;

	ElementType popData = temp->data;
	stack->head->next = temp->next;
	stack->size -= 1;

	free(temp);
	return popData;
}

int main(int argc, char const *argv[])
{
	Stack *stack = init();

	printf("入栈顺序：\n");
	for (int i = 0; i < 10; ++i)
	{
		ElementType data = i+100;
		push(stack, data);
		printf("%d \t", data);
	}
	printf("\n");

	printf("出栈顺序：\n");
	for (int i = 0; i < 11; ++i)
	{
		ElementType data = pop(stack);
		printf("%d \t", data);
	}
	printf("\n");	
	return 0;
}