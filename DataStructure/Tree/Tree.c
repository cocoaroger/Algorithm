#include <stdlib.h>
#include <stdio.h>

/**
 * 树型结构定义的方法
 */

typedef int ElementType;

/**
 * 双亲表示法
 * 这样的存储结构，我们可以根据结点的parent域在O(1)的时间找到其双亲结点，
 * 但是只能通过遍历整棵树才能找到它的孩子结点。
 */
struct PTree
{
	int size;
	struct PNode *nodes;
};

struct PNode
{
	ElementType data;
	int parent;	
};

/**
 * 孩子表示法
 * 这种结构对于查找某个结点的孩子结点比较容易，
 * 但若想要查找它的双亲或兄弟，则需要遍历整棵树，比较麻烦。
 */
struct ChildNode
{
	ElementType data;
	int degree; // 度
	struct ChildNode *nodes;
};

/**
 * 双亲孩子表示法
 */
struct PCTree
{
	int size;
	struct PNode2 *nodes;
};
struct PNode2
{
	int parent;
	ElementType data;
	struct ChildNode2 *firstChild;
};
struct ChildNode2
{
	int cur; // 存放节点在nodes数组中的下标
	struct ChildNode2 *next;
};

/**
 * 孩子兄弟表示法
 * 这个方法，可以方便的查找到某个结点的孩子，
 * 只需先通过firstChild找到它的第一个孩子，
 * 然后通过rightSib找到它的第二个孩子，
 * 接着一直下去，直到找到想要的孩子。若要查找某个结点的双亲和左兄弟，
 * 使用这个方法则比较麻烦。
 */
struct CBNode
{
	ElementType data;
	struct CBNode *firstChild;
	struct CBNode *rightChild;
};




int main(int argc, char const *argv[])
{
	
	return 0;
}