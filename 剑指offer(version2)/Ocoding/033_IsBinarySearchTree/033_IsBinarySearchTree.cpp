// 033_IsBinarySearchTree.cpp: 定义控制台应用程序的入口点。
//==================================================================
// author:pb
// date:2019-06-08
//==================================================================

#include "stdafx.h"
#include<vector>
bool _isBinarySeachTree(std::vector<int> &arr, int start, int end)
{
	if (start >= end)
		return true;
	int root = arr[end];
	int i;
	for (i = start; i < end; ++i)
	{
		if (arr[i] > root)
			break;
	}
	int j = i;
	for (; j < end; ++j)
	{
		if (arr[j] < root)
			return false;
	}
	bool left = true;
	bool right = true;
	if (i > start)
		left = _isBinarySeachTree(arr, start, i - 1);
	if (i < end)
		right = _isBinarySeachTree(arr, i, end - 1);
	return   left && right;
}
bool isBinarySeachTree(std::vector<int> &arr)
{
	int len = arr.size();
	if (len <= 0) return false;
	return _isBinarySeachTree(arr, 0, len-1);
}
void Test()
{
	std::vector<int> arr{ 4, 8, 6, 12, 16, 14, 10 };//true
	std::vector<int> arr1{ 7, 4, 6, 5 };//false
	std::vector<int> arr2{ 4, 6, 7, 5 };//true
	std::vector<int> arr3{ 1, 2, 3, 4, 5 };//true
	std::vector<int> arr4{ 5, 4, 3, 2, 1 };//true
	std::vector<int> arr5{ 5 };//true
	std::vector<int> arr6{ 4, 6, 12, 8, 16, 14, 10 };//false
	bool ret = isBinarySeachTree(arr);
	ret = isBinarySeachTree(arr1);
	ret = isBinarySeachTree(arr2);
	ret = isBinarySeachTree(arr3);
	ret = isBinarySeachTree(arr4);
	ret = isBinarySeachTree(arr5);
	ret = isBinarySeachTree(arr6);
}
int main()
{
	Test();
    return 0;
}

