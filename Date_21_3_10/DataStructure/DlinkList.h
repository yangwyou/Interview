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

void DLinkListInit(DLinkList*& L);//��ʼ��˫����
void DLinkListDestroy(DLinkList* L); //˫��������
bool isDLinkListEmpty(DLinkList* L);//�ж������Ƿ�Ϊ��
int  DLinkListLength(DLinkList* L);  //��˫����ĳ���
void DLinkListDisplay(DLinkList* L); //���˫����
DataType DLinkListGetElem(DLinkList* L, int i); //��ȡ��i��λ�õ�Ԫ��
bool DLinkListInsert(DLinkList*& L, int i, DataType e);//�ڵ�i��λ�ò���Ԫ��e
DataType DLinkListDelete(DLinkList*& L, int i);//ɾ����i��λ���ϵ�ֵ����������ֵ
#endif