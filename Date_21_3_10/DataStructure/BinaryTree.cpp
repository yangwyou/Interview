#include<iostream>
#include"BinaryTree.h"
using namespace std;

void LinkBTreeCreate(LinkBTree*& BT, char* str)//有str创建二叉链
{
	LinkBTree* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;

	char ch;
	BT = NULL;
	ch = str[j];

	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;//为左节点，top表示层数，k表示左右节点，碰到一个'('二叉树加一层,碰到一个','，变成右子树
		case ')':top--; break;
		case ',':k = 2; break; //为右节点
		default: p = (LinkBTree*)malloc(sizeof(LinkBTree));
			p->Elem = ch;
			p->Lchild = p->Rchild = NULL;
			if (BT == NULL)
			{
				BT = p;   //根节点
			}
			else
			{
				switch (k)
				{
				case 1:St[top]->Lchild = p; break;
				case 2:St[top]->Rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

LinkBTree* LinkBTreeFindNode(LinkBTree* BT, DataType e) //返回元素e的指针
{
	LinkBTree* p;

	if (BT == NULL)
	{
		return NULL;
	}
	else if (BT->Elem == e)
	{
		return BT;
	}
	else
	{
		p = LinkBTreeFindNode(BT->Lchild, e); //递归
		if (p != NULL)
		{
			return p;
		}
		else
		{
			return LinkBTreeFindNode(BT->Lchild, e);
		}
	}
}

LinkBTree* LinkBTreeLchild(LinkBTree* p)//返回*p节点的左孩子节点指针
{
	return p->Lchild;
}

LinkBTree* LinkBTreeRight(LinkBTree* p)//返回*p节点的右孩子节点指针{
{
	return p->Rchild;
}

int LinkBTreeDepth(LinkBTree* BT)//求二叉链的深度
{
	int LchildDep, RchildDep;
	if (BT == NULL)
	{
		return 0;
	}
	else
	{
		LchildDep = LinkBTreeDepth(BT->Lchild);
		RchildDep = LinkBTreeDepth(BT->Rchild);
	}
	return (LchildDep > RchildDep) ? (LchildDep + 1) : (RchildDep + 1);
}

void LinkBTreeDisplay(LinkBTree* BT)//以括号法输出二叉链
{
	if (BT != NULL)
	{
		cout << BT->Elem;
		if (BT->Lchild != NULL || BT->Rchild != NULL)
		{
			cout << '(';
			LinkBTreeDisplay(BT->Lchild);
			if (BT->Rchild != NULL)
			{
				cout << ',';
			}
			LinkBTreeDisplay(BT->Rchild);
			cout << ')';

		}
	}
}

int LinkBTreeWidth(LinkBTree* BT)//求二叉链的宽度
{
	return 0;
}

int LinkBTreeNodes(LinkBTree* BT)//求节点个数
{
	if (BT == NULL)
	{
		return 0;
	}
	else if (BT->Lchild == NULL && BT->Rchild == NULL)   //为叶子节点的情况
	{
		return 1;
	}
	else
	{
		return (LinkBTreeNodes(BT->Lchild) + LinkBTreeNodes(BT->Rchild) + 1);
	}
}

int LinkBTreeLeafNodes(LinkBTree* BT)//求二叉链的叶子节点个数
{
	if (BT == NULL)
	{
		return 0;
	}
	else if (BT->Lchild == NULL && BT->Rchild == NULL)  //为叶子节点的情况
	{
		return 1;
	}
	else
	{
		return (LinkBTreeLeafNodes(BT->Lchild) + LinkBTreeLeafNodes(BT->Rchild));
	}
}

void LinkBTreeProOeder(LinkBTree* BT) //前序非递归遍历
{
	LinkBTree* St[MaxSize], * p;
	int top = -1;
	if (BT != NULL)
	{
		top++;
		St[top] = BT;     //将第一层指向根节点

		while (top > -1)
		{
			p = St[top]; //第一层
			top--;       //退栈并访问该节点
			cout << p->Elem << " ";

			if (p->Rchild != NULL)
			{
				top++;
				St[top] = p->Rchild;
			}

			if (p->Lchild != NULL)
			{
				top++;
				St[top] = p->Lchild;
			}
		}
		cout << endl;
	}
}

void LinkBTreeProOederRecursion(LinkBTree* BT)//前序递归遍历
{
	if (BT != NULL)
	{
		cout << BT->Elem << " ";
		LinkBTreeProOeder(BT->Lchild);
		LinkBTreeProOeder(BT->Rchild);
	}
}

void LinkBTreeInOeder(LinkBTree* BT)//中序非递归遍历
{
	LinkBTree* St[MaxSize], * p;
	int top = -1;
	if (BT != NULL)
	{
		p = BT;
		while (top > -1 || p != NULL)
		{
			while (p != NULL)
			{
				top++;
				St[top] = p;
				p = p->Lchild;
			}

			if (top > -1)
			{
				p = St[top];
				top--;
				cout << p->Elem << " ";
				p = p->Rchild;
			}
		}
		cout << endl;
	}
}

void LinkBTreeInOederRecursion(LinkBTree* BT)//中序递归遍历
{
	if (BT != NULL)
	{
		LinkBTreeProOeder(BT->Lchild);
		cout << BT->Elem << " ";
		LinkBTreeProOeder(BT->Rchild);
	}
}

void LinkBTreePostOeder(LinkBTree* BT)//后序非递归遍历
{
	LinkBTree* St[MaxSize], * p;
	int top = -1, flag;
	if (BT != NULL)
	{
		do
		{
			while (BT != NULL)
			{
				top++;
				St[top] = BT;
				BT = BT->Lchild;
			}

			p = NULL;
			flag = 1;
			while (top != -1 && flag)
			{
				BT = St[top];
				if (BT->Rchild == p)
				{
					cout << BT->Elem << " ";
					top--;
					p = BT;
				}
				else
				{
					BT = BT->Lchild;
					flag = 0;
				}
			}
		} while (top != -1);

		cout << endl;
	}
}

void LinkBTreePostOederRecursion(LinkBTree* BT)//后序递归遍历
{
	if (BT != NULL)
	{
		LinkBTreeProOeder(BT->Lchild);
		LinkBTreeProOeder(BT->Rchild);
		cout << BT->Elem << " ";
	}
}