//
//  main.cpp
//  Tree
//
//  Created by roger wu on 2017/3/11.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//

#include <iostream>
#include "RBTree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
  
  int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
  int check_insert = 0; // 插入动作的检测开关（0 关闭，1 打开）
  int check_remove = 1; // 删除动作的检测开关（0 关闭，1 打开）
  int i;
  int ilen = (sizeof(a)) / (sizeof(a[0]));
  RBTree<int>* tree = new RBTree<int>();
  
  cout << "== 原始数据：";
  for (i = 0; i < ilen; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
  
  for (i = 0; i < ilen; i ++) {
    tree->insert(a[i]);
    if (check_insert) {
      cout << "== 添加节点：" << a[i] << endl;
      cout << "== 树的详细信息：" << endl;
      tree->print();
      cout << endl;
    }
  }
  
  // 中序遍历
  tree->inOrder();
  cout << endl;
  
  if (check_remove) {
    for (i = 0; i < ilen; i++) {
      tree->remove(a[i]);
      
      cout << "== 删除节点：" << a[i] << endl;
      cout << "== 树的详细信息：" << endl;
      tree->print();
      cout << endl;
    }
  }
  
  // 销毁红黑树
  tree->destrory();
  
  return 0;
}














