#pragma once

#define MaxSize 100      //�������
typedef char DataType;

typedef struct BTNode    //����һ���������ڵ�
{
	DataType Elem;
	BTNode* Lchild;
	BTNode* Rchild;
}LinkBTree;

void LinkBTreeCreate(LinkBTree*& BT, char* str);//��str����������
LinkBTree* LinkBTreeFindNode(LinkBTree* BT, DataType e); //����e��ָ��
LinkBTree* LinkBTreeLchild(LinkBTree* p);//����*p�ڵ�����ӽڵ�ָ��
LinkBTree* LinkBTreeRight(LinkBTree* p);//����*p�ڵ���Һ��ӽڵ�ָ��
int LinkBTreeDepth(LinkBTree* BT);//������������
void LinkBTreeDisplay(LinkBTree* BT);//�����ŷ����������
int LinkBTreeWidth(LinkBTree* BT);//��������Ŀ��
int LinkBTreeNodes(LinkBTree* BT);//��ڵ����
int LinkBTreeLeafNodes(LinkBTree* BT);//���������Ҷ�ӽڵ����

void LinkBTreeProOeder(LinkBTree* BT); //ǰ��ݹ����
void LinkBTreeProOederRecursion(LinkBTree* BT);//ǰ��ǵݹ����
void LinkBTreeInOeder(LinkBTree* BT);//����ݹ����
void LinkBTreeInOederRecursion(LinkBTree* BT);//����ǵݹ����
void LinkBTreePostOeder(LinkBTree* BT);//����ݹ����
void LinkBTreePostOederRecursion(LinkBTree* BT);//����ǵݹ����

