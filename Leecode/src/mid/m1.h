#pragma once
#include<list>
#include<vector>
#include<iostream>
/*
Leecode第二题： 两个链表相加，表示非负整数，逆序存储
eg: 2->4->3;    5->6->4;

相加： 7-》0-》8   因为：465+342=807
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