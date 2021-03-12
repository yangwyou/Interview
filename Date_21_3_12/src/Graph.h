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
	virtual ResultCode Insert(int u, int v, int w) = 0;   //�����������в���ߣ� WΪ�ߵ�Ȩ��
	virtual ResultCode Remove(int u, int v) = 0;        //ȥ����������֮��ı�
	virtual bool Exist( int u, int v) const = 0;         //�ж���������֮���Ƿ��������
	virtual int Vertices()const { return n; }

protected:
	int n, e;  //n��������  e:�ߵ���Ŀ

 };


class MGraph : public Graph
{
public:
	MGraph(int m_Size, const int& noedge);
	~MGraph();  //�漰��**a�ĵ�ַ�ͷ�����
	ResultCode Insert(int u,int v, int w) override;
	ResultCode Remove(int u, int v) override;        //ȥ����������֮��ı�
	bool Exist(int u, int v) const override ;         //�ж���������֮���Ƿ��������

protected:  
	int** a;  //����ߵ�Ȩ�ؾ���  ����ʹ���ڽӾ���
	int noEdge;  //�����u,v�����ڱߣ� noedge =1��  ���� noedge =0 ������ͼ�� ���� Inf�����޴� ��Ȩ��ͼ/����
};

