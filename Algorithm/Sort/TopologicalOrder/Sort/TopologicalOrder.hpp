//
//  TopologicalOrder.hpp
//  Sort
//
//  Created by roger wu on 2017/3/19.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//
// 概念：
// 拓扑排序(Topological Order)是指，将一个有向无环图(Directed Acyclic Graph简称DAG)进行度排序，进而得到一个有序的线性序列。


#ifndef TopologicalOrder_hpp
#define TopologicalOrder_hpp

#define MAX 100

// 邻接表
class ListDG {
private: // 内部类
  // 邻接表中表对应的链表的顶点，指向的边信息
  class ENode {
    int index; // 该边所指向的顶点的位置
    ENode *nextEdge; // 指向下一条弧的指针
    friend class ListDG;
  };
  
  // 邻接表中表的顶点
  class VNode {
    char data; // 顶点信息
    ENode *firstEdge; // 指向第一条依附该顶点的弧
    friend class ListDG;
  };
  
private: // 私有成员
  int _vertexNum; // 图的顶点的数目
  int _edgeNum; // 图的边的数目
  VNode *_vertexs; // 图的顶点数组
  
  
public:
  // 创建邻接表对应的图（自己输入）
  ListDG();
  // 创建邻接表
  ListDG(char vertexs[], int vlength, char edges[][2], int elength);
  ~ListDG();
  
  // 深度优先
  void DFS();
  // 广度优先
  void BFS();
  // 打印邻接表图
  void print();
  // 拓扑排序
  int topologicalOrder();
  
private:
  // 读取一个输入字符
  char readChar();
  // 返回data的位置
  int getPosition(char data);
  // 深度优先遍历图的递归实现
  void DFS(int i, int *visited);
  // 将node节点链接到list的最后
  void linkLast(ENode *list, ENode *node);
  
};


#endif /* TopologicalOrder_hpp */














