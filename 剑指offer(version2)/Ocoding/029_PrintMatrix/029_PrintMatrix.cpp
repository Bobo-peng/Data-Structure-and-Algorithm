// 029_PrintMatrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
void PrintMatrix(std::vector<std::vector<int>> &arr)
{
	if (arr.size() == 0 && arr[0].size() == 0)
		return;
	int rows = arr.size();//行
	int columns = arr[0].size();//列
	
	int start = 0;//(start, start)为左上角开始坐标
	while (2 * start < columns && 2 * start < rows)
	{
		int endX = columns - 1 - start;
		int endY = rows - 1 - start;
		for (int i = start; i <= endX; ++i)
		{
			std::cout << arr[start][i]<<" ";
		}
		// 从上到下打印一列
		if (start < endY)
		{
			for (int i = start + 1; i <= endY; ++i)
			{
				std::cout << arr[i][endX] << " ";
			}
		}

		// 从右到左打印一行
		if (start < endX && start < endY)
		{
			for (int i = endX - 1; i >= start; --i)
			{
				std::cout << arr[endY][i] << " ";
			}
		}

		// 从下到上打印一行
		if (start < endX && start < endY - 1)
		{
			for (int i = endY - 1; i >= start + 1; --i)
			{
				std::cout << arr[i][start] << " ";
			}
		}
		start++;
	}
}
void Test()
{
	std::vector<std::vector<int>> arr{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	PrintMatrix(arr);
}
int main()
{
	Test();
	getchar();
}

