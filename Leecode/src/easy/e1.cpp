  //hashTable的头文件， 原来叫hsh_map
#include"e1.h"

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

vector<int> Solution1::twoSum(vector<int>& nums, int target)
{
	vector<int> Res(2, -1);

	//首先把输入的数组 放到hash表里面去
	unordered_map<int,int>Input;	
	for (size_t i = 0; i < nums.size(); i++)
	{
		Input.insert(unordered_map<int,int>::value_type(nums[i],i));
	}
	//这里把值作为key,  把索引作为我们需要的value

	//接下来使用hashTable进行数据的比较
	for (size_t i = 0; i < nums.size(); i++)
	{	//第一个判断：先判断 hash表里面是否存在我们需要的值
		//第二个判断： 这个值不能是自己，题目里面说了不会有重复的值
		if (Input.count( target - nums[i]) >0
		&& (Input[target-nums[i]] !=i))
		{
			Res[0] = i;
			Res[1] = Input[target - nums[i]];
		}
	}

	return Res;
}

