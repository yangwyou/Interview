  //hashTable��ͷ�ļ��� ԭ����hsh_map
#include"e1.h"

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

vector<int> Solution1::twoSum(vector<int>& nums, int target)
{
	vector<int> Res(2, -1);

	//���Ȱ���������� �ŵ�hash������ȥ
	unordered_map<int,int>Input;	
	for (size_t i = 0; i < nums.size(); i++)
	{
		Input.insert(unordered_map<int,int>::value_type(nums[i],i));
	}
	//�����ֵ��Ϊkey,  ��������Ϊ������Ҫ��value

	//������ʹ��hashTable�������ݵıȽ�
	for (size_t i = 0; i < nums.size(); i++)
	{	//��һ���жϣ����ж� hash�������Ƿ����������Ҫ��ֵ
		//�ڶ����жϣ� ���ֵ�������Լ�����Ŀ����˵�˲������ظ���ֵ
		if (Input.count( target - nums[i]) >0
		&& (Input[target-nums[i]] !=i))
		{
			Res[0] = i;
			Res[1] = Input[target - nums[i]];
		}
	}

	return Res;
}

