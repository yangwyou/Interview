#include"m1.h"

ListNode* Solution1::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* head=nullptr, *tail=nullptr;
	int flag =0;  //进位标识符

	while (l1 || l2)
	{
		int n1 = l1 ? l1->val : 0;   //如果超过了链表长度，就设置值为0
		int n2 = l2 ? l2->val : 0;

		int sum = n1 + n2 + flag;

		if (!head)       //一开始 头节点非空， 所以第一个值放进去
		{
			head = tail = new ListNode(sum % 10);
		}                    //第二轮及以后的操作
		else
		{
			//  head  -> tail -> (tail->next)   ->  ( tail->next->next)   ...  依次类推
			//数据放到tail->next后面； 然后 再把tail->next的位置赋值给tail， 这样就可以根据tail的移动来更新数据
			tail->next = new ListNode(sum % 10);
			tail = tail->next;
		}
		flag = (sum >= 10);   //更新标志位  

		//接下来依次把两个链表的位置移到下一位
		if (l1)   
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}

	//最后 还需要判断最后一位是否有进位，如果有， 还需要新建一个节点，放在 tail->next后面
	if (flag > 0)
	{
		tail->next = new ListNode(flag);
	}
	return head;
}
