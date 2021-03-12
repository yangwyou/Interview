#include<iostream>
#include"LinkList.h"
using namespace std;

void InitLinkList(LinkList*& L)    //��ʼ������
{
	L = (LinkList*)malloc(sizeof(LinkList)); //����ͷ���
	L->next = NULL;
}

void DestroyLinkList(LinkList* L) //���ٵ�����
{
	LinkList* p = L, * q = p->next;//���������ڵ�ָ��

	if (L == NULL)
	{
		return;
	}

	while (q != NULL) //����һ����������һ���ڵ�һ���ڵ������
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}

int isEmptyLinkList(LinkList* L)  //�ж������Ƿ�Ϊ��
{
	return (L->next == NULL);// 1���գ�0���ǿ�
}

int LinkListLength(LinkList* L)  //�������ȣ�����ĳ��ȱ���һ���ڵ�һ���ڵ�ı���
{
	LinkList* p = L;

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

void DisplayLinkList(LinkList* L)//�������Ԫ��
{
	LinkList* p = L->next; //�˴�һ��Ҫָ��next,�����ǵ�һ���ڵ㣬������ͷ���

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

DataType LinkListGetElem(LinkList* L, int i)//��ȡ��i��λ�õ�Ԫ��ֵ
{
	LinkList* p = L;

	if (L == NULL || i < 0)
	{
		return 0;
	}

	int j = 0;
	while (j < i && p->next != NULL)
	{
		j++; p = p->next;
	}

	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return p->data;
	}
}

int LinkListLocate(LinkList* L, DataType e)  //Ԫ��e�������λ��
{
	LinkList* p = L;

	if (L == NULL)
	{
		return 0;
	}

	int j = 0;
	while (p->next != NULL && p->data == e)
	{
		j++;
	}
	return j + 1;
}

int LinkListInsert(LinkList*& L, int i, DataType e)//�ڵ�i������Ԫ��e
{
	LinkList* p = L, * s;
	int j = 0;

	if (L == NULL)
	{
		return 0;
	}

	while (j < i - 1 && p != NULL) //�Ƚ�ָ���Ƶ��ô�
	{
		j++;
		p = p->next;
	}

	s = (LinkList*)malloc(sizeof(LinkList)); //���һ���ڵ㣬�迪��һ���µ��ڴ�
	s->data = e;
	s->next = p->next;   //�Ƚ���һ��ַ���½ڵ�
	p->next = s;    //��ԭ����ָ��ָ���½ڵ�
	return 1;
}

DataType LinkListDelete(LinkList*& L, int i) //ɾ�������i����Ԫ��
{
	LinkList* p = L, * q;  //p�����洢��ʱ�ڵ�
	DataType e;          //�����汻ɾ�����Ԫ��

	int j = 0;
	while (j < i - 1 && p != NULL) //��pָ���i-1�ڵ�
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
		q = p->next; //qָ���i���ڵ�*p
		e = q->data; //
		p->next = q->next;//��������ɾ��p�ڵ㣬����p->next = p->next->next,����i���ڵ���Ϣ��ȡ����
		free(q);  //�ͷ�p���ڴ�
		return e;
	}
}