#pragma once

enum ResultCode
{
	Success,
	Duplicate,
	Failure,
	Notpresent,
};


class Graph
{
public:
	virtual ResultCode Insert(int u, int v, int w) = 0;   //在两个顶点中插入边， W为边的权重
	virtual ResultCode Remove(int u, int v) = 0;        //去掉两个顶点之间的边
	virtual bool Exist( int u, int v) const = 0;         //判断两个顶点之间是否存在连接
	virtual int Vertices()const { return n; }

protected:
	int n, e;  //n顶点数，  e:边的数目

 };


class MGraph : public Graph
{
public:
	MGraph(int m_Size, const int& noedge);
	~MGraph();  //涉及到**a的地址释放问题
	ResultCode Insert(int u,int v, int w) override;
	ResultCode Remove(int u, int v) override;        //去掉两个顶点之间的边
	bool Exist(int u, int v) const override ;         //判断两个顶点之间是否存在连接

protected:  
	int** a;  //保存边的权重矩阵，  这里使用邻接矩阵
	int noEdge;  //如果《u,v》存在边， noedge =1，  否则 noedge =0 （无向图） 或者 Inf（无限大， 有权重图/网）
};

