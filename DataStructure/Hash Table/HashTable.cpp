//
//  main.cpp
//  HashTable
//
//  Created by roger wu on 2017/3/15.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//

// 散列表概念：
// 是根据键而直接访问内存存储位置的数据结构
// 它通过计算一个关于键值的函数，将所需查询的数据映射到表中一个位置来访问记录，这加快了查找速度

// 需要解决的问题:
//   1）能不能支持所有的对象而不仅限于整数？
//　　2）如何支持所有整数而不只是正整数？
//　　3）被删除了的槽仍然占用查找时间。
//　　4）随着时间的推移，被标记为碰撞的槽越来越多，怎么办？
//　　5）必须在创建容器的时候指定大小，不能自动扩张。
//　　6）只是一个 HashSet，而不是HashTable。

// 关键点:
// 键值函数
// 基础数据结构是数组加链表
// 负载因子要控制在一定范围内

#include <iostream>


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
