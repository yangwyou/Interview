#include "Graph.h"

MGraph::MGraph(int m_Size, const int& noedg)
{

	n = m_Size;
	e = 0;
	noEdge = noedg;

	a = new int* [n];  //n是顶点数， 每个顶点使用指针来保存和它相邻的情况

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n]; //再给每一个顶点开辟一个空间，用来存储该顶点的情况
		for (int j = 0; j < n; j++)
			a[i][j] = noEdge;

		a[i][i] = 0;
	}
}

MGraph::~MGraph()
{
	//使用了两次开辟空间，所以需要先释放底层，在释放上一层的空间
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}

	delete[]a;
}


ResultCode MGraph::Insert(int u, int v, int w)
{
	//不允许自己和自己相连， 也不能超过或低于顶点的数目
	if (u < 0 || v<0 || u>n - 1 || v > n - 1 || u == v)
		return Failure;

	//边已经存在
	if (a[u][v] != noEdge)
	{
		return Duplicate;
	}
	//如果边不存在，就可以添加了
	a[u][v] = w;
	e++;   //边的数目加1
	return Success;

}

ResultCode MGraph::Remove(int u, int v)
{
	//不允许自己和自己相连， 也不能超过或低于顶点的数目
	if (u < 0 || v<0 || u>n - 1 || v > n - 1 || u == v)
		return Failure;

	//边已经存在
	if (a[u][v] == noEdge)
	{
		return Notpresent;
	}

	//如果边存在，就可以remove了
	a[u][v] = noEdge;
	e--;   //边的数减一
	return Success;
}


bool MGraph::Exist(int u, int v) const
{
	if (u < 0 || v<0 || u>n - 1 || v >n - 1 || u == v || a[u][v] == noEdge)
		return false;
	else
		return true;
}

