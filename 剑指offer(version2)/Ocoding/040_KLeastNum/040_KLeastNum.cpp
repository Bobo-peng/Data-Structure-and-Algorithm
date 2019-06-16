// 040_KLeastNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-016
//==================================================================

#include "pch.h"
#include <iostream>
#include<vector>
int partion(std::vector<int>& arr,int start, int end)
{
	if (end - start < 1) return start;
	int temp = arr[start];
	int j = start;
	for (int i = start + 1; i <= end; ++i)
	{
		if (arr[i] < temp)
		{
			j++;
			std::swap(arr[i],arr[j]);
		}
	}
	std::swap(arr[j],arr[start]);
	return j;
}
std::vector<int> KLeastNumber(std::vector<int>& arr,int k)
{
	std::vector<int> res;
	if (arr.size() < 1) return res;
	int start = 0;
	int end = arr.size() - 1;
	int p = partion(arr, start, end);
	while (p != k - 1)
	{
		if (p > k - 1)
		{
			end = p - 1;
			p = partion(arr, start, end);
		}
		else
		{
			start = p + 1;
			p = partion(arr, start, end);
		}
	}
	for (int i = 0; i < k; ++i)
	{
		res.push_back(arr[i]);
	}
	return res;
}
void Test()
{
	std::vector<int> arr{ 4,5,1,6,2,7,3,8 };
	std::vector<int> ret = KLeastNumber(arr, 4);
}
int main()
{
	Test();
}

