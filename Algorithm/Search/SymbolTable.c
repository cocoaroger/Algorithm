/**
 * 简单实现符号表
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char KeyType;
typedef char ValueType;

typedef struct _SymbolTable
{
	struct _Node *head;
} SymbolTable;

typedef struct _Node
{
	KeyType *key;
	ValueType *value;
	struct _Node *next;
} Node;

SymbolTable* init() {
	SymbolTable *st = (SymbolTable *)malloc(sizeof(SymbolTable));
	st->head = NULL;
	return st;
}

Node* sequentialSearch(SymbolTable *st, KeyType *key) {
	Node *cur = st->head;
	while (cur != NULL) {
		if (key == cur->key)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void put(SymbolTable *st, KeyType *key, ValueType *value) {
	Node *temp = sequentialSearch(st, key);
	if (temp != NULL)
	{
		temp->value = value;
	} else {
		Node *newHead = (Node *)malloc(sizeof(Node));
		newHead->key = key;
		newHead->value = value;
		newHead->next = st->head;

		st->head = newHead;
	}
}

ValueType* get(SymbolTable *st, KeyType *key) {
	Node *temp = sequentialSearch(st, key);
	if (temp != NULL)
	{
		return temp->value;
	} else {
		return NULL;
	}
}

int main(int argc, char const *argv[])
{
	SymbolTable *st = init();
	KeyType key[] = "name";
	ValueType value[] = "roger";
	put(st, key, value);

	printf("%s\n", get(st, key));

	return 0;
}









