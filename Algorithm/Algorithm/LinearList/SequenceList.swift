//
//  SequenceList.swift
//  Algorithm
//
//  Created by roger wu on 2017/1/16.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//

import Foundation

class SequenceList: CustomStringConvertible {
  private var list: NSMutableArray
  private var count = 0 // 元素个数
  private var capacity = 0 // list容量
  
  var description: String {
    get {
      var text = ""
      for element in self.list {
        text += "-> \(element) "
      }
      return text
    }
  }
  
  var length: Int {
    get {
      return count
    }
  }
  
  init(capacity: Int) {
    self.capacity = capacity
    self.list = NSMutableArray(capacity: capacity)
  }
  
  private func checkIndex(index: Int) -> Bool {
    if index < 0 || index > count  {
      print("index错误")
      return false
    } else {
      return true
    }
  }
  
  /// 查询
  func object(index: Int) -> (Bool, Any) {
    if !checkIndex(index: index) {
      return (false, "index错误")
    }
    return (true, list[index])
  }
  
  /// 插入
  @discardableResult
  func insert(_ element: Any, index: Int) -> Bool {
    if !checkIndex(index: index) {
      return false
    }
    
    var i = count
    while i > index {
      list[i] = list[i-1]
      i -= 1
    }
    list[index] = element
    count += 1
    return true
  }
  
  /// 删除
  @discardableResult
  func removeItem(_ index: Int) -> Bool {
    if !checkIndex(index: index) {
      return false
    }
    
    for i in index...count-2 {
      list[i] = list[i+1]
    }
    count -= 1
    list.removeLastObject()
    return true
  }
  
  func add(object: Any) {
    list.add(object)
  }
  
  func lastObject() -> Any? {
    if count == 0 {
      return nil
    } else {
      return list[count-1]
    }
  }
  
  func firstObject() -> Any? {
    if count == 0 {
      return nil
    } else {
      return list[0]
    }
  }
  
  
}
