// 042_GreatesSumOfArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-016
//==================================================================

#include "pch.h"
#include <iostream>
#include<vector>
//#include<math.h>
#include<algorithm>
int GreatesSumOfArrary(std::vector<int>& arr)
{
	int res = INT_MIN, sum = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		sum = std::max(arr[i] + sum, arr[i]);
		res = std::max(res, sum);
	}
	return res;
}
void Test()
{
	std::vector<int> arr{ 1,-2,3,10,-4,7,2,-5 };
	int ret = GreatesSumOfArrary(arr);
}
int main()
{
	Test();
}


