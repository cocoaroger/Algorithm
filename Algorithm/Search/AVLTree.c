/**
 * 平衡查找树
 * 平衡二叉搜索树(Balanced Binary Tree)是一种结构平衡的二叉搜索树，
 * 即叶节点深度差不超过1，它能在O(log n)内完成插入、查找和删除操作，
 * 最早被发明的平衡二叉搜索树为AVL树。
 *
 * 常见的平衡二叉搜索树有
	AVL树
	红黑树
	Treap
	节点大小平衡树
 */

/*
AVL树的基本操作一般涉及运作同在不平衡的二叉查找树所运作的同样的算法。
但是要进行预先或随后做一次或多次所谓的"AVL旋转"。
以下图表以四列表示四种情况，每行表示在该种情况下要进行的操作。
在左左和右右的情况下，只需要进行一次旋转操作；在左右和右左的情况下，需要进行两次旋转操作。
 */

// 删除：
// 从AVL树中删除，可以通过把要删除的节点向下旋转成一个叶子节点，
// 接着直接移除这个叶子节点来完成。因为在旋转成叶子节点期间最多有log n个节点被旋转，
// 而每次AVL旋转耗费固定的时间，所以删除处理在整体上耗费O(log n) 时间。
// 

// 搜寻
// 可以像普通二叉查找树一样的进行，所以耗费O(log n)时间，因为AVL树总是保持平衡的。
// 不需要特殊的准备，树的结构不会由于查找而改变。
// （这是与伸展树搜寻相对立的，它会因为搜寻而变更树结构。）

#include <stdlib.h>
#include <stdio.h>

typedef int Type;
/*
获取树的高度
 */
#define HEIGHT(tree) 	( (tree==NULL) ? 0 : (((AVLTreeNode*)(tree))->height) )
/*
获取较大树
 */
#define MAX(a, b) 		((a) > (b) ? (a) : (b))

typedef struct _AVLTreeNode
{
	Type key;
	int height; 
	struct _AVLTreeNode *left;
	struct _AVLTreeNode *right;
} AVLTreeNode;

/**
 * 创建节点
 * @param  key   关键字
 * @param  left  左节点
 * @param  right 右节点
 * @return       [description]
 */
static AVLTreeNode* avltree_create_node(Type key, AVLTreeNode *left, AVLTreeNode *right) {
	AVLTreeNode *node;
	node = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	if (node == NULL)
	{
		return NULL;
	}

	node->key = key;
	node->height = 0;
	node->left = left;
	node->right = right;
	return node;
}

/**
 * 获取树的高度
 * @param  tree [description]
 * @return      [description]
 */
int avltree_height(AVLTreeNode *tree) {
	return HEIGHT(tree);
}

/*
LL结构的旋转方法
 */
static AVLTreeNode* left_left_rotation(AVLTreeNode *rootNode) {
	AVLTreeNode *newRootNode;

	newRootNode = rootNode->left;
	rootNode->left = newRootNode->right;
	newRootNode->right = rootNode;

	rootNode->height = MAX(HEIGHT(rootNode->left), HEIGHT(rootNode->right)) + 1;
	newRootNode->height = MAX(HEIGHT(newRootNode->left), HEIGHT(newRootNode->right)) + 1;

	return newRootNode;
}

/*
RR结构的旋转方法
 */
static AVLTreeNode* right_right_rotation(AVLTreeNode *rootNode) {
	AVLTreeNode *newRootNode;

	newRootNode = rootNode->right;
	rootNode->right = newRootNode->left;
	newRootNode->left = rootNode;

	rootNode->height = MAX( HEIGHT(rootNode->left), HEIGHT(rootNode->right)) + 1;
	newRootNode->height = MAX( HEIGHT(newRootNode->right), HEIGHT(newRootNode->left)) + 1;

	return newRootNode;
}

/*
LR的旋转
LR失去平衡的情况，需要经过两次旋转才能让AVL树恢复平衡
1、根的左子树是RR结构，进行一次左子树RR旋转
2、然后根编程了LL结构，进行一次根LL旋转
 */
static AVLTreeNode* left_right_rotation(AVLTreeNode *rootNode) {
	rootNode->left = right_right_rotation(rootNode->left);
	return left_left_rotation(rootNode);
}

/*
RL的旋转
RL与LR对称
1、根的右子树是LL结构，进行一次右子树LL旋转
2、然后根编程了RR结构，进行一次根RR旋转
 */
static AVLTreeNode* right_left_rotation(AVLTreeNode *rootNode) {
	rootNode->right = left_left_rotation(rootNode->right);
	return right_right_rotation(rootNode);
}

/**
 * 将节点插入到AVL树中，并返回根节点	
 * @param  tree AVL树的根节点
 * @param  key  出入的节点的键值
 * @return      根节点
 */
AVLTreeNode* avltree_insert(AVLTreeNode *tree, Type key) {
	if (tree == NULL)
	{
		tree = avltree_create_node(key, NULL, NULL);
		if (tree == NULL)
		{
			printf("%s\n", "create avltree node failed");
			return NULL;
		}
	} 
	else if (key < tree->key) // 插入左子树
	{
		tree->left = avltree_insert(tree->left, key);
		if (HEIGHT(tree->left) - HEIGHT(tree->right) == 2)
		{
			tree = left_left_rotation(tree);
		}
		else 
		{
			tree = left_right_rotation(tree);
		}
	}
	else if (key > tree->key) // 插入右子树
	{
		tree->right = avltree_insert(tree->right, key);
		if (HEIGHT(tree->right) - HEIGHT(tree->left) == 2)
		{
			tree = right_right_rotation(tree);
		}
		else 
		{
			tree = right_left_rotation(tree);
		}
	}
	else // key == tree->key 
	{
		printf("%s\n", "添加失败，不允许添加相同的节点");
	}

	tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;

	return tree;
}






