#include<iostream>
#include<vector>
#include"easy/e1.h"

int main()
{
	#if 0
	/*
	��һ��Ľ���˼·�ؼ�����hashTable��ʹ���븳ֵ

	a.Insert(unordef_map<int,int>::value_type(a,b) );

	count ��������ĳ�������ĸ���
	a.count(fashfl);
	
	
	*/
	std::vector<int> A = { 1,2,3,4,5,6 };
	std::vector<int> Result;
	Result=Solution1::twoSum(A, 4);
	for (auto it = Result.begin(); it != Result.end(); it++)
	{
		std::cout << *it;

	}
	#endif


	return 0;
}