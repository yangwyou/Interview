#pragma once
#include<list>
#include<vector>
#include<iostream>
/*
Leecode�ڶ��⣺ ����������ӣ���ʾ�Ǹ�����������洢
eg: 2->4->3;    5->6->4;

��ӣ� 7-��0-��8   ��Ϊ��465+342=807
*/


using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* Next) :val(x), next(Next){}
};
class Solution1
{
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};