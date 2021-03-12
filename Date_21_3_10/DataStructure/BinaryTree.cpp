#include<iostream>
#include"BinaryTree.h"
using namespace std;

void LinkBTreeCreate(LinkBTree*& BT, char* str)//��str����������
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
		case '(':top++; St[top] = p; k = 1; break;//Ϊ��ڵ㣬top��ʾ������k��ʾ���ҽڵ㣬����һ��'('��������һ��,����һ��','�����������
		case ')':top--; break;
		case ',':k = 2; break; //Ϊ�ҽڵ�
		default: p = (LinkBTree*)malloc(sizeof(LinkBTree));
			p->Elem = ch;
			p->Lchild = p->Rchild = NULL;
			if (BT == NULL)
			{
				BT = p;   //���ڵ�
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

LinkBTree* LinkBTreeFindNode(LinkBTree* BT, DataType e) //����Ԫ��e��ָ��
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
		p = LinkBTreeFindNode(BT->Lchild, e); //�ݹ�
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

LinkBTree* LinkBTreeLchild(LinkBTree* p)//����*p�ڵ�����ӽڵ�ָ��
{
	return p->Lchild;
}

LinkBTree* LinkBTreeRight(LinkBTree* p)//����*p�ڵ���Һ��ӽڵ�ָ��{
{
	return p->Rchild;
}

int LinkBTreeDepth(LinkBTree* BT)//������������
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

void LinkBTreeDisplay(LinkBTree* BT)//�����ŷ����������
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

int LinkBTreeWidth(LinkBTree* BT)//��������Ŀ��
{
	return 0;
}

int LinkBTreeNodes(LinkBTree* BT)//��ڵ����
{
	if (BT == NULL)
	{
		return 0;
	}
	else if (BT->Lchild == NULL && BT->Rchild == NULL)   //ΪҶ�ӽڵ�����
	{
		return 1;
	}
	else
	{
		return (LinkBTreeNodes(BT->Lchild) + LinkBTreeNodes(BT->Rchild) + 1);
	}
}

int LinkBTreeLeafNodes(LinkBTree* BT)//���������Ҷ�ӽڵ����
{
	if (BT == NULL)
	{
		return 0;
	}
	else if (BT->Lchild == NULL && BT->Rchild == NULL)  //ΪҶ�ӽڵ�����
	{
		return 1;
	}
	else
	{
		return (LinkBTreeLeafNodes(BT->Lchild) + LinkBTreeLeafNodes(BT->Rchild));
	}
}

void LinkBTreeProOeder(LinkBTree* BT) //ǰ��ǵݹ����
{
	LinkBTree* St[MaxSize], * p;
	int top = -1;
	if (BT != NULL)
	{
		top++;
		St[top] = BT;     //����һ��ָ����ڵ�

		while (top > -1)
		{
			p = St[top]; //��һ��
			top--;       //��ջ�����ʸýڵ�
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

void LinkBTreeProOederRecursion(LinkBTree* BT)//ǰ��ݹ����
{
	if (BT != NULL)
	{
		cout << BT->Elem << " ";
		LinkBTreeProOeder(BT->Lchild);
		LinkBTreeProOeder(BT->Rchild);
	}
}

void LinkBTreeInOeder(LinkBTree* BT)//����ǵݹ����
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

void LinkBTreeInOederRecursion(LinkBTree* BT)//����ݹ����
{
	if (BT != NULL)
	{
		LinkBTreeProOeder(BT->Lchild);
		cout << BT->Elem << " ";
		LinkBTreeProOeder(BT->Rchild);
	}
}

void LinkBTreePostOeder(LinkBTree* BT)//����ǵݹ����
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

void LinkBTreePostOederRecursion(LinkBTree* BT)//����ݹ����
{
	if (BT != NULL)
	{
		LinkBTreeProOeder(BT->Lchild);
		LinkBTreeProOeder(BT->Rchild);
		cout << BT->Elem << " ";
	}
}