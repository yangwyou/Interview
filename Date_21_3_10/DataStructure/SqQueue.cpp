#include<iostream>
#include"SqQueue.h"
using namespace std;

void SqQueueInit(SqQueue*& Q)   //���г�ʼ��
{
	Q = (SqQueue*)malloc(sizeof(Q));
	if (Q)
	{
		Q->front = Q->rear = 0;
	}
}

void SqQueueClear(SqQueue*& Q)  //��ն���
{
	free(Q); //����˳��ջ��ֱ���ͷ��ڴ漴��
}

bool isSqQueueEmpty(SqQueue* Q) //�ж϶��г���
{
	return (Q->front == Q->rear);
}

int  SqQueueLength(SqQueue* Q)  //����еĳ���
{
	return Q->rear - Q->front;  //�˴�������
}

void EnSqQueue(SqQueue*& Q, DataType e)    //����
{
	if (Q == NULL)
	{
		cout << "�����ڴ�ʧ�ܣ�" << endl;
		return;
	}

	if (Q->rear >= MaxSize)  //���ǰ���ж����ж�
	{
		cout << "The Queue is Full!" << endl;
		return;
	}

	Q->rear++;
	Q->data[Q->rear] = e;
}

DataType DeSqQueue(SqQueue*& Q)     //��ջ
{
	if (Q == NULL)
	{
		return 0;
	}

	if (Q->front == Q->rear) //����ǰ���пն��ж�
	{
		cout << "This is an Empty Queue!" << endl;
		return 0;
	}

	Q->front--;
	return Q->data[Q->front];
}

void SqQueueDisplay(SqQueue* Q)           //�������
{
	if (Q == NULL)
	{
		return;
	}

	if (Q->front == Q->rear)
	{
		return;
	}
	int i = Q->front + 1;
	while (i <= Q->rear)
	{
		cout << Q->data[i] << "  ";
		i++;
	}
}