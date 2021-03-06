// 010_Fibonacci.cpp: 定义控制台应用程序的入口点。
//==================================================================
// author:pb
// date:2019-06-06
//==================================================================

#include "stdafx.h"
#include<iostream>
//递归
int Fibonacci(int n)
{
	if (n <= 1)
		return n;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//非递归
int Fibonacci1(int n)
{
	if (n <= 1)
		return n;
	int last_one = 1;
	int last_two = 0;
	int ret = 0;
	for (int i = 2; i <= n; ++i)
	{
		ret = last_one + last_two;
		last_two = last_one;
		last_one = ret;	 
	}
	return ret;
}
int main()
{
	std::cout<< "Fibonacci(" << 10 << ")=" << Fibonacci(10) << std::endl;
	std::cout << "Fibonacci1(" << 10 << ")=" << Fibonacci1(10) << std::endl;
	std::cout << "Fibonacci1(" << 100 << ")=" << Fibonacci1(40) << std::endl;
	std::cout << "Fibonacci(" << 100 << ")=" << Fibonacci(40) << std::endl;
	
	getchar();
    return 0;
}

