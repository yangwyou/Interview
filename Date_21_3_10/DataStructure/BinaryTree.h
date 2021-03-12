#pragma once

#define MaxSize 100      //树的深度
typedef char DataType;

typedef struct BTNode    //定义一个二叉树节点
{
	DataType Elem;
	BTNode* Lchild;
	BTNode* Rchild;
}LinkBTree;

void LinkBTreeCreate(LinkBTree*& BT, char* str);//有str创建二叉链
LinkBTree* LinkBTreeFindNode(LinkBTree* BT, DataType e); //返回e的指针
LinkBTree* LinkBTreeLchild(LinkBTree* p);//返回*p节点的左孩子节点指针
LinkBTree* LinkBTreeRight(LinkBTree* p);//返回*p节点的右孩子节点指针
int LinkBTreeDepth(LinkBTree* BT);//求二叉链的深度
void LinkBTreeDisplay(LinkBTree* BT);//以括号法输出二叉链
int LinkBTreeWidth(LinkBTree* BT);//求二叉链的宽度
int LinkBTreeNodes(LinkBTree* BT);//求节点个数
int LinkBTreeLeafNodes(LinkBTree* BT);//求二叉链的叶子节点个数

void LinkBTreeProOeder(LinkBTree* BT); //前序递归遍历
void LinkBTreeProOederRecursion(LinkBTree* BT);//前序非递归遍历
void LinkBTreeInOeder(LinkBTree* BT);//中序递归遍历
void LinkBTreeInOederRecursion(LinkBTree* BT);//中序非递归遍历
void LinkBTreePostOeder(LinkBTree* BT);//后序递归遍历
void LinkBTreePostOederRecursion(LinkBTree* BT);//后序非递归遍历

