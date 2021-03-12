/*
2021_3_10的学习内容：数据结构的总结
*/
#include<iostream>
#include"MyString.h"

int main()
{
	MyString a("gaygh");
	MyString b(a);

	MyString C = b + a;

	std::cout << a <<std::endl;
	std::cout << b << std::endl;
	std::cout << C << std::endl;
}

