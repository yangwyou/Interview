#include<iostream>
#include"SqQueue.h"
using namespace std;

void SqQueueInit(SqQueue*& Q)   //队列初始化
{
	Q = (SqQueue*)malloc(sizeof(Q));
	if (Q)
	{
		Q->front = Q->rear = 0;
	}
}

void SqQueueClear(SqQueue*& Q)  //清空队列
{
	free(Q); //对于顺序栈，直接释放内存即可
}

bool isSqQueueEmpty(SqQueue* Q) //判断队列长度
{
	return (Q->front == Q->rear);
}

int  SqQueueLength(SqQueue* Q)  //求队列的长度
{
	return Q->rear - Q->front;  //此处有问题
}

void EnSqQueue(SqQueue*& Q, DataType e)    //进队
{
	if (Q == NULL)
	{
		cout << "分配内存失败！" << endl;
		return;
	}

	if (Q->rear >= MaxSize)  //入队前进行队满判断
	{
		cout << "The Queue is Full!" << endl;
		return;
	}

	Q->rear++;
	Q->data[Q->rear] = e;
}

DataType DeSqQueue(SqQueue*& Q)     //出栈
{
	if (Q == NULL)
	{
		return 0;
	}

	if (Q->front == Q->rear) //出队前进行空队判断
	{
		cout << "This is an Empty Queue!" << endl;
		return 0;
	}

	Q->front--;
	return Q->data[Q->front];
}

void SqQueueDisplay(SqQueue* Q)           //输出队列
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