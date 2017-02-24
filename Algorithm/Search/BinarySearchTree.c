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

#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct _BinaryNode
{
	Type key; // 关键字（键值）
	struct _BinaryNode *left; // 左子树
	struct _BinaryNode *right; // 右子树
	struct _BinaryNode *parent; // 父节点
} BinaryNode;

BinaryNode* create_node(Type key, BinaryNode *parent, BinaryNode *left, BinaryNode *right) {
	BinaryNode *node = (BinaryNode*)malloc(sizeof(BinaryNode));
	if (node == NULL)
		return NULL;

	node->key = key;
	node->left = left;
	node->right = right;
	node->parent = parent;

	return node;
}

void preorder(BinaryNode *root) {
	if (root != NULL)
	{
		printf("%d\n", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(BinaryNode *root) {
	if (root != NULL)
	{
		preorder(root->left);
		printf("%d\n", root->key);
		preorder(root->right);
	}
}

void postorder(BinaryNode *root) {
	if (root != NULL)
	{
		preorder(root->left);
		preorder(root->right);
		printf("%d\n", root->key);
	}
}

/**
 * 递归查找
 * @param  tree [description]
 * @param  key  [description]
 * @return      [description]
 */
BinaryNode* bstree_search(BinaryNode *tree, Type key) {
	if (tree == NULL || key == tree->key)
	{
		return tree;
	}
	if (key > tree->key)
	{
		bstree_search(tree->right, key);
	} else {
		bstree_search(tree->left, key);
	}
	return tree;
}
/**
 * 非递归查找
 * @param  tree [description]
 * @param  key  [description]
 * @return      [description]
 */
BinaryNode* iterative_search(BinaryNode *tree, Type key) {
	while(tree != NULL && tree->key != key) {
		if (tree->key > key)
		{
			tree = tree->right;
		} else {
			tree = tree->left;
		}
	}
	return tree;
}
/**
 * 查找最大节点，右边一直遍历到底
 * @param  tree [description]
 * @return      [description]
 */
BinaryNode* search_max(BinaryNode *tree) {
	if (tree == NULL)
	{
		return NULL;
	}

	while(tree->right != NULL) {
		tree = tree->right;
	}
	return tree;
}
/**
 * 查找最小节点，左边一直遍历到底
 * @param  tree [description]
 * @return      [description]
 */
BinaryNode* search_min(BinaryNode *tree) {
	if (tree == NULL)
	{
		return NULL;
	}

	while(tree->left != NULL) {
		tree = tree->left;
	}
	return tree;
}
/**
 * 插入
 * @param  tree    [description]
 * @param  newNode 新节点
 * @return         [description]
 */
BinaryNode* bstree_insert(BinaryNode *tree, BinaryNode *newNode) {
	BinaryNode *parentNode = NULL;
	BinaryNode *tempTree = tree;

	while(tempTree != NULL) { // 查找新节点插入的位置
		parentNode = tempTree;

		if (newNode->key < tempTree->key)
		{
			tempTree = tempTree->left;
		} else if (newNode->key > tempTree->key) {
			tempTree = tempTree->right;
		} else { // key指相同的不插入树，直接返回树
			free(newNode);
			return tree;
		}
	}

	newNode->parent = parentNode;
	if (parentNode == NULL) // 没有找到位置，就做tree的root节点
	{
		tree = newNode;
	} else if (newNode->key < parentNode->key)
	{
		parentNode->left = newNode;
	} else {
		parentNode->right = newNode;
	}
	return tree;
}
/**
 * 插入
 * @param  tree [description]
 * @param  key  新关键值
 * @return      [description]
 */
BinaryNode* insert(BinaryNode *tree, Type key) {
	BinaryNode *newNode = create_node(key, NULL, NULL, NULL);
	return bstree_insert(tree, newNode);
}

/**
 * 打印二叉树
 * @param tree      树
 * @param key       值
 * @param direction 方向 0是根，-1是做，1是右
 */
void print_bstree(BinaryNode *tree, Type key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)
		{
			printf("%2d is root\n", tree->key);
		} else {
			printf("%2d is %2d's %6s child\n", tree->key, key, direction ? "right" : "left");
		}

		print_bstree(tree->left, tree->key, -1);
		print_bstree(tree->right, tree->key, 1);
	}
}

/**
 * 销毁二叉树
 * @param tree [description]
 */
void destroy_bstree(BinaryNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	if (tree->left != NULL)
	{
		destroy_bstree(tree->left);
	}
	if (tree->right != NULL)
	{
		destroy_bstree(tree->right);
	}
	free(tree);
}



































