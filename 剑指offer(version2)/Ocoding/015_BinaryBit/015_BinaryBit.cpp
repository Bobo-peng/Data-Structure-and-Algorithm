// 015_BinaryBit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-06
//==================================================================

#include "pch.h"
#include <iostream>
int BinaryBit(int n)
{
	int cnt = 0;
	unsigned int tmp = 1;
	while (tmp)
	{
		if (n & tmp)
			++cnt;
		tmp <<= 1;
	}
	return cnt;
}
void Test()
{
	int ret = BinaryBit(1);
	ret = BinaryBit(3);
	ret = BinaryBit(0xFF88);
	ret = BinaryBit(0x9999);
}
int main()
{
	Test();
}
