//
//  TopologicalOrder.cpp
//  Sort
//
//  Created by roger wu on 2017/3/19.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//

#include "TopologicalOrder.hpp"
#include <memory>
#include <iostream>
using namespace std;

ListDG::ListDG() {
  char c1, c2;
  int p1, p2;
  ENode *node1;
  
  // 输入“顶点数”和“边数”
  cout << "输入顶点数：";
  cin >> _vertexNum;
  cout << "输入边数：";
  cin >> _edgeNum;
  
  if (_vertexNum < 1 || _edgeNum < 1 || (_edgeNum > (_vertexNum * (_vertexNum - 1)))) {
    cout << "输入参数有误！" << endl;
    return;
  }
  
  // 初始化“邻接表”的顶点
  for (int i = 0; i < _vertexNum; i++) {
    cout << "vertex(" << i << "):";
    _vertexs[i].data = readChar();
    _vertexs[i].firstEdge = NULL;
  }
  
  // 初始化“邻接表的边”
  for (int i = 0; i < _edgeNum; i++) {
    cout << "edge(" << i << "):";
    c1 = readChar();
    c2 = readChar();
    
    p1 = getPosition(c1);
    p2 = getPosition(c2);
    // 初始化node1
    node1 = new ENode();
    node1->index = p2;
    // 将node1链接到“p1所在链表的末尾”
    if (_vertexs[p1].firstEdge == NULL) {
      _vertexs[p1].firstEdge = node1;
    } else {
      linkLast(_vertexs[p1].firstEdge, node1);
    }
  }
}

ListDG::ListDG(char vertexs[], int vlength, char edges[][2], int elength) {
  char c1, c2;
  int p1, p2;
  ENode *edge;
  
  _vertexNum = vlength;
  _edgeNum = elength;
  _vertexs = new VNode[_vertexNum];
  
  for (int i = 0; i < _vertexNum; i++) {
    _vertexs[i].data = vertexs[i];
    _vertexs[i].firstEdge = NULL;
  }
  
  for (int i = 0; i < _edgeNum; i++) {
    c1 = edges[i][0];
    c2 = edges[i][1];
    
    p1 = getPosition(c1);
    p2 = getPosition(c2);
    
    edge = new ENode();
    edge->index = p2;
    
    if (_vertexs[p1].firstEdge == NULL) {
      _vertexs[p1].firstEdge = edge;
    } else {
      linkLast(_vertexs[p1].firstEdge, edge);
    }
  }
}

ListDG::~ListDG() {
  ENode *node;
  
  for (int i = 0; i < _edgeNum; i++) {
    node = _vertexs[i].firstEdge;
    while (node != NULL) {
      delete node;
      node = node->nextEdge;
    }
  }
  
  delete [] _vertexs;
}

void ListDG::linkLast(ListDG::ENode *list, ListDG::ENode *node) {
  ENode *p = list;
  while (p->nextEdge) {
    p = p->nextEdge;
  }
  p->nextEdge = node;
}

int ListDG::getPosition(char data) {
  for (int i = 0; i < _vertexNum; i++) {
    if (_vertexs[i].data == data) {
      return i;
    }
  }
  return -1;
}

