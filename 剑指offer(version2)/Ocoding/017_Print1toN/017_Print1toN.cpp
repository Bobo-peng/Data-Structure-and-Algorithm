// 017_Print1toN.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-06
//==================================================================

#include "pch.h"
#include <iostream>
void Print1toN(int n)
{
	//std::unique_ptr<char> num(new char[n]());
	int *num = new int[n]();
	int len = 0;
	bool overflow = false;
	while (!overflow)
	{
		int carry = 0;
		for (int i = 0; i < n; ++i)//把各位放在num[0],打印的时候反着打印
		{
			int tmp = num[i] + carry;
			if (i == 0)	tmp++;//只在个位加1
			if (tmp >= 10)//有进位
			{
				tmp %= 10;
				carry = 1;
				num[i] = tmp;
				
				if (i == n - 1) overflow = true;	
			}
			else
			{
				num[i] = tmp;
				len = len > i ? len : i;//求总共有多少位数
				break;
			}
		}
		if (overflow) break;//最高位有进位，说明结束了，直接跳出大循环
		for (int i = len; i >= 0; --i)
		{
			std::cout << num[i];
		}
		std::cout << std::endl;
	}
	delete[] num;
}
int main()
{
	Print1toN(1);
	Print1toN(4);
	getchar();
}
