// 031_StackOrder.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<stack>
bool StackOrder(std::vector<int> &arr1, std::vector<int> &arr2)
{
	std::stack<int> s;
	int len1 = arr1.size();
	int len2 = arr2.size();
	int j  = 0;
	int i = 0;
	for (; i < len2; ++i)
	{
		while (s.empty() || s.top() != arr2[i])
		{
			if (j == len1)//所有的元素都压入栈
				break;
			s.push(arr1[j++]);
		}
		if (s.top() != arr2[i])
			break;
		s.pop();
	}
	if (s.empty() && i == len2)
		return true;
	else
		return false;
}
void Test()
{
	std::vector<int> arr1{ 1,2,3,4,5 };
	std::vector<int> arr2{ 4,5,3,2,1 };
	std::vector<int> arr3{ 4,3,5,1,2 };
	bool ret = StackOrder(arr1,arr2);
	ret = StackOrder(arr1,arr3);
}
void Test1()
{
	std::vector<int> arr1{ 1,2,3,4,5 };
	std::vector<int> arr2{ 3, 5, 4, 2, 1 };//true
	std::vector<int> arr3{ 3, 5, 4, 1, 2 };//false
	bool ret = StackOrder(arr1, arr2);
	ret = StackOrder(arr1, arr3);
}
void Test2()
{
	std::vector<int> arr1{ 1};
	std::vector<int> arr2{ 1};
	std::vector<int> arr3{ 2};
	bool ret = StackOrder(arr1, arr2);
	ret = StackOrder(arr1, arr3);
}
int main()
{
   Test(); 
   Test1();
   Test2();
}
