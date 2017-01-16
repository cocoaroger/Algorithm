//
//  ViewController.swift
//  Algorithm
//
//  Created by roger wu on 2017/1/16.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    let sequenceList = SequenceList(capacity: 100)
    for index in 0...99 {
      sequenceList.insert(index, index: index)
    }
    print(sequenceList)
    print(sequenceList.length)
    
    sequenceList.removeItem(2)
    print(sequenceList)
    print(sequenceList.length)
  }
  
  override func didReceiveMemoryWarning() {
    super.didReceiveMemoryWarning()
  }
}

