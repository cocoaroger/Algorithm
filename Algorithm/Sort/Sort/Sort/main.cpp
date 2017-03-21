//
//  main.cpp
//  Sort
//
//  Created by roger wu on 2017/3/18.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//

#include <iostream>
#include "TopologicalOrder.hpp"

int main(int argc, const char * argv[]) {
  char vertexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  char edges[][2] = {
    {'A', 'G'},
    {'B', 'A'},
    {'B', 'D'},
    {'C', 'F'},
    {'C', 'G'},
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
