/*
2021_3_10��ѧϰ���ݣ����ݽṹ���ܽ�
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

