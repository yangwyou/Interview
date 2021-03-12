/*
B站 侯捷 STL源码解析 第一讲
*/

#if 0

使用BST需要先进行排序， 即使用Binarty TREE search之前需要先排序


1:  vector是可扩展的，  按2的倍数进行扩展， 也可以自己指定扩展的大小， 另外扩展是另外开辟一块内存，将原来的内容拿过去

2： list,  链表；  forward_list: 单向链表

3： queue:队列， 先进先出   deque： 双向进出队列   。  链表和队列进行查找都比较慢

4： stack : 栈            队列和栈都没有iterator， 因为如果有的话，就可以改变某个位置的值，这违反了他们的特性（先进先出，先进后出）

5，multiset:  它是一棵树，  multiset允许有重复数据进行存储。，基于红黑树做支撑

6. unordered_multiset/ unordered_map


7. set/map：基于红黑树, 都不允许重复数据的进入






#endif // 0

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

#include<string>
#include<array>
#include<list>
#include<queue>
#include<deque>
#include<forward_list>
#include<unordered_map>
#include<unordered_set>

#include<map>


using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;
using std::array;
using std::deque;
using std::queue;
using std::forward_list;
using std::unordered_map;
using std::unordered_multimap;
using std::unordered_set;
using std::unordered_multiset;
using std::map;

long get_a_target_long()
{
	long target = 0;
	cout << "target (0~" << RAND_MAX << "):";
	cin >> target;
	return target;
}

string get_a_target_string()
{
	long target = 0;
	char buf[10];
	cout << "target (0~" << RAND_MAX << "):";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	
	return string(buf);
}


int main()
{
	
	
	//下面的这段代码主要是为了对Stl的几个基本部件有一定认识

	int a[6] = {12,12,232,25,54,68};

	
	// vector： 容器   
	// allocator: 分配器，用来处理内存分配问题
	vector<int, std::allocator<int>> vi(a, a + 6);

	deque<int> b;
	
	//      algorithm     iterator
	cout << count_if(vi.begin(),vi.end(), std::not1(std::bind2nd( std::less<int>(),40)))<<endl;
	//                                    functional adaptor
	
	for (vector<int>::iterator it=vi.begin(); it != vi.end(); it++)
	{
		cout <<  *it <<" ";
	}
	
	
	return 0;
}