//
//  main.cpp
//  Sort
//
//  Created by roger wu on 2017/3/18.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//  数据结构：图的拓扑排序测试

#include <iostream>
#include "TopologicalOrder.hpp"
#include <algorithm>
#include <iterator>

int main(int argc, const char * argv[]) {
  
  char vertexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; // 顶点
  char edges[][2] = { // 两点，构成一边
    {'A', 'G'},
    {'B', 'A'},
    {'B', 'D'},
    {'F', 'C'},
//    {'C', 'G'},
    {'D', 'E'},
    {'D', 'F'}
  };
  
  int vlength = sizeof(vertexs) / sizeof(vertexs[0]);
  int elength = sizeof(edges) / sizeof(edges[0]);
  
  ListDG *dg;
  
  dg = new ListDG(vertexs, vlength, edges, elength);
  dg->print();
  
  dg->DFS();
  dg->BFS();
  
  dg->topologicalOrder();
  
  return 0;
}
