#pragma once
#ifndef SQLIST_H
#define SQLIST_H

#define MaxSize 50
typedef int DataType;

struct SqList  //˳����൱��һ�����飬����ṹ����Ѿ���ʾ������˳���
{
	DataType data[MaxSize];
	int length;  //��ʾ˳���ʵ�ʳ���
};//˳������Ͷ���


void InitSqList(SqList*& L);

//�ͷ�˳���
void DestroySqList(SqList* L);

//�ж��Ƿ�Ϊ�ձ�
int isSqListEmpty(SqList* L);

//����˳����ʵ�ʳ���
int SqListLength(SqList* L);

//��ȡ˳����е�i��Ԫ��ֵ
DataType SqListGetElem(SqList* L, int i);

//��˳����в���Ԫ��e,��������˳����ĸ�λ��
int GetElemLocate(SqList* L, const DataType e);

//�ڵ�i��λ�ò���Ԫ��
int SqListInsert(SqList*& L, int i, DataType e);

//ɾ����i��λ��Ԫ��,�����ظ�Ԫ�ص�ֵ
DataType SqListElem(SqList* L, int i);

#endif