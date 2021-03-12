#pragma once
#ifndef SQQUEUE_H
#define SQQUEUE_H

#define MaxSize 50
typedef int DataType;

typedef struct SQueue //����һ���ṹ�壬�����������Ͷ�ͷ�Ͷ�β
{
	DataType data[MaxSize];
	int front, rear; //front��ʾ��ͷ��rear��ʾ��β�����ͷ����β��������β����ͷ��
}SqQueue;

void SqQueueInit(SqQueue*& Q);              //���г�ʼ��
void SqQueueClear(SqQueue* $Q);             //��ն���
bool isSqQueueEmpty(SqQueue* Q);            //�ж϶��г���
int  SqQueueLength(SqQueue* Q);             //����еĳ���
void SqQueueDisplay(SqQueue* Q);            //�������
void EnSqQueue(SqQueue*& Q, DataType e);    //����
DataType DeSqQueue(SqQueue*& Q);           //����

#endif