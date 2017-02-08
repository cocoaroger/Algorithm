#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/**
 * 顺序存储二叉树的实现
 *
 * 结点的存储位置反映了它们之间的逻辑关系：位置k的结点的双亲结点的位置为「k/2」，
 * 它的两个孩子结点的位置分别为2k和2k+1。
 */

typedef int ElementType;
#define DEFAULT_DEPTH 5

typedef struct _BinaryTree
{
	ElementType *datas;
	int size;
} BinaryTree;

BinaryTree* init()
{
	BinaryTree *binaryTree = (BinaryTree*)malloc(sizeof(BinaryTree));
	assert(binaryTree != NULL);

	int size = pow(2, DEFAULT_DEPTH) * sizeof(ElementType);
	binaryTree->datas = NULL;
	binaryTree->datas = (ElementType*)malloc(size);
	assert(binaryTree->datas != NULL);

	binaryTree->size = 0;

	return binaryTree;
}

ElementType getRoot(BinaryTree *binaryTree)
{
	return binaryTree->datas[1];
}

ElementType getParent(int index, BinaryTree *binaryTree)
{
	return binaryTree->datas[index/2];
}

ElementType getLeft(int index, BinaryTree *binaryTree)
{
	return binaryTree->datas[index*2];
}

ElementType getRight(int index, BinaryTree *binaryTree)
{
	return binaryTree->datas[index*2+1];
}

void add(ElementType data, BinaryTree *binaryTree)
{
	binaryTree->datas[binaryTree->size+1] = data;
	binaryTree->size += 1;
}

/**
 * 前序遍历：先访问根结点，然后遍历左子树，最后遍历右子树。
 * @param binaryTree [description]
 * @param index      遍历的位置
 */
void preOrderTraverse(BinaryTree *binaryTree, int index)
{
	if (binaryTree->datas[index] == 0)
	{
		return;
	}
	printf("%d\t", binaryTree->datas[index]);
	preOrderTraverse(binaryTree, index*2);
	preOrderTraverse(binaryTree, index*2+1);
}
/**
 * 中序遍历：先遍历左子树，然后遍历根结点，最后遍历右子树。
 */
/**
 * 后序遍历：先遍历左子树，然后遍历右子树，最后遍历根结点。
 */
/**
 * 层序遍历：从上到下逐层遍历，在同一层中，按从左到右的顺序遍历。
 */


int main(int argc, char const *argv[])
{	
	BinaryTree *binaryTree = init();
	for (int i = 1; i < 100; ++i)
	{
		add(i, binaryTree);	
	}
	printf("%d\n", getLeft(2, binaryTree));
	printf("%d\n", getRoot(binaryTree));

	printf("前序遍历:\n");
	preOrderTraverse(binaryTree, 1);

	return 0;
}

