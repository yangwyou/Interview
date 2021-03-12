#include"MyString.h"

//通用构造函数
MyString::MyString(const char* str)
{
	if (!str)
	{
		length = 0;
		data = new char[1];  //一定要用new分配内存，否则就变成了浅拷贝；
		*data = '\0';
	}
	else
	{
		length = strlen(str); //
		data = new char[length + 1];
		strcpy(data, str);
	}
}

//拷贝构造函数
MyString::MyString(const MyString& str)
{
	length = str.size();
	data = new char[length + 1];  //一定要用new,否则变成了浅拷贝
	strcpy(data, str.c_str());
}

//析构函数
MyString::~MyString()
{
	delete[]data;
	length = 0;
}

//重载+
MyString MyString::operator+(const MyString& str) const
{
	MyString MyStringNew;
	MyStringNew.length = length + str.size();

	MyStringNew = new char[length + 1];
	strcpy(MyStringNew.data, data);
	strcat(MyStringNew.data, str.data);  //字符串拼接函数，即将str内容复制到MyStringNew内容后面
	return MyStringNew;
}

//重载=
MyString& MyString::operator=(const MyString& str)
{
	if (this == &str)
	{
		return *this;
	}

	delete[]data;                 //释放内存
	this->length = str.length;
	this->data = new char[length + 1];
	strcpy(data, str.c_str());
	return *this;
}

//重载+=
MyString& MyString::operator+=(const MyString& str)
{
	length += str.size();
	char* dataNew = new char[length + 1];
	strcpy(dataNew, data);
	delete[]data;
	strcat(dataNew, str.c_str());
	data = dataNew;
	return *this;
}

//重载==
bool MyString::operator==(const MyString& str) const
{
	if (length != str.length)
	{
		return false;
	}
	return strcmp(data, str.data) ? false : true;
}

//重载[]
char& MyString::operator[](int n) const           //str[n]表示第n+1个元素   
{
	if (n >= length)
	{
		return data[length - 1]; //错误处理
	}
	else
	{
		return data[n];
	}
}

//获取长度
size_t MyString::size() const
{
	return this->length;
}

//获取C字符串
const char* MyString::c_str() const
{
	return data;
}

//重载>>

std::istream& operator>>(std::istream& is, MyString& str)
{
	char tem[1000];
	is >> tem;
	str.length = strlen(tem);
	str.data = new char[str.length + 1];
	strcpy(str.data, tem);
	return is;
}

//重载<<
std::ostream& operator<<(std::ostream& os, MyString& str)
{
	os << str.c_str();
	return os;
}