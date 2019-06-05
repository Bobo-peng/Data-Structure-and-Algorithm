//==================================================================
// author:pb
// date:2019-06-05
//==================================================================
//#include "stdafx.h"
#include"pch.h"
class CSingleton {
public:
	int m_data;
public:
	static CSingleton* Instance()
	{
		return _instance;
	}
private:
	CSingleton() {};//必须有函数体
	static CSingleton* _instance;
};
CSingleton* CSingleton::_instance = new CSingleton();
int main()
{
	CSingleton *sg = CSingleton::Instance();
	sg->m_data = 10;

	return 0;
}

