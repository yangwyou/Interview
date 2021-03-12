#pragma once
#include<iostream>
#include<string.h>
class MyString
{
private:
	char* data; 
	size_t length;

public:
	MyString(const char* str=nullptr);  //通用构造函数
	MyString(const MyString& str);      //拷贝构造函数， 涉及到浅拷贝与深拷贝问题  malloc 分配内存问题
	~MyString();

	//操作符重载  + =  +=  ==   “输出”<<定义为友元类， (由ostream负责， cout<<)
	MyString operator+(const MyString& str) const;
	MyString &operator=(const MyString& str); 
	MyString &operator+=(const MyString& str);

	bool operator==(const MyString& str) const;

	friend std::istream& operator>>(std::istream & is, MyString & str);
	friend std::ostream& operator<<(std::ostream& os, MyString & str);

	char& operator[](int n) const; //查询某个值

	size_t size() const;
	const char* c_str() const;
};