char ListDG::readChar() {
  char ch;
  do {
    cin >> ch;
  } while (!((ch > 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')));
  
  return ch;
}

void ListDG::DFS(int i, int *visited) {
  ENode *edge;
  
  visited[i] = 1;
  cout << _vertexs[i].data << " ";
  edge = _vertexs[i].firstEdge;
  while (edge != NULL) {
    if (!visited[edge->index]) { // 未被访问过
      DFS(edge->index, visited);
    }
    edge = edge->nextEdge;
  }
}

void ListDG::DFS() {
  int *visited = NULL; // 顶点访问标记
  
  visited = new int(_vertexNum);
  for (int i = 0; i < _vertexNum; i++) {
    visited[i] = 0;
  }
  
  cout << "== DFS:";
  for (int i = 0; i < _vertexNum; i++) {
    if (!visited[i]) { // 某个节点未被访问
      DFS(i, visited);
    }
  }
  cout << endl;
  
  delete[] visited;
}

void ListDG::BFS() {
  int head = 0, rear = 0;
  int *queue;
  int *visited;
  ENode *edge;
  
  queue = new int(_vertexNum);
  visited = new int(_vertexNum);
  
  for (int i = 0; i < _vertexNum; i++) {
    visited[i] = 0;
  }
  
  cout << "== BFS:";
  int j, k;
  for (int i = 0; i < _vertexNum; i++) {
    
    if (!visited[i]) { // 未被访问
      visited[i] = 1;
      cout << _vertexs[i].data << " ";
      queue[rear++] = i; // 入队列
    }
    
    while (head != rear) {
      j = queue[head++]; // 出队列
      edge = _vertexs[j].firstEdge;
      
      while (edge != NULL) {
        k = edge->index;
        if (!visited[k]) {
          visited[k] = 1;
          cout << _vertexs[k].data << " ";
          queue[rear++] = k;
        }
        edge = edge->nextEdge;
      }
    }
  }
  cout << endl;
  
  delete[] visited;
  delete[] queue;
}

void ListDG::print() {
  ENode *node;
  
  cout << "== List Graph:" << endl;

  for (int i = 0; i < _vertexNum; i++) {
    cout << i << " (" << _vertexs[i].data << "): ";
    node = _vertexs[i].firstEdge;
    while (node != NULL) {
      cout << node->index << "(" << _vertexs[node->index].data << ") ";
      node = node->nextEdge;
    }
    cout << endl;
  }
}

/**
 拓扑排序

 @return -1：失败 0：失败 1：成功并输出结果
 */
int ListDG::topologicalOrder() {
  int i = 0, j = 0, index = 0;
  int head = 0, rear = 0; // 辅助队列的头和尾
  int *queue; // 辅助队列
  int *ins; // 入度数组
  char *tops; // 拓扑排序结果数组，记录每个节点的排序后的序号
  ENode *node;
  
  ins = new int(_vertexNum);
  queue = new int(_vertexNum);
  tops = new char(_vertexNum);
  
  // 统计每个顶点的入度
  for (i = 0; i < _vertexNum; i++) {
    node = _vertexs[i].firstEdge;
    while (node != NULL) {
      ins[node->index]++;
      node = node->nextEdge;
    }
  }
  
  // 将所有入度为0的顶点入队列
  for (i = 0; i < _vertexNum; i++) {
    if (ins[i] == 0) {
      queue[rear++] = i; // 入队列
    }
  }
  
  while (head != rear) { // 队列非空
    j = queue[head++]; // 出队列，j是顶点的序号
    tops[index++] = _vertexs[j].data; // 将该顶点添加到tops中，tops是排序结果
    node = _vertexs[j].firstEdge; // 获取以该顶点为起点的出边队列
    
    // 将与"node"关联的节点的入度减1；
    // 若减1之后，该节点的入度为0；则将该节点添加到队列中。
    while (node != NULL) {
      // 将节点(序号为node->ivex)的入度减1。
      ins[node->index]--;
      // 若节点的入度为0，则将其"入队列"
      if (ins[node->index] == 0) {
        queue[rear++] = node->index; // 入队列
      }
      
      node = node->nextEdge;
    }
  }
  
  if (index != _vertexNum) {
    cout << "Graph has a cycle" << endl;
    delete[] queue;
    delete[] ins;
    delete[] tops;
    return 1;
  }
  
  // 打印拓扑排序结果
  cout << "== TopSort:";
  for (i = 0; i < _vertexNum; i++) {
    cout << tops[i] << " ";
  }
  cout << endl;
  
  delete queue;
  delete ins;
  delete tops;
  return 0;
}




























