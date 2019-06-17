// 058_ReverseWords.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<algorithm>
void _ReverseStr(std::string&str, int start, int end)
{
	for (int i = start; i < (end - start+1)/2+ start; ++i)
	{
		std::swap(str[i],str[end - (i- start)]);
	}
}
std::string ReverseWords(std::string& str)
{
	int len = str.length();
	_ReverseStr(str, 0, len-1);
	int wordStart= 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[wordStart] == ' ')
		{
			wordStart++;
		}
		else if (str[i] == ' ' || i == len - 1)
		{
			if (i == len - 1)
			{
				_ReverseStr(str, wordStart, i);
			}
			else
			{
				_ReverseStr(str, wordStart, i - 1);
				wordStart = i;
			}	
		}
	}
	return str;
}
void Test()
{
	std::string str= "you are a student.  ";
	ReverseWords(str);
}
int main()
{
    Test(); 
}
