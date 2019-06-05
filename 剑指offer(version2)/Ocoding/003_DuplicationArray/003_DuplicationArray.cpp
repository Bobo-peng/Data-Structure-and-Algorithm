// 003_DuplicationArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-05
//==================================================================
#include "pch.h"
#include <iostream>
#include<vector>
bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > length-1)
			return false;
	}
	int *tmp_arr = new int[length]();//1.new,每个元素都初始化为0
	for (int i = 0; i < length; ++i)
	{
		tmp_arr[numbers[i]]++;
	}

	if (tmp_arr[*duplication] > 1)
	{
		delete[] tmp_arr;
		return true;
	}	
	else
	{
		delete[] tmp_arr;
		return false;
	}

}
bool duplicate1(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}
	std::vector<int> tmp_arr(length);//2.vector,每个元素都初始化为0
	for (int i = 0; i < length; ++i)
	{
		tmp_arr[numbers[i]]++;
	}

	if (tmp_arr[*duplication] > 1)
		return true;
	else
		return false;

}
bool duplicate2(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}
	std::unique_ptr<int[]>  tmp_arr(new int[length]());//3.智能指针
	for (int i = 0; i < length; ++i)
	{
		tmp_arr[numbers[i]]++;
	}

	if (tmp_arr[*duplication] > 1)
		return true;
	else
		return false;
}
int main()
{
	int arr[7] = { 2,4,6,4,5,0,1 };
	int d = 4;
	bool ret = duplicate2(arr, 7, &d);
	std::cout << "ret:" << ret << std::endl;
}


