/*
Bվ ��� STLԴ����� ��һ��
*/

#if 0

ʹ��BST��Ҫ�Ƚ������� ��ʹ��Binarty TREE search֮ǰ��Ҫ������


1:  vector�ǿ���չ�ģ�  ��2�ı���������չ�� Ҳ�����Լ�ָ����չ�Ĵ�С�� ������չ�����⿪��һ���ڴ棬��ԭ���������ù�ȥ

2�� list,  ����  forward_list: ��������

3�� queue:���У� �Ƚ��ȳ�   deque�� ˫���������   ��  ����Ͷ��н��в��Ҷ��Ƚ���

4�� stack : ջ            ���к�ջ��û��iterator�� ��Ϊ����еĻ����Ϳ��Ըı�ĳ��λ�õ�ֵ����Υ�������ǵ����ԣ��Ƚ��ȳ����Ƚ������

5��multiset:  ����һ������  multiset�������ظ����ݽ��д洢�������ں������֧��

6. unordered_multiset/ unordered_map


7. set/map�����ں����, ���������ظ����ݵĽ���






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
	
	
	//�������δ�����Ҫ��Ϊ�˶�Stl�ļ�������������һ����ʶ

	int a[6] = {12,12,232,25,54,68};

	
	// vector�� ����   
	// allocator: �����������������ڴ��������
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