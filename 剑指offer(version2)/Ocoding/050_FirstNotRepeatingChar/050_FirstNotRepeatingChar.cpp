// 050_FirstNotRepeatingChar.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-016
//==================================================================

#include "pch.h"
#include <iostream>

#include<string>
#include<vector>
char FirstNotRepeatingChar(const std::string& str)
{
	std::vector<int> hashtable(256, 0);
	for (int i = 0; i < str.length(); ++i)
	{
		hashtable[str[i]]++;
	}
	for (int i = 0; i < str.length(); ++i)
	{
		if (hashtable[str[i]] == 1)
			return str[i];
	}
	return '\0';
}
void Test()
{
	std::string str = "abaccdeff";
	char ret = FirstNotRepeatingChar(str);
}
int main()
{
	Test();
}


