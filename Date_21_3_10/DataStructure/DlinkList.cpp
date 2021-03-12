#include<iostream>
#include"DLinkList.h"
using namespace std;


void DLinkListInit(DLinkList*& L)//初始化双链表
{
	L = (DLinkList*)malloc(sizeof(DLinkList)); //创建头结点
	L->prior =	L->next = nullptr;
}


void DLinkListDestroy(DLinkList* L) //双链表销毁
{
	if (L == NULL)
	{
		return;
	}
	DLinkList* p = L, * q = p->next;//定义两个节点，第一个表示当前节点，第二个表示第二个节点
	while (q != NULL)              //当第二个节点指向null，说明p是最后一个节点，如果不是，则
	{                              //释放掉p，q就为第一个节点，将q赋给p，p->给q，这样迭代
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}


bool isDLinkListEmpty(DLinkList* L)//判断链表是否为空
{
	return L->next == NULL;
}


int  DLinkListLength(DLinkList* L)  //求双链表的长度
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

void DLinkListDisplay(DLinkList* L) //输出双链表
{
	DLinkList* p = L->next;  //跳过头结点，指向第一个节点
	while (p != NULL)
	{
		cout << p->Elem << "  ";
		p = p->next;
	}
}

DataType DLinkListGetElem(DLinkList* L, int i) //获取第i个位置的元素
{
	DLinkList* p = L;//指向头结点

	if (L == NULL)
	{
		cout << "Function DLinkListGetElem" << "链表为空表" << endl;
		return 0;
	}

	int j = 0;
	while (p != NULL && j < i) //将指针指向第i个位置处
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

bool DLinkListInsert(DLinkList*& L, int i, DataType e)//在第i个位置插入元素e
{
	int j = 0;
	DLinkList* p = L, * s;//其中s节点是表示插入的那个节点，所以要给它开辟内存

	while (p != NULL && j < i - 1)  //插入节点前，先找到第i-1个节点
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
		s->next = p->next;//插入点后继的指向
		if (p->next != NULL)
		{
			p->next->prior = s;  //插入点的后继的前驱指向
		}
		s->prior = p; //插入点前驱的前驱指向
		p->next = s; //插入点后前驱的后继指向
	}
	return 0;
}

DataType DLinkListDelete(DLinkList*& L, int i)//删除第i个位置上的值，并返回其值
{
	DLinkList* p = L, * s;
	int j = 0;

	if (L == NULL)
	{
		cout << "Function DLinkListDelete" << "删除出错" << endl;
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