#include<iostream>
#include"SqList.h"
using namespace std;

//��ʼ��˳���
void InitSqList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList)); // �����ڴ�
	L->length = 0;
}

//�ͷ�˳���
void DestroySqList(SqList* L)
{
	if (L == NULL)
	{
		return;
	}
	free(L);
}

//�ж��Ƿ�Ϊ�ձ�
int isSqListEmpty(SqList* L)
{
	if (L == NULL)
	{
		return 0;
	}
	return (L->length == 0);
}

//����˳����ʵ�ʳ���
int SqListLength(SqList* L)
{
	if (L == NULL)
	{
		cout << "˳�������ڴ�ʧ��" << endl;
		return 0;
	}
	return L->length;
}

//��ȡ˳����е�i��Ԫ��ֵ
DataType SqListGetElem(SqList* L, int i)
{
	if (L == NULL)
	{
		cout << "No Data in SqList" << endl;
		return 0;
	}
	return L->data[i - 1];
}

//��˳����в���Ԫ��e,��������˳����ĸ�λ��
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

//�ڵ�i��λ�ò���Ԫ��
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
	for (int j = L->length; j >= i - 1; j--) //��i֮���Ԫ�غ��ƣ��ڳ��ռ�
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return 1;
}

//ɾ����i��λ��Ԫ��,�����ظ�Ԫ�ص�ֵ
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