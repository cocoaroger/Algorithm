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
	AVLTreeNode *node = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
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

/**
 * 查找子树中最大节点
 * @param  tree  要查找的树
 * @return       最大的节点
 */
static AVLTreeNode* avltree_maximun(AVLTreeNode *tree) {
	AVLTreeNode *temp = tree;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

/**
 * 查找最小节点
 * @param  tree 被查找的树
 * @return      最小节点
 */
static AVLTreeNode* avltree_min(AVLTreeNode *tree) {
	AVLTreeNode *temp = tree;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
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
			if (key < tree->left->key)
			{
				tree = left_left_rotation(tree);	
			} else {

				tree = left_right_rotation(tree);
			}	
		}
	}
	else if (key > tree->key) // 插入右子树
	{
		tree->right = avltree_insert(tree->right, key);
		if (HEIGHT(tree->right) - HEIGHT(tree->left) == 2)
		{
			if (key > tree->right->key)
			{
				tree = right_right_rotation(tree);	
			} else {
				tree = right_left_rotation(tree);
			}	
		}
	}
	else // key == tree->key 
	{
		printf("%s\n", "添加失败，不允许添加相同的节点");
	}

	tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;

	return tree;
}

/**
 * 删除节点
 * @param  tree       根节点
 * @param  waitDelete 待删除的节点
 * @return            新的根节点
 */
static AVLTreeNode* delete_node(AVLTreeNode *tree, AVLTreeNode *waitDelete) {
	if (tree == NULL || waitDelete == NULL)
	{
		return NULL;
	}

	if (waitDelete->key < tree->key) // 在左子树
	{
		tree->left = delete_node(tree->left, waitDelete);

		if (HEIGHT(tree->right) - HEIGHT(tree->left) == 2)
		{
			AVLTreeNode *right = tree->right;
			if (HEIGHT(right->left) > HEIGHT(right->right))
			{
				tree = right_left_rotation(tree);
			} else {
				tree = right_right_rotation(tree);
			}
		}
	}
	else if (waitDelete->key > tree->key) // 在右子树
	{
		tree->right = delete_node(tree->right, waitDelete);

		if (HEIGHT(tree->left) - HEIGHT(tree->right) == 2)
		{
			AVLTreeNode *left = tree->left;
			if (HEIGHT(left->right) > HEIGHT(left->left))
			{
				tree = left_right_rotation(tree);
			} else {
				tree = left_left_rotation(tree);
			}
		}
	}
	else { // tree是要删除的节点
		if ((tree->left) && (tree->right)) // tree的左右孩子都非空
		{
			if (HEIGHT(tree->left) > HEIGHT(tree->right))
			{
				// 如果tree的左子树比右子树高；
                // 则(01)找出tree的左子树中的最大节点
                //   (02)将该最大节点的值赋值给tree。
                //   (03)删除该最大节点。
                // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
                AVLTreeNode *max = avltree_maximun(tree->left);
                tree->key = max->key;
                tree->left = delete_node(tree->left, max);
			}
			else 
			{
				// 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                // 则(01)找出tree的右子树中的最小节点
                //   (02)将该最小节点的值赋值给tree。
                //   (03)删除该最小节点。
                // 这类似于用"tree的右子树中最小节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
				AVLTreeNode *min = avltree_min(tree->right);
				tree->key = min->key;
				tree->right = delete_node(tree->right, min);
			}
		}
		else 
		{
			AVLTreeNode *temp = tree;
			tree = tree->left ? tree->left : tree->right;
			free(temp);
		}
		
	}

	return tree;
}

AVLTreeNode* avltree_search(AVLTreeNode *tree, Type key) {
	if (tree == NULL || tree->key == key)
	{
		return tree;
	}

	if (key < tree->key)
	{
		return avltree_search(tree->left, key);
	} else
	{
		return avltree_search(tree->right, key);
	}
}

/**
 * 删除节点，返回根节点
 * @param  tree 根节点
 * @param  key  键值
 * @return      根节点
 */
AVLTreeNode* avltree_delete(AVLTreeNode *tree, Type key) 
{
	AVLTreeNode *temp = avltree_search(tree, key);

	// avltree_search，及二叉查找树的查找方法
	if (temp != NULL)
	{
		tree = delete_node(tree, temp);
	}
	return tree;
}


/*
  * 前序遍历"AVL树"
  */
 void preorder_avltree(AVLTreeNode *tree)
 {
     if(tree != NULL)
     {
         printf("%d ", tree->key);
         preorder_avltree(tree->left);
         preorder_avltree(tree->right);
     }
 }
 
 
 /*
  * 中序遍历"AVL树"
  */
 void inorder_avltree(AVLTreeNode *tree)
 {
     if(tree != NULL)
     {
         inorder_avltree(tree->left);
         printf("%d ", tree->key);
         inorder_avltree(tree->right);
     }
 }
 
 /*
  * 后序遍历"AVL树"
  */
 void postorder_avltree(AVLTreeNode *tree)
 {
     if(tree != NULL)
     {
         postorder_avltree(tree->left);
         postorder_avltree(tree->right);
         printf("%d ", tree->key);
     }
 }

#define ARRAY_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )
/**
 * 测试
 */
int main(int argc, char const *argv[])
{
	static int array[] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};

	AVLTreeNode *root = NULL;

	for (int i = 0; i < ARRAY_SIZE(array); ++i)
	{
		printf("%d\n", array[i]);
		root = avltree_insert(root, array[i]);
	}

	printf("\n前序遍历: ");
    preorder_avltree(root);
    
    printf("\n中序遍历: ");
    inorder_avltree(root);

    printf("\n后序遍历: ");
    postorder_avltree(root);
    printf("\n");

    printf("高度：%d\n", avltree_height(root));
    printf("最小值：%d\n", avltree_min(root)->key);
    printf("最大值：%d\n", avltree_maximun(root)->key);

    int i = 8;
    printf("\n删除根节点：%d\n", 8);
    root = avltree_delete(root, i);

    printf("高度：%d\n", avltree_height(root));
    printf("\n中序遍历: ");
    inorder_avltree(root);

    // 销毁二叉树

	return 0;
}









