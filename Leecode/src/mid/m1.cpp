#include"m1.h"

ListNode* Solution1::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* head=nullptr, *tail=nullptr;
	int flag =0;  //��λ��ʶ��

	while (l1 || l2)
	{
		int n1 = l1 ? l1->val : 0;   //��������������ȣ�������ֵΪ0
		int n2 = l2 ? l2->val : 0;

		int sum = n1 + n2 + flag;

		if (!head)       //һ��ʼ ͷ�ڵ�ǿգ� ���Ե�һ��ֵ�Ž�ȥ
		{
			head = tail = new ListNode(sum % 10);
		}                    //�ڶ��ּ��Ժ�Ĳ���
		else
		{
			//  head  -> tail -> (tail->next)   ->  ( tail->next->next)   ...  ��������
			//���ݷŵ�tail->next���棻 Ȼ�� �ٰ�tail->next��λ�ø�ֵ��tail�� �����Ϳ��Ը���tail���ƶ�����������
			tail->next = new ListNode(sum % 10);
			tail = tail->next;
		}
		flag = (sum >= 10);   //���±�־λ  

		//���������ΰ����������λ���Ƶ���һλ
		if (l1)   
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}

	//��� ����Ҫ�ж����һλ�Ƿ��н�λ������У� ����Ҫ�½�һ���ڵ㣬���� tail->next����
	if (flag > 0)
	{
		tail->next = new ListNode(flag);
	}
	return head;
}
