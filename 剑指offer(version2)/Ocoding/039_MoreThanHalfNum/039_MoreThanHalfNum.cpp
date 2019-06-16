// 039_MoreThanHalfNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-016
//==================================================================
#include "pch.h"
#include <iostream>
#include<vector>
int partion(std::vector<int> &arr,int start, int end)
{
	if (end - start) return start;
	int temp = arr[start];
	int j = start;
	for (int i = start+1; i <= end; ++i)
	{
		if (arr[i] > temp)
		{
			++j;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[start], arr[j]);
	return j;
}
int MoreThanHalfNumber(std::vector<int> &arr)
{
	if (arr.size() < 1) return 0;
	int start = 0;
	int end = arr.size()-1;
	int mid = end >> 1;
	int p = partion(arr,start,end);
	while (p != mid)
	{
		if (p > mid)
		{
			end = p - 1;
			p = partion(arr, start, end);
		}
		else if (p < mid)
		{
			start = p + 1;
			p = partion(arr, start, end);
		}
	}
	return arr[p];
}
int MoreThanHalfNumber2(std::vector<int> &arr)
{
	if (arr.size() < 1) return 0;
	int len = arr.size();
	int num = arr[0];//保存数组的值
	int times = 1;//保存出现的次数
	for (int i = 1; i < len; ++i)
	{
		if (times == 0)
		{
			num = arr[i];
			times = 1;
		}
		else if (arr[i] == num)
			times++;
		else
			times--;
	}
	return num;
}
void Test()
{
	std::vector<int> arr{1,2,3,2,2,2,5,4,2};
	std::vector<int> arr1{ 1,2,3,2,3,3,5,3,3 };
	int ret = MoreThanHalfNumber(arr);
	 ret = MoreThanHalfNumber(arr1);
	 ret = MoreThanHalfNumber2(arr);
	 ret = MoreThanHalfNumber2(arr1);
}
int main()
{
	Test();
	getchar();
}


