#include<iostream>
#include"LinkList.h"
using namespace std;

void InitLinkList(LinkList*& L)    //初始化链表
{
	L = (LinkList*)malloc(sizeof(LinkList)); //创建头结点
	L->next = NULL;
}

void DestroyLinkList(LinkList* L) //销毁单链表
{
	LinkList* p = L, * q = p->next;//创建辅助节点指针

	if (L == NULL)
	{
		return;
	}

	while (q != NULL) //销毁一个链表，必须一个节点一个节点的销毁
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}

int isEmptyLinkList(LinkList* L)  //判断链表是否为空
{
	return (L->next == NULL);// 1：空；0：非空
}

int LinkListLength(LinkList* L)  //求链表长度，链表的长度必须一个节点一个节点的遍历
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

void DisplayLinkList(LinkList* L)//输出链表元素
{
	LinkList* p = L->next; //此处一点要指向next,这样是第一个节点，跳过了头结点

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

DataType LinkListGetElem(LinkList* L, int i)//获取第i个位置的元素值
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

int LinkListLocate(LinkList* L, DataType e)  //元素e在链表的位置
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

int LinkListInsert(LinkList*& L, int i, DataType e)//在第i处插入元素e
{
	LinkList* p = L, * s;
	int j = 0;

	if (L == NULL)
	{
		return 0;
	}

	while (j < i - 1 && p != NULL) //先将指针移到该处
	{
		j++;
		p = p->next;
	}

	s = (LinkList*)malloc(sizeof(LinkList)); //添加一个节点，需开辟一个新的内存
	s->data = e;
	s->next = p->next;   //先将下一地址给新节点
	p->next = s;    //将原来的指针指向新节点
	return 1;
}

DataType LinkListDelete(LinkList*& L, int i) //删除链表第i处的元素
{
	LinkList* p = L, * q;  //p用来存储临时节点
	DataType e;          //用来存被删除点的元素

	int j = 0;
	while (j < i - 1 && p != NULL) //将p指向第i-1节点
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
		q = p->next; //q指向第i个节点*p
		e = q->data; //
		p->next = q->next;//从链表中删除p节点，即是p->next = p->next->next,将第i个节点信息提取出来
		free(q);  //释放p点内存
		return e;
	}
}