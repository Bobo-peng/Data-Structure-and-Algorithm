// 063_MaxProfit.cpp: 定义控制台应用程序的入口点。
//==================================================================
// author:pb
// date:2019-06-019
//==================================================================

#include "stdafx.h"
#include<vector>
#include<algorithm>
int MaxProfit(std::vector<int> &prices)
{
	int ret = 0, buy = INT_MAX;
	for (int i = 0; i < prices.size(); ++i)
	{
		buy = std::min(buy, prices[i]);
		ret = std::max(ret, prices[i] - buy);
	}
	return ret;
}
void Test()
{
	std::vector<int> arr{ 9,11,8,5,7,12,16,14 };
	int ret = MaxProfit(arr);
}
int main()
{
	Test();
	return 0;
}


int main()
{
    return 0;
}

