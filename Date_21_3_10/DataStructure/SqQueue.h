#pragma once
#ifndef SQQUEUE_H
#define SQQUEUE_H

#define MaxSize 50
typedef int DataType;

typedef struct SQueue //创建一个结构体，里面包含数组和队头和队尾
{
	DataType data[MaxSize];
	int front, rear; //front表示队头，rear表示队尾，入队头不动尾动，出队尾不动头动
}SqQueue;

void SqQueueInit(SqQueue*& Q);              //队列初始化
void SqQueueClear(SqQueue* $Q);             //清空队列
bool isSqQueueEmpty(SqQueue* Q);            //判断队列长度
int  SqQueueLength(SqQueue* Q);             //求队列的长度
void SqQueueDisplay(SqQueue* Q);            //输出队列
void EnSqQueue(SqQueue*& Q, DataType e);    //进队
DataType DeSqQueue(SqQueue*& Q);           //出队

#endif