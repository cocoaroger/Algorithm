//
//  RBTree.hpp
//  Tree
//
//  Created by roger wu on 2017/3/12.
//  Copyright © 2017年 cocoaroger. All rights reserved.
//

#ifndef RBTree_hpp
#define RBTree_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef enum : int {
  Red = 0,
  Black = 1,
} RBColor;

template <class T>
class RBNode {
public:
  RBColor color;
  T key;
  RBNode *parent;
  RBNode *left;
  RBNode *right;
  
  RBNode(T value, RBColor color, RBNode *parent, RBNode *left, RBNode *right):
  key(value), color(color), parent(parent), left(left), right(right) {}
};


template <class T>
class RBTree {
private:
  RBNode<T> *root; // 根节点
  
public:
  RBTree();
  ~RBTree();
  
  /**
   递归查找
   
   @param key 键值
   @return 节点
   */
  RBNode<T>* search(T key);
  /**
   非递归查找
   */
  RBNode<T>* iterativeSearch(T key);
  
  /**
   插入节点
   */
  void insert(T key);
  /**
   删除节点
   */
  void remove(T key);
  
  /**
   销毁
   */
  void destrory();
  /**
   打印
   */
  void print();
  /**
   中序遍历
   */
  void inOrder();
  
private:
  
  /**
   递归查找"红黑树tree"中键值为key的节点

   @param tree 以改节点作为红黑树
   @param key 键值
   @return 查询到的节点
   */
  RBNode<T>* search(RBNode<T> *tree, T key) const;
  /*
   非递归查找
   */
  RBNode<T>* iterativeSearch(RBNode<T> *tree, T key) const;
  
  /**
   左旋（对节点x进行左旋）
   */
  void leftRotate(RBNode<T>* &root, RBNode<T>* x);
  // 右旋
  void rightRotate(RBNode<T>* &root, RBNode<T>* y);
  // 插入修正函数
  void insertFixUp(RBNode<T>* &root, RBNode<T>* node);
  // 插入函数
  void insert(RBNode<T>* &root, RBNode<T>* node);
  // 删除修正函数
  void removeFixUp(RBNode<T>* &root, RBNode<T>* node, RBNode<T>* parent);
  // 删除函数
  void remove(RBNode<T>* &root, RBNode<T>* node);
  
  // 销毁
  void destrory(RBNode<T>* &tree);
  /**
   打印

   @param tree 根节点
   @param key 节点值
   @param direction 0：表示根节点 -1：左孩子 1：右孩子 
   */
  void print(RBNode<T>* tree, T key, int direction);
  /**
   中序遍历
   */
  void inOrder(RBNode<T>* node) const;
  
#define rb_parent(node)    ((node)->parent)
#define rb_color(node)    ((node)->color)
#define rb_is_red(node)    ((node)->color == Red)
#define rb_is_black(node)    ((node)->color == Black)
#define rb_set_red(node)    do { (node)->color = Red; } while (0)
#define rb_set_black(node)    do { (node)->color = Black; } while (0)
#define rb_set_parent(node, parent)    do { (node)->parent = (parent); } while (0)
#define rb_set_color(node, color)    do { (node)->color = (color); } while (0)

};


// MARK: Public Method
/*
 构造函数
 */
template <class T>
RBTree<T>::RBTree():root(NULL) {
  root = NULL;
}

/*
 析构函数
 */
template <class T>
RBTree<T>::~RBTree() {
  destrory();
}

template <class T>
RBNode<T>* RBTree<T>::search(T key) {
  return search(root, key);
}

template <class T>
RBNode<T>* RBTree<T>::iterativeSearch(T key) {
  return iterativeSearch(root, key);
}

template <class T>
void RBTree<T>::insert(T key) {
  RBNode<T> *z = NULL;
  if ((z = new RBNode<T>(key, Black, NULL, NULL, NULL)) == NULL) {
    return;
  }
  
  insert(root, z);
}

template <class T>
void RBTree<T>::remove(T key) {
  RBNode<T> *node;
  if ((node = search(key)) != NULL) {
    remove(root, node);
  }
}

template <class T>
void RBTree<T>::destrory() {
  destrory(root);
}

template <class T>
void RBTree<T>::print() {
  if (root != NULL) {
    print(root, root->key, 0);
  }
}

template <class T>
void RBTree<T>::inOrder() {
  inOrder(root);
}

// MARK: Private Method
template <class T>
RBNode<T>* RBTree<T>::search(RBNode<T> *tree, T key) const {
  if (tree == NULL || tree->key == key) {
    return tree;
  }
  
  if (key < tree->key) {
    return search(tree->left, key);
  } else {
    return search(tree->right, key);
  }
}

template <class T>
RBNode<T>* RBTree<T>::iterativeSearch(RBNode<T> *tree, T key) const {
  RBNode<T>* temp = tree;
  
  while (temp != NULL && temp->key != key) {
    if (key < tree->key) {
      temp = tree->left;
    } else {
      temp = tree->right;
    }
  }
  return temp;
}

