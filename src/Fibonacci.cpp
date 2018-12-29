#include"stdafx.h"
#include<iostream>
#include<vector>
//重复计算过多
long Fibonacci(unsigned n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//时间复杂度O(n)
long Fibonacci1(unsigned n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	long fn_2 = 0;//f(n-2)
	long fn_1 = 1;//f(n-1)
	long fn = 0;//f(n)
	for (int i = 2; i <= n; i++)
	{
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
		
	}
	return fn;
}
std::vector<int> memo;
int num = 0;

// 记忆化搜索
int fib(int n) {

	num++;

	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	if (memo[n] == -1)
		memo[n] = fib(n - 1) + fib(n - 2);

	return memo[n];
}
// 动态规划
int fib1(int n) {

	std::vector<int> memo(n + 1, -1);

	memo[0] = 0;
	memo[1] = 1;
	for (int i = 2; i <= n; i++)
		memo[i] = memo[i - 1] + memo[i - 2];

	return memo[n];
}
int main()
{
	long num = Fibonacci(10);
	long num1 = Fibonacci1(10);
	memo = std::vector<int>(10+1, -1);
	int num2 = fib(10);
	int num3 = fib(10);
	std::cout << num << std::endl;
	getchar();
	return 0;
}