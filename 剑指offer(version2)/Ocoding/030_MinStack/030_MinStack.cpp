// 030_MinStack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stack>
template<typename T> class minstack {
public:
	minstack() {}
	~minstack() {}
	void push(const T &val);
	void pop();
	const T& top()const;
	const T& min()const;
	bool empty();
	size_t size();//unsigned int
private:
	std::stack<T> m_data;
	std::stack<T> m_min;//存放最小值
};
template<typename T> void minstack<T>::push(const T &val)
{
	m_data.push(val);
	if (m_min.empty() || val <= m_min.top())
		m_min.push(val);
	else
		m_min.push(m_min.top());
}
template<typename T> void minstack<T>::pop()
{
	m_data.pop();
	m_min.pop();
}
template<typename T> const T& minstack<T>::top()const
{
	return m_data.top();
}
template<typename T> const T& minstack<T>::min()const
{
	return m_min.top();
}
template<typename T> bool minstack<T>::empty()
{
	return m_data.empty();
}
template<typename T> size_t minstack<T>::size()
{
	return m_data.size();
}
void Test()
{
	minstack<int> s;
	s.push(3);
	int ret = s.min();
	s.push(4);
	ret = s.min();
	s.push(2);
	ret = s.min();
	s.push(3);
	ret = s.min();
	s.pop();
	ret = s.min();
	s.pop();
	ret = s.min();
	s.pop();

}
int main()
{
	Test();
}