/*
 * 对红黑树的节点(x)进行左旋转
 *
 * 左旋示意图(对节点x进行左旋)：
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \                #
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */
template <class T>
void RBTree<T>::leftRotate(RBNode<T>* &root, RBNode<T>* x) {
  RBNode<T> *y = x->right;
  
  // 1. y的左节点赋值给x的右节点
  x->right = y->left;
  if (y->left != NULL) {
    y->left->parent = x;
  }
  
  // 2. x的parent赋值给y的parent
  y->parent = x->parent;
  if (x->parent == NULL) {
    root = y;
  } else {
    if (x->parent->left == x) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
  }
  
  // 3. 将x设置为y的左节点，x的父节点设置为y
  y->left = x;
  x->parent = y;
}


template <class T>
void RBTree<T>::rightRotate(RBNode<T>* &root, RBNode<T>* y) {
  RBNode<T>* x = y->left;
  
  // 1. 将x的右节点赋值给y的左节点
  y->left = x->right;
  if (x->right != NULL) {
    x->right->parent = y;
  }
  
  // 2. 将y的parent赋值给x的parent
  x->parent = y->parent;
  if (y->parent == NULL) {
    root = x;
  } else {
    if (y == y->parent->right) {
      y->parent->right = x;
    } else {
      y->parent->left = x;
    }
  }
  
  // 3. 将y设置为x的左节点，y的父节点设为x
  x->right = y;
  y->parent = x;
}

template <class T>
/**
 插入修正函数
 在向红黑树中插入节点之后(失去平衡)，再调用该函数；
 目的是将它重新塑造成一颗红黑树。
 @param root 红黑树根节点
 @param node 插入的节点
 */
void RBTree<T>::insertFixUp(RBNode<T>* &root, RBNode<T>* node) {
  RBNode<T> *parent, *gparent;
  
  // 若“父节点存在，并且父节点的颜色是红色”
  while ((parent = rb_parent(node)) && rb_is_red(parent)) {
    gparent = rb_parent(parent);
    
    // 若“父节点”是“祖父节点”的左孩子
    if (parent == gparent->left) {
      // case 1: 叔叔节点是红色
      {
        RBNode<T> *uncle = gparent->right;
        if (uncle && rb_is_red(uncle)) {
          rb_set_black(uncle);
          rb_set_black(parent);
          rb_set_red(gparent);
          node = gparent;
          continue;
        }
      }
      
      // case 2: 叔叔是黑色，且当前节点是右孩子
      if (parent->right == node) {
        RBNode<T> *temp;
        leftRotate(root, parent);
        temp = parent;
        parent = node;
        node = temp;
      }
      
      // case 3: 叔叔是黑色，且当前节点是左孩子
      rb_set_black(parent);
      rb_set_red(gparent);
      rightRotate(root, gparent);
      
    } else { // 若“node的父节点”是“node的祖父节点的右孩子”
      // case 1: 叔叔节点是红色
      {
        RBNode<T> *uncle = gparent->left;
        if (uncle && rb_is_red(uncle)) {
          rb_set_black(uncle);
          rb_set_black(parent);
          rb_set_red(gparent);
          node = gparent;
          continue;
        }
      }
      
      // case 2: 叔叔是黑色，且当前节点是左孩子
      if (parent->left == node) {
        RBNode<T> *temp;
        rightRotate(root, parent);
        temp = parent;
        parent = node;
        node = temp;
      }
      
      // case 3: 叔叔是黑色，且当前节点是右孩子
      rb_set_black(parent);
      rb_set_red(gparent);
      leftRotate(root, gparent);
    }
  }
  
  // 将根节点设为黑色
  rb_set_black(root);
}

