//==================================================================
// author:pb
// date:2019-06-04
//==================================================================
#include "pch.h"
#include <iostream>
class CData {
public:
	
	CData(const char* data);
	CData(const CData& data);
	CData&  operator =(CData& data);
	char* GetData();
	~CData();
private:
	char* m_data;
};
CData::CData(const char* data = nullptr)
{
	std::cout << "this is construction function" << std::endl;
	if (data == nullptr)
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		m_data = new char[strlen(data) + 1];
		strcpy(m_data, data);
	}
		
}
CData::~CData()
{
	
	delete[] m_data;
}
CData::CData(const CData& data)
{
	std::cout << "this is copy construction function" << std::endl;
	m_data = new char[strlen(data.m_data) + 1];
	strcpy(m_data, data.m_data);
}
CData&  CData::operator =(CData& data)
{
	std::cout << "this is operator overload function" << std::endl;
	if (&data == this)
		return *this;
	delete[] m_data;
	m_data = nullptr;
	m_data = new char[strlen(data.m_data) + 1];
	strcpy(m_data, data.m_data);
	return *this;
}
char* CData::GetData()
{
	return m_data;
}
void test1()
{
	const char* str = "you are a nice man!";
	CData d1(str);
	std::cout << "test1 d1.m_data:" << d1.GetData() << std::endl;
	CData d2 = d1;//调用复制构造函数
	std::cout << "test1 d2.m_data:" << d2.GetData() << std::endl;
	CData d3;
	d3 = d1;//调用运输算符重载函数
	std::cout << "test1 d3.m_data:" << d3.GetData() << std::endl;
	d3 = d3;
}
int main()
{
	test1();
	getchar();
}

