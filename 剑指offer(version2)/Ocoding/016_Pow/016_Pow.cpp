// 016_Pow.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-06
//==================================================================

#include "pch.h"
#include <iostream>
//浮点数的比较
bool equal(double x, double y)
{
	if ((x - y > -0.0000001) && (x - y < 0.0000001))
		return true;
	else
		return false;
}
double _Opow(double n, unsigned int e)
{
	if (e == 0)
		return 1;
	if (e == 1)
		return n;
	int ret = _Opow(n, e >> 1);//除以2
	ret *= ret;
	if (e & 1 == 1)//判断奇偶
		ret *= n;
	return ret;
}
double Opow(double n, int e)
{
	if (equal(n, 0.0) && e < 0)//排除分母为0的情况
		return 0.0;
	int _e = e > 0 ? e : -e;
	double ret = _Opow(n, _e);
	if (e < 0)
		ret = 1.0 / ret;
	return ret;
}
int main()
{
	double a =pow(2.0,-1);
	a = pow(3, -2);
	double b = Opow(2.0,-1);
	double c = Opow(2.0, 0);
	double d = Opow(0, 0);
	double e = Opow(3, -2);
    
}

