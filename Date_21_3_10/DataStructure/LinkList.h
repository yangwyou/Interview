#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

typedef int DataType;


//单链表：单链表是一个节点一个节点构成，
//先定义一个节点，节点为一个结构体，当这些节点连在一起，
// 链表为指向头结点的结构体型指针，即是LinkList型指针

typedef struct LNode  //定义的是节点的类型
{
	DataType data;
	struct LNode* next; //指向后继节点
}LinkList;


void InitLinkList(LinkList*& L);    //初始化链表
void DestroyLinkList(LinkList* L); //销毁单链表
int isEmptyLinkList(LinkList* L);  //判断链表是否为空
int LinkListLength(LinkList* L);   //求链表长度
void DisplayLinkList(LinkList* L); //输出链表元素
DataType LinkListGetElem(LinkList* L, int i);//获取第i个位置的元素值
int LinkListLocate(LinkList* L, DataType e);  //元素e在链表的位置
int LinkListInsert(LinkList*& L, int i, DataType e);//在第i处插入元素e
DataType LinkListDelete(LinkList*& L, int i); //删除链表第i处的元素
#endif