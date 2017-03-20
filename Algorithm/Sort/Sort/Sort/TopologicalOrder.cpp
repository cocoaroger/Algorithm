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
  ENode *node1;
  
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
    
    node1 = new ENode();
    node1->index = p2;
    
    if (_vertexs[p1].firstEdge == NULL) {
      _vertexs[p1].firstEdge = node1;
    } else {
      linkLast(_vertexs[p1].firstEdge, node1);
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
  ENode *node;
  
  visited[i] = 1;
  cout << _vertexs[i].data << " ";
  node = _vertexs[i].firstEdge;
  while (node != NULL) {
    if (!visited[node->index]) {
      DFS(node->index, visited);
    }
    node = node->nextEdge;
  }
}

void ListDG::DFS() {
  int *visited; // 顶点访问标记
  
  visited = new int(_vertexNum);
  for (int i = 0; i < _vertexNum; i++) {
    visited[i] = 0;
  }
  
  cout << "== DFS:";
  for (int i = 0; i < _vertexNum; i++) {
    if (!visited[i]) {
      DFS(i, visited);
    }
  }
  cout << endl;
  
  delete []visited;
}

void ListDG::BFS() {
  int head = 0, rear = 0;
  int *queue;
  int *visited;
  ENode *node;
  
  queue = new int(_vertexNum);
  visited = new int(_vertexNum);
  for (int i = 0; i < _vertexNum; i++) {
    visited[i] = 0;
  }
  
  cout << "==BFS:";
  int j, k;
  for (int i = 0; i < _vertexNum; i++) {
    if (!visited[i]) {
      visited[i] = 1;
      cout << _vertexs[i].data << " ";
      queue[rear++] = i; // 入队列
    }
    
    while (head != rear) {
      j = queue[head++]; // 出队列
      node = _vertexs[j].firstEdge;
      
      while (node != NULL) {
        k = node->index;
        if (!visited[k]) {
          visited[k] = 1;
          cout << _vertexs[k].data << " ";
          queue[rear++] = k;
        }
        node = node->nextEdge;
      }
    }
  }
  
  cout << endl;
  delete []visited;
  delete []queue;
}

void ListDG::print() {
  ENode *node;
  
  cout << "== List Graph:" << endl;
  for (int i = 0; i < _vertexNum; i++) {
    cout << i << "(" << _vertexs[i].data << "):";
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
  
  return 0;
}




























