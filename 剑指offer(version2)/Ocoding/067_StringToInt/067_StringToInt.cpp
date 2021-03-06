// 067_StringToInt.cpp: 定义控制台应用程序的入口点。
//==================================================================
// author:pb
// date:2019-06-019
//==================================================================

#include "stdafx.h"
#include<string>

int StringToInt(const char* str)
{
		int tmp = 0;
		const char* ptr = str;
		if (*str == '+' || *str == '-')
		{
			str++;
		}
		while (*str != 0)
		{
			if (*str < '0' || *str > '9')
			{
				break;
			}
			tmp = tmp * 10 + (*str - '0');
			str++;
		}
		if (*ptr == '-')
		{
			tmp = -tmp;
		}
		return tmp;
}

long long StrToIntCore(const char* str, bool minus);

enum Status { kValid = 0, kInvalid };
int g_nStatus = kValid;

int StrToInt(const char* str)
{
	g_nStatus = kInvalid;
	long long num = 0;

	if (str != nullptr && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;
		}

		if (*str != '\0')
			num = StrToIntCore(str, minus);
	}

	return (int)num;
}

long long StrToIntCore(const char* digit, bool minus)
{
	long long num = 0;

	while (*digit != '\0')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');

			if ((!minus && num > 0x7FFFFFFF)
				|| (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}

			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if (*digit == '\0')
		g_nStatus = kValid;

	return num;
}
bool isNumChar(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}
int myAtoi(std::string str) {
	bool neg = false;
	int res = 0;
	int n = str.size();
	if (n == 0)
		return 0;
	int i = 0;
	while (i < n && str[i] == ' ')
		++i;
	if (str[i] == '+' || str[i] == '-')
		neg = (str[i++] == '+') ? false : true;
	while (i < n && isNumChar(str[i]))
	{

		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) {
			return neg ? INT_MIN : INT_MAX;
		}
		res = res * 10 + str[i++] - '0';

	}
	res = neg ? -res : res;
	return res;
}
void Test()
{
	const char* str = "----12kj34as";
	int ret = StringToInt(str);
	ret = StrToInt(str);
	std::string str1 = "12kj34as";
    ret = myAtoi(str);
	ret = atoi(str);
}
int main()
{
	Test();
    return 0;
}

