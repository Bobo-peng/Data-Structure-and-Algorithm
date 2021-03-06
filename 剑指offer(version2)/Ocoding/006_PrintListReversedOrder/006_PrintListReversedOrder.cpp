// 006_PrintListReversedOrder.cpp: 定义控制台应用程序的入口点。
//==================================================================
// author:pb
// date:2019-06-06
//==================================================================

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<stack>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
//创建链表
ListNode* CreatList(std::vector<int> &arr)
{
	int lsize = arr.size();
	if (lsize <= 0)
		return nullptr;
	ListNode* head = new ListNode(arr[0]);
	ListNode* cur = head;
	for(int i = 1; i < lsize; ++i)
	{
		ListNode* tmp = new ListNode(arr[i]);
		cur->next = tmp;
		cur = cur->next;
	}
	return head;
}
//释放链表
void DestroyList(ListNode* head)
{
	ListNode* cur = head;
	while (nullptr != cur)
	{
		cur = head;
		head = head->next;
		delete cur;
		cur = nullptr;
	}
}
ListNode* ReverseList(ListNode* head)
{
	ListNode* pre = nullptr;
	ListNode* cur = head;
	while (nullptr != cur)
	{
		ListNode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}
void PrintReversedOrder(ListNode* head)
{
	std::stack<int> slist;
	while (nullptr != head)
	{
		slist.push(head->val);
		head = head->next;
	}
	while (!slist.empty())
	{
		std::cout << slist.top() << " ";
		slist.pop();
	}
	std::cout << "\n";
}
void PrintReversedOrderByRecurisive(ListNode* head)
{
	if (nullptr == head)
		return;
	PrintReversedOrderByRecurisive(head->next);
	std::cout << head->val << " ";
}
void PrintList(ListNode* head)
{
	while (nullptr != head)
	{
		std::cout << head->val<< " ";
		head = head->next;
	}
	std::cout << "\n";
}
int main()
{
	std::vector<int> arr1{ 1,2,3,4,5 };
	ListNode* head = CreatList(arr1);
	PrintReversedOrderByRecurisive(head);
	PrintReversedOrder(head);
	ListNode* rhead = ReverseList(head);
	PrintReversedOrder(rhead);
	PrintList(rhead);
	DestroyList(rhead);
	getchar();
    return 0;
}