template <class T>
void RBTree<T>::insert(RBNode<T>* &root, RBNode<T>* node) {
  RBNode<T> *y = NULL;
  RBNode<T> *x = root;
  
  // 1. 将红黑树当做一颗二叉查找树，讲节点添加到二叉查找树中
  while (x != NULL) {
    y = x;
    if (node->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  
  node->parent = y;
  if (y != NULL) {
    if (node->key < y->key) {
      y->left = node;
    } else {
      y->right = node;
    }
  } else {
    root = node;
  }
  
  // 2. 设置节点颜色为红色
  node->color = Red;
  
  // 3. 修正
  insertFixUp(root, node);
}

template <class T>
void RBTree<T>::removeFixUp(RBNode<T>* &root, RBNode<T>* node, RBNode<T>* parent) {
  RBNode<T> *other;
  
  while ((!node || rb_is_black(node)) && node != root) {
    if (parent->left == node) {
      other = parent->right;
      if (rb_is_red(other)) {
        // case 1: x的兄弟w是红色的
        rb_set_black(other);
        rb_set_red(parent);
        leftRotate(root, parent);
        other = parent->right;
      }
      
      if ((!other->left || rb_is_black(other->left)) &&
          (!other->right || rb_is_black(other->right))) {
        // case 2: x的兄弟w是黑色，且w的两个孩子也都是黑色的
        rb_set_red(other);
        node = parent;
        parent = rb_parent(node);
      } else {
        if (!other->right || rb_is_black(other->right)) {
          // case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色
          rb_set_black(other->left);
          rb_set_red(other);
          rightRotate(root, other);
          other = parent->right;
        }
        
        // case 4: x的兄弟是黑色的；并且w的右孩子是红色的，左孩子任意颜色
        rb_set_color(other, parent->color);
        rb_set_black(parent);
        rb_set_black(other->right);
        leftRotate(root, parent);
        node = root;
        break;
      }
    } else {
      other = parent->left;
      if (rb_is_red(other)) {
        // case 1: x的兄弟w是红色的
        rb_set_black(other);
        rb_set_red(parent);
        rightRotate(root, parent);
        other = parent->left;
      }
      
      if ((!other->left || rb_is_black(other->left)) &&
          (!other->right || rb_is_black(other->right))) {
        // case 2: x的兄弟w是黑色，且w的两个孩子也都是黑色
        rb_set_red(other);
        node = parent;
        parent = rb_parent(node);
      } else {
        if (!other->left || rb_is_black(other->left)) {
          // case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子是黑色
          rb_set_black(other->right);
          rb_set_red(other);
          leftRotate(root, other);
          other = parent->left;
        }
        
        // case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色
        rb_set_color(other, parent->color);
        rb_set_black(parent);
        rb_set_black(other->left);
        rightRotate(root, parent);
        node = root;
        break;
      }
    }
  }
  
  if (node) {
    rb_set_black(node);
  }
}

template <class T>
void RBTree<T>::remove(RBNode<T>* &root, RBNode<T>* node) {
  RBNode<T> *child, *parent;
  RBColor color;
  
  // 被删除节点的“左右孩子都不为空”的情况
  if ((node->left != NULL) && (node->right != NULL)) {
    
    // 被删节点的后继节点。（称为“取代节点”）
    // 用它来取代“被删节点”的位置，然后再将“被删节点”去掉
    RBNode<T> *replace = node;
    
    // 获取后继节点
    replace = node->right;
    while (replace->left != NULL) {
      replace = replace->left;
    }
    
    // “node节点”不是根节点（只有根节点不存在父节点）
    if (rb_parent(node)) {
      if (rb_parent(node)->left == node) {
        rb_parent(node)->left = replace;
      } else {
        rb_parent(node)->right = replace;
      }
    } else {
      // “node节点”是根节点，更新根节点
      root = replace;
    }
    
    // child是"取代节点"的右孩子，也是需要"调整的节点"。
    // "取代节点"肯定不存在左孩子！因为它是一个后继节点。
    child = replace->right;
    parent = rb_parent(replace);
    // 保存"取代节点"的颜色
    color = rb_color(replace);
    
    // "被删除节点"是"它的后继节点的父节点"
    if (parent == node) {
      parent = replace;
    } else {
      // child 不为空
      if (child) {
        rb_set_parent(child, parent);
      }
      parent->left = child;
      
      replace->right = node->right;
      node->right->parent = replace;
    }
    
    replace->parent = node->parent;
    replace->color = node->color;
    replace->left = node->left;
    node->left->parent = replace;
    
    if (color == Black) {
      removeFixUp(root, child, parent);
    }
    
    delete node;
    return;
  }
  
  if (node->left != NULL) {
    child = node->left;
  } else {
    child = node->right;
  }
  
  parent = node->parent;
  // 保存“取代节点”的颜色
  color = node->color;
  
  if (child) {
    child->parent = parent;
  }
  
  // “node节点”不是根节点
  if (parent) {
    if (parent->left == node) {
      parent->left = child;
    } else {
      parent->right = child;
    }
  } else {
    root = child;
  }
  
  if (color == Black) {
    removeFixUp(root, child, parent);
  }
  delete node;
}

template <class T>
void RBTree<T>::destrory(RBNode<T>* &tree) {
  if (tree == NULL) {
    return;
  }
  
  if (tree->left != NULL) {
    return destrory(tree->left);
  } else if (tree->right != NULL) {
    return destrory(tree->right);
  }
  
  delete tree;
  tree = NULL;
}

template <class T>
void RBTree<T>::print(RBNode<T> *tree, T key, int direction) {
  if (tree != NULL) {
    if (direction == 0) {
      cout << tree->key << " (Black) is root" << endl;
    } else {
      cout << tree->key << (rb_is_red(tree) ? " Red" : " Black") << " is " << key << "'s " << (direction == 1 ? "right child" : "left child") << endl;
    }
    
    print(tree->left, tree->key, -1);
    print(tree->right, tree->key, 1);
  }
}

template <class T>
void RBTree<T>::inOrder(RBNode<T> *node) const {
  if (node != NULL) {
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
  }
}

#endif /* RBTree_hpp */





















