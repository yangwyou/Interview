#include"MyString.h"

//ͨ�ù��캯��
MyString::MyString(const char* str)
{
	if (!str)
	{
		length = 0;
		data = new char[1];  //һ��Ҫ��new�����ڴ棬����ͱ����ǳ������
		*data = '\0';
	}
	else
	{
		length = strlen(str); //
		data = new char[length + 1];
		strcpy(data, str);
	}
}

//�������캯��
MyString::MyString(const MyString& str)
{
	length = str.size();
	data = new char[length + 1];  //һ��Ҫ��new,��������ǳ����
	strcpy(data, str.c_str());
}

//��������
MyString::~MyString()
{
	delete[]data;
	length = 0;
}

//����+
MyString MyString::operator+(const MyString& str) const
{
	MyString MyStringNew;
	MyStringNew.length = length + str.size();

	MyStringNew = new char[length + 1];
	strcpy(MyStringNew.data, data);
	strcat(MyStringNew.data, str.data);  //�ַ���ƴ�Ӻ���������str���ݸ��Ƶ�MyStringNew���ݺ���
	return MyStringNew;
}

//����=
MyString& MyString::operator=(const MyString& str)
{
	if (this == &str)
	{
		return *this;
	}

	delete[]data;                 //�ͷ��ڴ�
	this->length = str.length;
	this->data = new char[length + 1];
	strcpy(data, str.c_str());
	return *this;
}

//����+=
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

//����==
bool MyString::operator==(const MyString& str) const
{
	if (length != str.length)
	{
		return false;
	}
	return strcmp(data, str.data) ? false : true;
}

//����[]
char& MyString::operator[](int n) const           //str[n]��ʾ��n+1��Ԫ��   
{
	if (n >= length)
	{
		return data[length - 1]; //������
	}
	else
	{
		return data[n];
	}
}

//��ȡ����
size_t MyString::size() const
{
	return this->length;
}

//��ȡC�ַ���
const char* MyString::c_str() const
{
	return data;
}

//����>>

std::istream& operator>>(std::istream& is, MyString& str)
{
	char tem[1000];
	is >> tem;
	str.length = strlen(tem);
	str.data = new char[str.length + 1];
	strcpy(str.data, tem);
	return is;
}

//����<<
std::ostream& operator<<(std::ostream& os, MyString& str)
{
	os << str.c_str();
	return os;
}