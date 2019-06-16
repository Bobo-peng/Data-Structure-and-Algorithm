// 048_longestSubNoDuplication.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-016
//==================================================================

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
int longestSubstringWithoutDuplication(const std::string& str)
{
	int curLength = 0;
	int maxLength = 0;
	std::vector<int> position(26,-1);
	for (int i = 0; i < str.length(); ++i)
	{
		int prevIndex = position[str[i] - 'a'];
		if (prevIndex < 0 || i - prevIndex > curLength)
			++curLength;
		else
		{
			if (curLength > maxLength)
				maxLength = curLength;

			curLength = i - prevIndex;
		}
		position[str[i] - 'a'] = i;
	}

	if (curLength > maxLength)
		maxLength = curLength;
	return maxLength;
}
void Test()
{
	std::string str = "arabcacfr";
	int ret = longestSubstringWithoutDuplication(str);
}
int main()
{
	Test();
}

