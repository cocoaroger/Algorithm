/**
 * 二叉查找树
 *
 * 二叉查找树（英语：Binary Search Tree），也称二叉搜索树、有序二叉树（英语：ordered binary tree），
  查找树的定义非常简单，一句话就是左孩子比父节点小，
  右孩子比父节点大，还有一个特性就是”中序遍历“可以让结点有序。
 */

/**
 * 树的一些案例场景和JAVA实现代码
 *
 * http://www.cnblogs.com/huangxincheng/archive/2012/07/21/2602375.html
 * 
 */

/**
 * 二叉搜索树查找算法
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _BinaryNode
{
	int key; // 节点元素
	int attach; // 附加值
	struct _BinaryNode *left; // 左子树
	struct _BinaryNode *right; // 右子树
} BinaryNode;

BinaryNode* init() {
	BinaryNode *node = (BinaryNode*)malloc(sizeof(BinaryNode));
	node->left = NULL;
	node->right = NULL;
	return node;
}





