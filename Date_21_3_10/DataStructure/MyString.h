#pragma once
#include<iostream>
#include<string.h>
class MyString
{
private:
	char* data; 
	size_t length;

public:
	MyString(const char* str=nullptr);  //ͨ�ù��캯��
	MyString(const MyString& str);      //�������캯���� �漰��ǳ�������������  malloc �����ڴ�����
	~MyString();

	//����������  + =  +=  ==   �������<<����Ϊ��Ԫ�࣬ (��ostream���� cout<<)
	MyString operator+(const MyString& str) const;
	MyString &operator=(const MyString& str); 
	MyString &operator+=(const MyString& str);

	bool operator==(const MyString& str) const;

	friend std::istream& operator>>(std::istream & is, MyString & str);
	friend std::ostream& operator<<(std::ostream& os, MyString & str);

	char& operator[](int n) const; //��ѯĳ��ֵ

	size_t size() const;
	const char* c_str() const;
};

