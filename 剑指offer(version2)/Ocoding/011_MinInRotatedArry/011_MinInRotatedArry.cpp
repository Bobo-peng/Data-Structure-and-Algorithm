// 011_MinInRotatedArry.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-06
//==================================================================

#include "pch.h"
#include <iostream>
#include<vector>
int MinNumInRotateArry(std::vector<int> &arr)
{
	int start = 0;
	int end = arr.size()-1;
	int mid = 0;
	while (arr[start] >= arr[end])
	{
		if (end - start == 1)
		{
			mid = end;
			break;
		}
		mid = (end - start) / 2 + start;
		if (arr[mid] >= arr[start])
			start = mid;
		else if (arr[mid] <= arr[end])
			end = mid;
	}
	return arr[mid];
}
void Test()
{
	std::vector<int> arr{3,4,5,1,2};
	std::vector<int> arr1{1,2,3,4,5};
	std::vector<int> arr2{ 5,4,3,2,1 };
	int ret =MinNumInRotateArry(arr);
	 ret = MinNumInRotateArry(arr1);
	 ret = MinNumInRotateArry(arr2);
}
int main()
{
	Test();
	return 0;
}

