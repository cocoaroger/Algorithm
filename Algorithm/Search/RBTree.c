/*
红黑树的特性:
（1）每个节点或者是黑色，或者是红色。
（2）根节点是黑色。
（3）每个叶子节点（NIL）是黑色。 [注意：这里叶子节点，是指为空(NIL或NULL)的叶子节点！]
（4）如果一个节点是红色的，则它的子节点必须是黑色的。
（5）从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点。

注意：
(01) 特性(3)中的叶子节点，是只为空(NIL或null)的节点。
(02) 特性(5)，确保没有一条路径会比其他路径长出俩倍。因而，红黑树是相对是接近平衡的二叉树。
 */

/*
红黑树的应用
红黑树的应用比较广泛，主要是用它来存储有序的数据，它的时间复杂度是O(lgn)，效率非常之高。
例如，Java集合中的TreeSet和TreeMap，C++ STL中的set、map，以及Linux虚拟内存的管理，都是通过红黑树去实现的。
 */

/*
左旋转
 */

/*
右旋转
 */

/*
区分 左旋 和 右旋
 */

/*
红黑树的基本操作(二) 添加
按二叉查找树的添加方法添加节点，然后想方设法的旋转以及重新着色，使这颗树重新成为红黑树！
 */

/*
红黑树的基本操作(三) 删除
将红黑树内的某一个节点删除。需要执行的操作依次是：首先，将红黑树当作一颗二叉查找树，将该节点从二叉查找树中删除；
然后，通过"旋转和重新着色"等一系列来修正该树，使之重新成为一棵红黑树。
 */

enum RBTColor
{
	Red,
	Black	
};

template <class T>
class RBNode
{
public:
	RBTColor color; // 颜色
	T key; // 关键字（键值）
	RBNode *left;
	RBNode *right;
	RBNode *parent;

	RBNode(T value, RBTColor c, RBNode *l, RBNode *r, RBNode *p):
		key(value), color(c), left(l), right(r), parent(p) {}
};


template <class T>
class RBTree
{
public:
	RBTree();
	~RBTree();
	
};
