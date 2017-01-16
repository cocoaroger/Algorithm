//
//  SinglyLinkedList.swift
//  Algorithm
//
//  Created by roger wu on 2017/1/16.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//

import Foundation

class SinglyNode {
  var data: AnyObject
  var next: SinglyNode?
  
  init(data: AnyObject) {
    self.data = data
  }
}

class SinglyLinkedList {
  private var list: NSMutableArray
  private var count: Int = 0
  
  var length: Int {
    get {
      return count
    }
  }
  
  init() {
    list = NSMutableArray()
  }
  
  
  
}
