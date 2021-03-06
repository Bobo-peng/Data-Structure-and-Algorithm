// 009_QueueWithTwoStack.cpp: 定义控制台应用程序的入口点。
//==================================================================
// author:pb
// date:2019-06-06
//==================================================================
#include "stdafx.h"
#include<stack>
#include<queue>
#include<assert.h>

template<typename T>
class squeue {
public:
	squeue() {}
	~squeue() {}
	void spush(T &val)
	{
		s1.push(val);
	}

	T sfront()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		assert(!s2.empty());
		return s2.top();
	}
	void spop()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		assert(!s2.empty());
		return s2.pop();
	}
private:
	std::stack<T> s1;
	std::stack<T> s2;
};
void Test1()
{
	squeue<int> sq;
	//int ret = sq.sfront();
	int a = 1;
	int b = 2;
	int c = 3;
	sq.spush(a);
	sq.spush(b);
	sq.spush(c);
	//sq.spop();
	int ret = sq.sfront();
}
void Test2()
{
	squeue<char> sq;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	sq.spush(a);
	sq.spush(b);
	sq.spush(c);
	sq.spop();
	char ret = sq.sfront();
}
int main()
{
	Test1();
	Test2();
    return 0;
}

