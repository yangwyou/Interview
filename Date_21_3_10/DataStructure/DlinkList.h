#pragma once
#ifndef DLINKLIST_H
#define DLINKLIST_H

typedef int DataType;

typedef struct DLNode
{
	DataType Elem;
	DLNode* prior;
	DLNode* next;
}DLinkList;

void DLinkListInit(DLinkList*& L);//初始化双链表
void DLinkListDestroy(DLinkList* L); //双链表销毁
bool isDLinkListEmpty(DLinkList* L);//判断链表是否为空
int  DLinkListLength(DLinkList* L);  //求双链表的长度
void DLinkListDisplay(DLinkList* L); //输出双链表
DataType DLinkListGetElem(DLinkList* L, int i); //获取第i个位置的元素
bool DLinkListInsert(DLinkList*& L, int i, DataType e);//在第i个位置插入元素e
DataType DLinkListDelete(DLinkList*& L, int i);//删除第i个位置上的值，并返回其值
#endif