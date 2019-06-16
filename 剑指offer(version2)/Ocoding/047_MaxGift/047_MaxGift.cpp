// 047_MaxGift.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-016
//==================================================================

#include "pch.h"
#include <iostream>
#include<vector>
//#include<math.h>
#include<algorithm>
int MaxGift(std::vector<std::vector<int>> &grid)
{
	int m = grid.size(), n;
	if (m == 0)
		return 0;
	else
		n = grid[0].size();
	std::vector<std::vector<int>> dp(m, std::vector<int>(n));//m行，n列
	//初值
	dp[0][0] = grid[0][0];
	for (int i = 1; i < m; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];
	for (int i = 1; i < n; ++i) dp[0][i] = grid[0][i] + dp[0][i - 1];
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			dp[i][j] = grid[i][j] + std::max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	return dp[m - 1][n - 1];
}
void Test()
{
	std::vector<std::vector<int>> arr{ {1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5} };
	int ret = MaxGift(arr);
}
int main()
{
	Test();
}


