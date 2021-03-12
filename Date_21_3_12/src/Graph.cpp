#include "Graph.h"

MGraph::MGraph(int m_Size, const int& noedg)
{

	n = m_Size;
	e = 0;
	noEdge = noedg;

	a = new int* [n];  //n�Ƕ������� ÿ������ʹ��ָ��������������ڵ����

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n]; //�ٸ�ÿһ�����㿪��һ���ռ䣬�����洢�ö�������
		for (int j = 0; j < n; j++)
			a[i][j] = noEdge;

		a[i][i] = 0;
	}
}

MGraph::~MGraph()
{
	//ʹ�������ο��ٿռ䣬������Ҫ���ͷŵײ㣬���ͷ���һ��Ŀռ�
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}

	delete[]a;
}


ResultCode MGraph::Insert(int u, int v, int w)
{
	//�������Լ����Լ������� Ҳ���ܳ�������ڶ������Ŀ
	if (u < 0 || v<0 || u>n - 1 || v > n - 1 || u == v)
		return Failure;

	//���Ѿ�����
	if (a[u][v] != noEdge)
	{
		return Duplicate;
	}
	//����߲����ڣ��Ϳ��������
	a[u][v] = w;
	e++;   //�ߵ���Ŀ��1
	return Success;

}

ResultCode MGraph::Remove(int u, int v)
{
	//�������Լ����Լ������� Ҳ���ܳ�������ڶ������Ŀ
	if (u < 0 || v<0 || u>n - 1 || v > n - 1 || u == v)
		return Failure;

	//���Ѿ�����
	if (a[u][v] == noEdge)
	{
		return Notpresent;
	}

	//����ߴ��ڣ��Ϳ���remove��
	a[u][v] = noEdge;
	e--;   //�ߵ�����һ
	return Success;
}


bool MGraph::Exist(int u, int v) const
{
	if (u < 0 || v<0 || u>n - 1 || v >n - 1 || u == v || a[u][v] == noEdge)
		return false;
	else
		return true;
}

