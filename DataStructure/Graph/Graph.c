#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// 有向图实现方法

typedef int ElementType;


/*---------------------邻接矩阵实现法----------------------*/
/**
 * 顶点信息
 */
typedef struct _VertexNode1
{
	ElementType data; // 顶点数据
} VertexNode1;
/**
 * 图信息
 */
typedef struct _Graph1
{
	VertexNode1 *vertexs; // 顶点数组
	int **edges; // 边的信息，邻接矩阵

	int vertexNum; // 点数
	int edgeNum; // 边数
} Graph1;
/*---------------------邻接矩阵实现法----------------------*/


/*---------------------邻接表实现法----------------------*/
/**
 * 边信息
 */
typedef struct _EdgeNode2
{
	int index;
	struct _EdgeNode2 *next; // 指向起点相同的下一个顶点指针	
} EdgeNode2;
/**
 * 顶点信息
 */
typedef struct _VertexNode2
{
	int index; // 顶点数组中的坐标
	EdgeNode2 *headNode; // 该顶点所指向的顶点链表
} VertexNode2;
/**
 * 图信息
 */
typedef struct _Graph2
{
	VertexNode2 *vertexs; // 顶点数组

	int vertexNum; // 点数
	int edgeNum; // 边数
} Graph2;
/*---------------------邻接表实现法----------------------*/



/*---------------------十字链表实现法--------------------*/
/**
 * 边信息
 */
typedef struct _EdgeNode3
{
	int headVex; // 边的终点在顶点数组中的下标
	int tailVex; // 边的起点在顶点数组中的下标

	struct _EdgeNode3 *headNext; // 指入边表指针域
	struct _EdgeNode3 *tailNext; // 指出边表指针域
} EdgeNode3;
/**
 * 顶点信息
 */
typedef struct _VertexNode3
{
	int data; // 存放数据
	EdgeNode3 *firstIn; // 入边表（即是逆邻接表中的单链表）头指针
	EdgeNode3 *firstOut; // 出边表（即是邻接表中的单链表）头指针
} VertexNode3;
/**
 * 图信息
 */
typedef struct _Graph3
{
	VertexNode3 *vertexs; // 顶点数组

	int vertexNum; // 点数
	int edgeNum; // 边数
} Graph3;
/*---------------------十字链表实现法--------------------*/





