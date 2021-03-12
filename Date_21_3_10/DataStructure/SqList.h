#pragma once
#ifndef SQLIST_H
#define SQLIST_H

#define MaxSize 50
typedef int DataType;

struct SqList  //顺序表相当于一个数组，这个结构体就已经表示了整个顺序表
{
	DataType data[MaxSize];
	int length;  //表示顺序表实际长度
};//顺序表类型定义


void InitSqList(SqList*& L);

//释放顺序表
void DestroySqList(SqList* L);

//判断是否为空表
int isSqListEmpty(SqList* L);

//返回顺序表的实际长度
int SqListLength(SqList* L);

//获取顺序表中第i个元素值
DataType SqListGetElem(SqList* L, int i);

//在顺序表中查找元素e,并返回在顺序表哪个位置
int GetElemLocate(SqList* L, const DataType e);

//在第i个位置插入元素
int SqListInsert(SqList*& L, int i, DataType e);

//删除第i个位置元素,并返回该元素的值
DataType SqListElem(SqList* L, int i);

#endif