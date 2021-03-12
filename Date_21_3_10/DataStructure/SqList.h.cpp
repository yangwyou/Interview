#include<iostream>
#include"SqList.h"
using namespace std;

//初始化顺序表
void InitSqList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList)); // 开辟内存
	L->length = 0;
}

//释放顺序表
void DestroySqList(SqList* L)
{
	if (L == NULL)
	{
		return;
	}
	free(L);
}

//判断是否为空表
int isSqListEmpty(SqList* L)
{
	if (L == NULL)
	{
		return 0;
	}
	return (L->length == 0);
}

//返回顺序表的实际长度
int SqListLength(SqList* L)
{
	if (L == NULL)
	{
		cout << "顺序表分配内存失败" << endl;
		return 0;
	}
	return L->length;
}

//获取顺序表中第i个元素值
DataType SqListGetElem(SqList* L, int i)
{
	if (L == NULL)
	{
		cout << "No Data in SqList" << endl;
		return 0;
	}
	return L->data[i - 1];
}

//在顺序表中查找元素e,并返回在顺序表哪个位置
int GetElemLocate(SqList* L, const DataType e)
{
	if (L == NULL)
	{
		cout << "Empty SqList" << endl;
		return 0;
	}
	int i = 0;
	while (i < L->length && L->data[i] != e)
	{
		i++;
	}
	if (i > L->length)
		return 0;
	return i + 1;
}

//在第i个位置插入元素
int SqListInsert(SqList*& L, int i, DataType e)
{
	if (L == NULL)
	{
		cout << "error" << endl;
		return 0;
	}
	if (i > L->length + 1 || i < 1)
	{
		cout << "error" << endl;
		return 0;
	}
	for (int j = L->length; j >= i - 1; j--) //将i之后的元素后移，腾出空间
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return 1;
}

//删除第i个位置元素,并返回该元素的值
DataType SqListElem(SqList* L, int i)
{
	if (L == NULL)
	{
		cout << "error" << endl;
		return 0;
	}
	if (i < 0 || i > L->length)
	{
		cout << "error" << endl;
		return 0;
	}
	DataType e = L->data[i - 1];
	for (int j = i; j < L->length; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return e;
}