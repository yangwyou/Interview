#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

typedef int DataType;


//��������������һ���ڵ�һ���ڵ㹹�ɣ�
//�ȶ���һ���ڵ㣬�ڵ�Ϊһ���ṹ�壬����Щ�ڵ�����һ��
// ����Ϊָ��ͷ���Ľṹ����ָ�룬����LinkList��ָ��

typedef struct LNode  //������ǽڵ������
{
	DataType data;
	struct LNode* next; //ָ���̽ڵ�
}LinkList;


void InitLinkList(LinkList*& L);    //��ʼ������
void DestroyLinkList(LinkList* L); //���ٵ�����
int isEmptyLinkList(LinkList* L);  //�ж������Ƿ�Ϊ��
int LinkListLength(LinkList* L);   //��������
void DisplayLinkList(LinkList* L); //�������Ԫ��
DataType LinkListGetElem(LinkList* L, int i);//��ȡ��i��λ�õ�Ԫ��ֵ
int LinkListLocate(LinkList* L, DataType e);  //Ԫ��e�������λ��
int LinkListInsert(LinkList*& L, int i, DataType e);//�ڵ�i������Ԫ��e
DataType LinkListDelete(LinkList*& L, int i); //ɾ�������i����Ԫ��
#endif