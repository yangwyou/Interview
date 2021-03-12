#include<iostream>
#include"DLinkList.h"
using namespace std;


void DLinkListInit(DLinkList*& L)//��ʼ��˫����
{
	L = (DLinkList*)malloc(sizeof(DLinkList)); //����ͷ���
	L->prior =	L->next = nullptr;
}


void DLinkListDestroy(DLinkList* L) //˫��������
{
	if (L == NULL)
	{
		return;
	}
	DLinkList* p = L, * q = p->next;//���������ڵ㣬��һ����ʾ��ǰ�ڵ㣬�ڶ�����ʾ�ڶ����ڵ�
	while (q != NULL)              //���ڶ����ڵ�ָ��null��˵��p�����һ���ڵ㣬������ǣ���
	{                              //�ͷŵ�p��q��Ϊ��һ���ڵ㣬��q����p��p->��q����������
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}


bool isDLinkListEmpty(DLinkList* L)//�ж������Ƿ�Ϊ��
{
	return L->next == NULL;
}


int  DLinkListLength(DLinkList* L)  //��˫����ĳ���
{
	DLinkList* p = L;

	if (L == NULL)
	{
		return 0;
	}

	int i = 0;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

void DLinkListDisplay(DLinkList* L) //���˫����
{
	DLinkList* p = L->next;  //����ͷ��㣬ָ���һ���ڵ�
	while (p != NULL)
	{
		cout << p->Elem << "  ";
		p = p->next;
	}
}

DataType DLinkListGetElem(DLinkList* L, int i) //��ȡ��i��λ�õ�Ԫ��
{
	DLinkList* p = L;//ָ��ͷ���

	if (L == NULL)
	{
		cout << "Function DLinkListGetElem" << "����Ϊ�ձ�" << endl;
		return 0;
	}

	int j = 0;
	while (p != NULL && j < i) //��ָ��ָ���i��λ�ô�
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return p->Elem;
	}
}

bool DLinkListInsert(DLinkList*& L, int i, DataType e)//�ڵ�i��λ�ò���Ԫ��e
{
	int j = 0;
	DLinkList* p = L, * s;//����s�ڵ��Ǳ�ʾ������Ǹ��ڵ㣬����Ҫ���������ڴ�

	while (p != NULL && j < i - 1)  //����ڵ�ǰ�����ҵ���i-1���ڵ�
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
	{
		return 0;
	}
	else
	{
		s = (DLinkList*)malloc(sizeof(DLinkList));
		s->Elem = e;
		s->next = p->next;//������̵�ָ��
		if (p->next != NULL)
		{
			p->next->prior = s;  //�����ĺ�̵�ǰ��ָ��
		}
		s->prior = p; //�����ǰ����ǰ��ָ��
		p->next = s; //������ǰ���ĺ��ָ��
	}
	return 0;
}

DataType DLinkListDelete(DLinkList*& L, int i)//ɾ����i��λ���ϵ�ֵ����������ֵ
{
	DLinkList* p = L, * s;
	int j = 0;

	if (L == NULL)
	{
		cout << "Function DLinkListDelete" << "ɾ������" << endl;
		return 0;
	}

	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
	{
		return 0;
	}
	else
	{
		s = p->next;
		if (s == NULL)
		{
			return 0;
		}
		DataType e = p->Elem;
		p->next = s->next;
		if (p->next != NULL)
		{
			p->next->prior = p;
		}
		free(s);
		return e;
	}
}