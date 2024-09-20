#include "stdio.h"
#include "stdlib.h"
typedef int ElemType;
typedef struct BTNode {
  ElemType data;
  struct BTNode *lchild;
  struct BTNode *rchild;

} BTNode, *BTtree;

// 先序中序后序遍历二叉树(递归)
void pre_print(BTtree T) {
  if (T) {
    printf("%d\n", T->data);
    pre_print(T->lchild);
    pre_print(T->rchild);
  }
}
void in_print(BTtree T) {
  if (T) {
    in_print(T->lchild);
    printf("%d\n", T->data);
    in_print(T->rchild);
  }
}
void last_print(BTtree T) {
  if (T) {
    last_print(T->lchild);
    last_print(T->rchild);
    printf("%d\n", T->data);
  }
}
// 创建节点函数用于构造
BTNode *createNode(ElemType value) {
  BTNode *newNode = (BTNode *)malloc(sizeof(BTNode));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  newNode->data = value;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  return newNode;
}
// 计算二叉树中所有节点个数
// 递归实现,首先判断是否该节点是否为空
int count(BTtree T) {
  if (T == NULL) {
    return 0;
  } else {
    int m = count(T->lchild);
    int n = count(T->rchild);
    return m + n + 1;
  }
}
int main() {

  BTNode *root = createNode(10);         // 创建根节点
  root->lchild = createNode(20);         // 创建左子节点
  root->rchild = createNode(30);         // 创建右子节点
  root->lchild->lchild = createNode(40); // 左子节点的左子节点
  root->lchild->rchild = createNode(50); // 左子节点的右子节点
  root->rchild->lchild = createNode(60); // 右子节点的左子节点
  root->rchild->rchild = createNode(70); // 右子节点的右子节点
  /* 上述操作构造的二叉树形状如下
      10
     /  \
   20    30
  / \   / \
40  50 60 70

   */

  // pre_print(root);
  int result = count(root);
  printf("%d\n", result);
  return 0;
}
